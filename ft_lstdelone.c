/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:19:24 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:26:44 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Deletes a single node from a linked list.
 * 
 * @param lst A pointer to the node to be deleted.
 * @param del A function pointer to a function used to free the content of the node.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst);
}
