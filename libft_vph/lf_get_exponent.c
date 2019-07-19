/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_get_exponent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 00:29:10 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/30 20:52:48 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Obtenir l'exposant d'un long double en base 10
** Prend en paramètre la valeur brute de l'exposant
*/

int16_t	lf_get_exponent(uint16_t to_get)
{
	if (to_get < 0)
	{
		ft_putstr_fd_v2(RED"get expo : not a exponent\n"RESET, 2);
		return (0);
	}
	return ((int16_t)to_get - EXP_LF);
}
