/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:44:17 by jschott           #+#    #+#             */
/*   Updated: 2023/08/21 16:52:09 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_min(t_list **list)
{
	t_list	*lst;
	t_list	*lst_min;
	int		min;

	if (!(*list))
		return (NULL);
	min = 0;
	lst_min = NULL;
	lst = *list;
	while (lst)
	{
		if ((lst->index == -1)
			&& (!min || (long) lst->content < (long) lst_min->content))
		{
			lst_min = lst;
			min = 1;
		}
		lst = lst->next;
	}
	return (lst_min);
}

void	index_list(t_list **list)
{
	t_list	*lst;
	int		index;

	index = 0;
	lst = get_min(list);
	while (lst)
	{
		lst->index = index++;
		lst = get_min(list);
	}
}

int	valid_input(void *content, t_list *rest)
{
	t_list	*tmp;
	long	num;

	tmp = rest;
	while (tmp)
	{
		num = (long) tmp->content;
		if (content == tmp->content || num < INT_MIN || num > INT_MAX)
			return (0);
		tmp = tmp->next;
	}
	if ((long) content < INT_MIN || (long) content > INT_MAX)
		return (0);
	if (rest && rest->next)
		return (valid_input(rest->content, rest->next));
	else
		return (1);
}

int	alphanum_str(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			while (ft_isspace(argv[i][j]))
				j++;
			if (ft_strchr("+-", argv[i][j]) && (argv[i][++j] == '\0' \
				|| !ft_strchr("0123456789\0", (int) argv[i][j])))
				return (0);
			while (argv[i][j] != '\0' && ft_strchr("0123456789", argv[i][j]))
				j++;
			if (!ft_isspace(argv[i][j]) && !ft_strchr("0123456789", argv[i][j]))
				return (0);
		}
		i++;
	}
	return (1);
}

t_list	*read_input(char **argv, int argc)
{
	t_list	*input;
	t_list	*int_put;
	int		i;
	char	**help;

	input = 0;
	i = 0;
	help = &argv[0];
	if ((argc > 2 && ft_strchr(argv[0], ' ')) || !alphanum_str(argv))
		return (0);
	if (argc == 2 && ft_strchr(argv[0], ' '))
		help = ft_split(*argv, ' ');
	while (help[i] != 0)
		ft_lstadd_back(&input, ft_lstnew((void *) help[i++]));
	int_put = ft_lstmap(input, (void *) ft_atol, free);
	ft_lstclear(&input, free);
	if (!int_put || !valid_input(int_put->content, int_put->next))
	{
		ft_lstclear(&int_put, free);
		return (0);
	}
	index_list(&int_put);
	return (int_put);
}
