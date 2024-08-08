/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:52:12 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:21:15 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Searches for the optimal position to insert a number into a sorted stack.
 * 
 * @param stack A pointer to the top of the stack.
 * @param num The index of the number to be inserted.
 * @return The number of moves to reach the insertion point from the top or bottom.
 */
long	search_slot(t_list **stack, long num)
{
	long	i;
	t_list	*ptr;

	i = 0;
	ptr = *stack;
	while (ptr && num < ptr->index)
	{
		i++;
		if (ptr->next && ptr->index > ptr->next->index)
		{
			ptr = ptr->next;
			break ;
		}
		ptr = ptr->next;
	}
	while (ptr && num > ptr->index)
	{
		i++;
		if (ptr->next && ptr->index > ptr->next->index)
			break ;
		ptr = ptr->next;
	}
	if (i > ft_lstsize(*stack) / 2)
		i = i - ft_lstsize(*stack);
	return (i);
}

/**
 * Executes the cheapest combination of operations to shuffle elements between two stacks.
 * 
 * @param dest A pointer to the destination stack.
 * @param src A pointer to the source stack.
 * @param move_dst The number of moves to insert the element into the destination stack.
 * @param move_src The number of moves to bring the next candidate to the top of the source stack.
 */
void	exec_cheapest_shuffle(t_list **dest, t_list **src, \
								long move_dst, long move_src)
{
	while (move_dst < 0 && move_src < 0)
	{
		exec_ops("rrr", dest, src);
		move_dst++;
		move_src++;
	}
	while (move_dst > 0 && move_src > 0)
	{
		exec_ops("rr", dest, src);
		move_dst--;
		move_src--;
	}
	while (move_dst < 0 && move_dst++)
		exec_ops("rra", dest, src);
	while (move_dst > 0 && move_dst--)
		exec_ops("ra", dest, src);
	while (move_src < 0 && move_src++)
		exec_ops("rrb", dest, src);
	while (move_src > 0 && move_src--)
		exec_ops("rb", dest, src);
}

/**
 * Determines and executes the cheapest operation to shuffle one element from the source stack to the destination.
 * 
 * @param dest A pointer to the destination stack.
 * @param src A pointer to the source stack.
 */
void	cheapest_shuffle(t_list **dest, t_list **src)
{
	long	move_dst;
	long	move_src;
	long	pos;
	long	best_move;
	t_list	*ptr;

	move_src = 0;
	pos = 0;
	ptr = (*src);
	move_dst = search_slot(dest, ptr->index);
	best_move = ft_abs(move_dst);
	while (best_move && ptr)
	{
		if (ft_abs(search_slot(dest, ptr->index)) + ft_abs(pos) < best_move)
		{
			move_dst = search_slot(dest, ptr->index);
			move_src = pos;
			best_move = ft_abs(search_slot(dest, ptr->index)) + ft_abs(pos);
		}
		if (++pos > ft_lstsize(*src) / 2)
			pos = pos - ft_lstsize(*src);
		ptr = ptr->next;
	}
	exec_cheapest_shuffle(dest, src, move_dst, move_src);
}
