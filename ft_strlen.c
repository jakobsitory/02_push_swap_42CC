/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:20:28 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:21:41 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Calculates the length of a string.
 * 
 * @param str A pointer to the string whose length is to be calculated.
 * @return The length of the string.
 */
int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
