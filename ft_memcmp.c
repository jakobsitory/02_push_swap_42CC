/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:33:30 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:25:10 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Compares two blocks of memory.
 * 
 * @param s1 A pointer to the first memory block to be compared.
 * @param s2 A pointer to the second memory block to be compared.
 * @param n The number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if `s1` is found, respectively, to be less than, to
 * match, or be greater than `s2`.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	i = 0;
	ptr1 = s1;
	ptr2 = s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
