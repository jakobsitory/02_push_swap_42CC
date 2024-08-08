/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:41:35 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:20:27 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
void	print_stack(t_list *list, int res)
{
	long int	num;

	if (!list)
		return ;
	else if (list->next)
	{
		while (list->next)
		{
			num = (long int) list->index;
			printf ("%*li | ", 5, num);
			num = (long int) list->index;
			printf ("%*li | ", 3, num / res);
			num = (long int) list->content;
			printf ("%li\n", num);
			list = list->next;
		}
	}
	num = (long int) list->index;
	printf ("%*li | ", 5, num);
	num = (long int) list->index;
	printf ("%*li | ", 3, num / res);
	num = (long int) list->content;
	printf ("%li\n", num);
}
 */

/**
 * Checks if a stack is sorted in ascending order based on index.
 * 
 * @param stack A pointer to the top of the stack.
 * @return 1 if the stack is sorted in ascending order, 0 otherwise.
 */
int	is_ascending(t_list *stack)
{
	t_list	*nxt;
	int		one;
	int		two;

	nxt = stack->next;
	while (nxt)
	{
		one = stack->index;
		two = nxt->index;
		if (one > two)
			return (0);
		stack = nxt;
		nxt = nxt->next;
	}
	return (1);
}

/**
 * The main function of a program that sorts a stack of numbers.
 * 
 * This function serves as the entry point for a program that sorts a stack of numbers. It takes command-line
 * arguments (`argc`, `argv`), where `argv` contains the numbers to be sorted. It initializes two stacks, `a` and
 * `b`, and attempts to read the input numbers into stack `a` using the `read_input` function. If the input is valid
 * and stack `a` is not already sorted in ascending order, it calls `sort_five` to sort the stack. Finally, it
 * cleans up by freeing the memory allocated for both stacks.
 * 
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return 1 if the input is invalid or less than two arguments are provided, 0 otherwise.
 */
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	a = read_input(&argv[1], argc);
	if (!a)
		return (write(2, "Error\n", 6));
	if (!is_ascending(a))
		sort_five(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
