/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:21:39 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:21:54 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Copies a string into another, ensuring the target is null-terminated.
 * 
 * @param dest A pointer to the destination buffer where the string is copied.
 * @param src A pointer to the source string to be copied.
 * @param size The size of the destination buffer.
 * @return The total length of the source string.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = ft_strlen (src);
	i = 0;
	if ((int) size != 0)
	{
		while (src [i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}
