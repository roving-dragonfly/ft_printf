/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_set_nan_inf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 01:02:30 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/30 21:02:54 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ATTENTION au PSEUDO INF != INF
** ATTENTION au NaN, aucun n'est comparable, même pas à lui même
*/

long double	lf_set_nan_inf(int8_t c, int8_t sign)
{
	t_longf ulf;

	ulf.y.exponent = 0b111111111111111;
	if (sign == 0 || sign == 1)
		ulf.y.sign = (uint8_t)sign;
	else
		return (0);
	if (c == 'n')
	{
		ulf.y.mantissa = (1ULL << 63) + 1;
		return (ulf.x);
	}
	if (c == 'i')
	{
		ulf.y.mantissa = 1ULL << 63;
		return (ulf.x);
	}
	return (0);
}
