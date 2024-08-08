/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:23:28 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:27:39 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Clears and frees an entire linked list.
 * 
 * @param lst A double pointer to the first node of the linked list. This allows the function to modify the caller's
 * pointer to the list, effectively setting it to `NULL` after clearing the list.
 * @param del A function pointer to a function used to free the content of each node. This ensures that all dynamic
 * memory associated with the node's content is properly released.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = tmp;
		}
	}
}
