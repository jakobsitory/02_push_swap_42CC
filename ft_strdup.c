/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:20:26 by jschott           #+#    #+#             */
/*   Updated: 2023/08/15 15:46:51 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
