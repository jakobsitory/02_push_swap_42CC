/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:20:26 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:22:06 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Duplicates a string by allocating memory and copying the string into it.
 * 
 * @param s A pointer to the string to be duplicated.
 * @return A pointer to the duplicated string, or `NULL` if memory allocation fails.
 */
char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *) malloc (ft_strlen (s) + 1);
	if (!dup)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = (char) s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
