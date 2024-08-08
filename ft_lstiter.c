/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:30:47 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:26:31 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Iterates over a linked list and applies a function to the content of each node.
 * 
 * @param lst A pointer to the first node of the linked list to be iterated over.
 * @param f A function pointer to the operation to apply to each node's content.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*pos;

	pos = lst;
	while (pos)
	{
		f(pos->content);
		pos = pos->next;
	}
}
