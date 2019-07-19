/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:50:45 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/18 19:45:01 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** ATTENTION les nb négatifs hors base 10, s'affichent sur 16 octets
*/

static void		fill_base_tab(char *base_tab)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 43)
		if (i <= 9 || i >= 17)
			base_tab[++j] = '0' + i;
}

static uint8_t	put_base10(__uint128_t nb, char *base_tab, char signedness)
{
	uint8_t		i;

	i = 1;
	if ((__int128_t)nb < 0 && signedness == 's')
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb > 10 - 1)
		i += put_base10(nb / 10, base_tab, signedness);
	write(1, &base_tab[nb % 10], 1);
	return (i);
}

uint8_t			ft_putnbr_base(__uint128_t nb, uint8_t base, char signedness)
{
	char		base_tab[36];
	uint8_t		i;

	i = 1;
	if (base < 2 || base > 36)
		return (0);
	fill_base_tab(base_tab);
	if (base == 10)
		return (put_base10(nb, base_tab, signedness));
	if (nb > base - 1)
		i += ft_putnbr_base(nb / base, base, signedness);
	write(1, &base_tab[nb % base], 1);
	return (i);
}
