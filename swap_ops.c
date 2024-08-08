/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:52:05 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:16:38 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Executes operations on two stacks based on the given operation code.
 * 
 * @param op A string representing the operation code.
 * @param a A pointer to the first stack.
 * @param b A pointer to the second stack.
 */
void	exec_ops(char *op, t_list **a, t_list **b)
{
	if (!ft_memcmp(op, "sa", 3) || !ft_memcmp(op, "ss", 3))
		swap (a);
	if (!ft_memcmp(op, "sb", 3) || !ft_memcmp(op, "ss", 3))
		swap (b);
	if (!ft_memcmp(op, "pa", 3))
		push (a, b);
	if (!ft_memcmp(op, "pb", 3))
		push (b, a);
	if (!ft_memcmp(op, "ra", 3) || !ft_memcmp(op, "rr", 3))
		rotate (a);
	if (!ft_memcmp(op, "rb", 3) || !ft_memcmp(op, "rr", 3))
		rotate (b);
	if (!ft_memcmp(op, "rra", 3) || !ft_memcmp(op, "rrr", 3))
		rrotate (a);
	if (!ft_memcmp(op, "rrb", 3) || !ft_memcmp(op, "rrr", 3))
		rrotate (b);
	write (1, op, ft_strlen(op));
	write (1, "\n", 1);
}

/**
 * Swaps the top two elements of a stack.
 * 
 * @param stack A pointer to the stack on which to perform the swap operation.
 */
void	swap(t_list **stack)
{
	t_list	*new_1;
	t_list	*new_2;

	if (!(*stack) || !(*stack)->next)
		return ;
	new_1 = (*stack)->next;
	new_2 = (*stack);
	new_2->next = new_1->next;
	new_1->next = new_2;
	(*stack) = new_1;
}

/**
 * Pushes the top element from one stack to another.
 * 
 * @param dest A pointer to the destination stack.
 * @param src A pointer to the source stack.
 */
void	push(t_list **dest, t_list **src)
{
	t_list	*tmp;

	tmp = NULL;
	if (!(*src))
		return ;
	else if (!(*dest))
	{
		(*dest) = ft_lstnew((*src)->content);
		(*dest)->index = (*src)->index;
		tmp = (*src)->next;
		(*src)->next = NULL;
		ft_lstdelone((*src), free);
		(*src) = tmp;
		return ;
	}
	tmp = (*src)->next;
	(*src)->next = NULL;
	ft_lstadd_back(src, (*dest));
	(*dest) = (*src);
	(*src) = tmp;
}

/**
 * Rotates all elements of a stack up by one position.
 * 
 * @param stack A pointer to the stack on which to perform the rotate operation.
 */
void	rotate(t_list **stack)
{
	t_list	*new_1;
	t_list	*new_2;

	if (!(*stack) || !(*stack)->next)
		return ;
	new_1 = (*stack)->next;
	new_2 = (*stack);
	new_2->next = NULL;
	ft_lstadd_back(&new_1, new_2);
	(*stack) = new_1;
}

/**
 * Rotates all elements of a stack down by one position.
 * 
 * @param stack A pointer to the stack on which to perform the reverse rotate operation.
 */
void	rrotate(t_list **stack)
{
	t_list	*new_1;
	t_list	*temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	new_1 = ft_lstlast(*stack);
	temp = (*stack);
	while (temp->next->next)
		temp = temp->next;
	temp->next = NULL;
	ft_lstadd_back(&new_1, (*stack));
	(*stack) = new_1;
}
