# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 10:43:17 by jschott           #+#    #+#              #
#    Updated: 2023/08/22 10:12:55 by jschott          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.h push_swap.c sort_logic.c \
		read_input.c swap_ops.c ft_atoi.c \
		ft_isdigit.c ft_lstadd_back.c ft_lstmap.c \
		ft_lstnew.c ft_lstlast.c ft_strlcpy.c \
		ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
		ft_lstsize.c ft_memcmp.c ft_split.c \
		ft_strchr.c ft_strlen.c index.c \
		ft_calloc.c ft_memset.c sort_logic_toa.c \
		ft_sqrt.c ft_strdup.c ft_abs.c \
		insertion_sort.c

OBJS = $(SRC:.c=.o)

CC = cc

FT_FLAGS = -g -Werror -Wall -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(FT_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FT_FLAGS) *.o -o $@

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re