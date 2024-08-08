/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:33:53 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:30:57 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Checks if a character is a sign ('+' or '-') and returns a corresponding value.
 * 
 * @param c The character to check.
 * @return 1 if `c` is a '+', -1 if `c` is a '-', and 0 otherwise.
 */
int	ft_issign(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	else
		return (0);
}

/**
 * Checks if a character is a whitespace character.
 * 
 * @param c The character to check.
 * @return 1 if `c` is a whitespace character, 0 otherwise.
 */
int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

/**
 * Converts a string to a long integer.
 * 
 * @param str A pointer to the null-terminated byte string to be converted.
 * @return The converted value as a long integer.
 */
long	ft_toli(const char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]) != 0)
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb);
}

/**
 * Converts a string to a long integer, considering leading whitespace and sign.
 * 
 * @param str A pointer to the null-terminated byte string to be converted.
 * @return The converted value as a long integer, or 0 if the conversion is not possible.
 */
long	ft_atol(const char *str)
{
	long int	i;
	long int	s;

	i = 0;
	s = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		s = (long) ft_issign(str[i]);
		i++;
	}
	if (ft_isdigit(str[i]))
		return (s * ft_toli(&str[i]));
	else
		return (0);
}
