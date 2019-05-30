/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_check_nupi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 01:14:21 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/30 18:04:23 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check Not a Number, Unnormal, Pseudo infinity
** Characteristics of these values on Wikipedia, extended precision
** Inf != pseudo Inf
** NaN != NaN
** Unnormal != Unnormal and no arithmetic permitted except * 1
*/

int8_t	lf_check_nupi(long double x)
{
	t_longf ulf;

	ulf.x = x;
	if (ulf.y.exponent == 0b111111111111111 && ulf.y.mantissa != 1ULL << 63)
		return (1);
	if (ulf.y.exponent != 0 && !(ulf.y.mantissa & (1ULL << 63)))
		return (1);
	return (0);
}
