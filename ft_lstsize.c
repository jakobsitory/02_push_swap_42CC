/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:39:09 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:25:24 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Counts the number of elements in a linked list.
 * 
 * @param lst A pointer to the first node of the linked list.
 * @return The total number of nodes in the list.
 */
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	count++;
	if (lst->next != NULL)
		count = count + ft_lstsize(lst->next);
	return (count);
}
