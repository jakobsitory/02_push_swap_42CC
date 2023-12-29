/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:32:23 by jschott           #+#    #+#             */
/*   Updated: 2023/08/03 11:52:16 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memloc;

	memloc = malloc (nmemb * size);
	if (!memloc)
		return (NULL);
	return (ft_memset(memloc, 0, nmemb * size));
}
