/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:15:37 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:28:06 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Adds a new element to the end of a linked list.
 * 
 * @param lst A double pointer to the first node of the linked list. This allows the function to modify the head of the
 * list if it is initially empty.
 * @param new A pointer to the new element to be added to the list. This new element should have its `next` pointer set
 * to `NULL` before being passed to this function.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pos;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	pos = ft_lstlast(*lst);
	pos->next = new;
}
