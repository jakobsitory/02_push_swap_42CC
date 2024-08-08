/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:32:23 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:28:29 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Allocates memory for an array of `nmemb` elements of `size` bytes each and initializes all bytes to zero.
 * 
 * @param nmemb The number of elements to allocate.
 * @param size The size of each element.
 * @return A pointer to the allocated memory, which is initialized to zero. If the allocation fails, returns `NULL`.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memloc;

	memloc = malloc (nmemb * size);
	if (!memloc)
		return (NULL);
	return (ft_memset(memloc, 0, nmemb * size));
}
