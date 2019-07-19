/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_remove_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:12:02 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/31 03:11:54 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Remove the decimal part of the long double float
*/

long double	lf_remove_decimal(long double x)
{
	t_longf ulf;
	int32_t	shift;

	if (lf_check_nupi(x))
	{
		ft_putstr_fd_v2(RED"rm decimal : input non ok\n"RESET, 2);
		return (0);
	}
	ulf.x = x;
	if ((shift = 63 - lf_get_exponent(ulf.y.exponent)) >= 64)
	{
		ulf.y.exponent = 0;
		ulf.y.mantissa = 0;
	}
	else if (shift > 0)
	{
		ulf.y.mantissa >>= shift;
		ulf.y.mantissa <<= shift;
	}
	return (ulf.x);
}
