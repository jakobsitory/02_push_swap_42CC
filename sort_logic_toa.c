/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic_toa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:57:01 by jschott           #+#    #+#             */
/*   Updated: 2023/08/21 16:36:25 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheapest_move_a(t_list **stack, unsigned top, unsigned bot, int res)
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
			exec_ops("rrb", NULL, stack);
		while (move2top > 0 && move2top--)
			exec_ops("rb", NULL, stack);
	}
	else if (ft_abs(move2bot) < ft_abs(move2top))
	{
		while (move2bot < 0 && move2bot++)
			exec_ops("rrb", NULL, stack);
		while (move2bot > 0 && move2bot--)
			exec_ops("rb", NULL, stack);
	}
	return (1);
}

void	sort2a(t_list **a, t_list **b, long int size, int res)
{
	unsigned int	top_buck;
	unsigned int	bot_buck;

	if (!(*a))
		exec_ops("pa", a, b);
	top_buck = (*a)->index / res;
	bot_buck = (ft_lstlast(*a)->index) / res + 1;
	while ((ft_lstsize(*a) <= size - res))
	{
		if (top_buck == UINT_MAX)
			top_buck = (size - 1) / res;
		if (bot_buck == (size - 1) / res + 1)
			bot_buck = 0;
		if ((*b) && ((*b)->index / res == top_buck \
			|| (*b)->index / res == bot_buck))
			exec_ops("pa", a, b);
		if (res <= 10 && (*a)->index / res == bot_buck)
			exec_ops("ra", a, b);
		cheapest_move_a(b, top_buck, bot_buck, res);
		if (!(calc_move(b, top_buck, res)))
			--top_buck;
		if (!(calc_move(b, bot_buck, res)))
			++bot_buck;
	}
}
