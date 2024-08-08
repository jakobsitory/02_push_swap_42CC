/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:18:39 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:28:17 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if the given character is a digit.
 * 
 * @param c The character to check, represented as an integer.
 * @return 1 if `c` is a digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	if (('0' <= c) && (c <= '9'))
		return (1);
	else
		return (0);
}
