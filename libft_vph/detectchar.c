/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:09:39 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/26 15:58:42 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** _ATTENTION_ recherche 00, si 01 puis 00 (0x0100)
**			OU recherche c,	 si c-1 puis c (0x2223 pour c = '#')
** 			=> Les deux octects sont ON
** _ATTENTION_ si memsize > mem recherchée => fonction FAIL
** _ATTENTION_ endian
*/

__uint128_t		detectchar(__uint128_t mem, uint8_t memsize, uint8_t c)
{
	__uint128_t distribution;
	__uint128_t eighty;

	distribution = 1;
	eighty = 0x80;
	if (!(memsize <= 16 && memsize >= 1))
	{
		ft_putstr_fd_v2(RED"error detectchar\n"RESET, 2);
		return (0);
	}
	while (--memsize)
	{
		distribution = (distribution << 8) + 0x1;
		eighty = (eighty << 8) + 0x80;
	}
	mem = mem ^ (c * distribution);
	return ((mem - distribution) & ~mem & eighty);
}
