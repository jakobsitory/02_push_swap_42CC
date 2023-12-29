/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:37:53 by jschott           #+#    #+#             */
/*   Updated: 2023/08/22 09:51:43 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a)
{
	long	b;
	long	m;
	long	e;

	b = (*a)->index;
	m = (*a)->next->index;
	e = (ft_lstlast(*a))->index;
	if (b > m && b < e && m < e)
		exec_ops("sa", a, NULL);
	else if (b > m && b > e && m > e)
	{
		exec_ops("sa", a, NULL);
		exec_ops("rra", a, NULL);
	}
	else if (b > m && b > e && m < e)
		exec_ops("ra", a, NULL);
	else if (b < m && b < e && m > e)
	{
		exec_ops("sa", a, NULL);
		exec_ops("ra", a, NULL);
	}
	else if (b < m && b > e && m > e)
		exec_ops("rra", a, NULL);
}

long int	calc_move(t_list **stack, unsigned int num, int res)
{
	long int	i;
	long int	first;
	long int	last;
	t_list		*ptr;

	i = 0;
	first = 0;
	last = 0;
	ptr = (*stack);
	while (ptr)
	{
		if (ptr->index / res == num)
		{
			last = i;
			if (!first)
				first = i + 1;
		}
		i++;
		ptr = ptr->next;
	}
	if (i - last < first - 1)
		return (last - i);
	else if (first > 0)
		return (first);
	return (0);
}

int	cheapest_move(t_list **stack, unsigned top, unsigned bot, int res)
{
	long int	move2top;
	long int	move2bot;

	move2top = calc_move(stack, top, res);
	move2bot = calc_move(stack, bot, res);
	if (!move2top || !move2bot)
		return (0);
	else if (ft_abs(move2top) <= ft_abs(move2bot))
	{
		while (move2top < 0 && move2top++)
			exec_ops("rra", stack, NULL);
		while (move2top > 0 && move2top--)
			exec_ops("ra", stack, NULL);
	}
	else if (ft_abs(move2bot) < ft_abs(move2top))
	{
		while (move2bot < 0 && move2bot++)
			exec_ops("rra", stack, NULL);
		while (move2bot > 0 && move2bot--)
			exec_ops("ra", stack, NULL);
	}
	return (1);
}

void	sort2b(t_list **a, t_list **b, long int size, int res)
{
	unsigned int	top_buck;
	unsigned int	bot_buck;

	if (!(*b))
		exec_ops("pb", a, b);
	top_buck = (*b)->index / res;
	bot_buck = top_buck - 1;
	while ((ft_lstsize(*b) <= size - res))
	{
		if (top_buck == (size - 1) / res + 1)
			top_buck = 0;
		if (bot_buck == UINT_MAX)
			bot_buck = (unsigned)((size - 1) / res + 1);
		if ((*a) && ((*a)->index / res == top_buck \
			|| (*a)->index / res == bot_buck))
			exec_ops("pb", a, b);
		if ((*b)->index / res == bot_buck)
			exec_ops("rb", a, b);
		cheapest_move(a, top_buck, bot_buck, res);
		if (!(calc_move(a, top_buck, res)))
			++top_buck;
		if (!(calc_move(a, bot_buck, res)))
			--bot_buck; 
	}
}

void	sort_five(t_list **a, t_list **b)
{
	long int		size;
	int				res;

	size = ft_lstsize(*a);
	res = size / 10;
	if (size > 100)
		sort2b(a, b, size, res);
	while (ft_lstsize(*a) > 3)
		exec_ops("pb", a, b);
	sort_three(a);
	while (*b)
	{
		cheapest_shuffle(a, b);
		exec_ops("pa", a, b);
	}
	if ((*a)->index != 0)
	{
		cheapest_move(a, 0, size - 1, 1);
		if ((*a)->index != 0)
			exec_ops("rra", a, b);
	}
}
