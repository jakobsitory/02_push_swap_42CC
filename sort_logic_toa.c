/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic_toa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:57:01 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:18:42 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Finds and executes the cheapest move to sort a number from stack `b` to stack `a`.
 * 
 * The function `cheapest_move_a` determines the cheapest (minimum number of moves) way to sort either the top or
 * bottom number of stack `b` into its correct position in stack `a`, based on a given resolution (`res`). It
 * calculates the number of moves required to bring the top or bottom number to the top of stack `b` and then
 * executes the necessary operations (`rb` for rotate up, `rrb` for rotate down) to move the number to stack `a`.
 * 
 * @param stack A pointer to the top of stack `b`.
 * @param top The index divided by `res` of the top number in stack `b`.
 * @param bot The index divided by `res` of the bottom number in stack `b`.
 * @param res The resolution used for sorting.
 * @return 1 if a move is executed, 0 otherwise.
 */
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

/**
 * Sorts elements from stack `b` to stack `a` based on bucketing strategy.
 * 
 * The function `sort2a` implements a bucketing strategy to sort elements from stack `b` back to stack `a`. It
 * divides the elements into buckets based on a resolution (`res`) and moves elements to stack `a` while maintaining
 * the order. It uses `exec_ops` to execute operations like `pa` (push to stack `a`) and `ra` (rotate stack `a` up).
 * It also calls `cheapest_move_a` to find and execute the cheapest move for sorting numbers from stack `b` to `a`.
 * 
 * @param a A pointer to the top of stack `a`.
 * @param b A pointer to the top of stack `b`.
 * @param size The total number of elements to sort.
 * @param res The resolution used for bucketing.
 */
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
