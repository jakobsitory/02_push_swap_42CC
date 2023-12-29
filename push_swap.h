/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:42:19 by jschott           #+#    #+#             */
/*   Updated: 2023/08/18 13:16:16 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	long			index;
	struct s_list	*next;
}	t_list;

long int		ft_abs(long int num);
long			ft_atol(const char *str);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
int				ft_isdigit(int c);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			swap(t_list **stack);
void			push(t_list **dest, t_list **src);
void			rotate(t_list **stack);
void			rrotate(t_list **stack);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
				void (*del)(void *));
char			**ft_split(const char *s, char c);
void			ft_lstiter(t_list *lst, void (*f)(void *));
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_strlen(const char *str);
int				ft_isspace(char c);
t_list			*read_input(char **argv, int argc);
void			exec_ops(char *op, t_list **a, t_list **b);
int				ft_lstsize(t_list *lst);
void			sort_three(t_list **a);
void			sort_five(t_list **a, t_list **b);
int				is_ascending(t_list *stack);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			print_stack(t_list *list, int res);
void			group_stack(t_list **a, t_list **b, long int size);
void			sort2a(t_list **a, t_list **b, long int size, int res);
long int		calc_move(t_list **stack, unsigned int num, int res);
int				cheapest_move_a(t_list **stack, unsigned top, \
				unsigned bot, int res);
int				ft_sqrt(int nb);
char			*ft_strdup(const char *s);
void			cheapest_shuffle(t_list **dest, t_list **src);

#endif
