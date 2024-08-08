/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:07:13 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:26:04 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Creates a new linked list by applying a function to each element of an existing list.
 * 
 * @param lst A pointer to the first node of the linked list to be mapped.
 * @param f A function pointer to the operation to apply to each element's content.
 * @param del A function pointer for freeing an element's content in case of an error.
 * @return A pointer to the first node of the newly created linked list, or `NULL` if an error occurs.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newlstel;

	if (!f || !lst || !del)
		return (0);
	newlstel = ft_lstnew(f(lst->content));
	if (!newlstel)
	{
		del(newlstel->content);
		return (0);
	}
	newlst = newlstel;
	lst = lst->next;
	while (lst)
	{
		newlstel = ft_lstnew(f(lst->content));
		if (!newlstel)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, newlstel);
		lst = lst->next;
	}
	return (newlst);
}
