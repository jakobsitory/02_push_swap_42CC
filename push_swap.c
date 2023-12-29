/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:41:35 by jschott           #+#    #+#             */
/*   Updated: 2023/08/22 09:51:34 by jschott          ###   ########.fr       */
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
