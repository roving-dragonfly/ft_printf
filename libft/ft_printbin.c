/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:43:16 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/21 00:33:20 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** __ATTENTION__
** Size == nb bits et NON nb octets
** Si on utilise sizeof il faut x8
*/

int16_t	ft_printbin(__uint128_t nb, uint8_t size, uint8_t format_0b)
{
	uint8_t		i;
	__uint128_t	one;

	i = 0;
	one = 1;
	if (size > 128)
		return (-1);
	if (format_0b == 'b')
		write(1, "0b", 2);
	while (i < size)
		nb & (one << (size - 1 - i++)) ? write(1, "1", 1) : write(1, "0", 1);
	return (i);
}
