/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:20:43 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:24:54 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Fills a block of memory with a specified value.
 * 
 * @param s A pointer to the memory block to be filled.
 * @param c The value to be set. Although it's passed as an `int`, it's treated as an `unsigned char`.
 * @param n The number of bytes to be filled.
 * @return The original pointer `s` to the memory block.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
