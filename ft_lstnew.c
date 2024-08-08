/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:05:41 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:25:39 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Creates a new node for a linked list.
 * 
 * @param content A pointer to the content to be stored in the new node.
 * @return A pointer to the newly created node, or `NULL` if memory allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc (sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = -1;
	node->next = NULL;
	return (node);
}
