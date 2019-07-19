/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_set_exponent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 00:49:28 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/30 21:02:14 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Met en place l'exposant d'un long double
** Prend en paramètre la valeur base 10 de l'exposant à mettre en place
*/

uint16_t	lf_set_exponent(int16_t to_set)
{
	if (to_set < -EXP_LF || to_set > EXP_LF + 1)
	{
		ft_putstr_fd_v2(RED"set expo : exponent non ok\n"RESET, 2);
		return (0);
	}
	return ((uint16_t)to_set + EXP_LF);
}
