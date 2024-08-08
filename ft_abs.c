/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:55:49 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:11:25 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Computes the absolute value of a long integer.
 * 
 * @param num The long integer whose absolute value is to be computed.
 * @return The absolute value of `num`.
 */
long int	ft_abs(long int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
