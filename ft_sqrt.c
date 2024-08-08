/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:05:54 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:22:33 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Calculates the square root of a non-negative integer.
 * 
 * @param nb The non-negative integer whose square root is to be computed.
 * @return The square root of `nb` if `nb` is a perfect square, otherwise 0.
 */
int	ft_sqrt(int nb)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (nb - i >= 0)
	{
		nb = nb - i;
		i += 2;
		j++;
	}
	if (nb == 0)
		return (j);
	else
		return (0);
}
