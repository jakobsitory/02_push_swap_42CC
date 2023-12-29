/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:07:13 by jschott           #+#    #+#             */
/*   Updated: 2023/08/01 16:50:14 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
