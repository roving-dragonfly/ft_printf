/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:50:45 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/18 23:11:46 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** ATTENTION les nb négatifs hors base 10, s'affichent sur 16 octets
** ATTENTION ici le retour n'est pas le nb de carac imprimés,
** c'est le nb de caract restant à imprimer.
** Le retour peut être utiliser comme un indicateur de caract retirés d'un nb,
** ou un indicateur de surplus si n > nb
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

static uint8_t	put_base10(__uint128_t nb, char *base_tab, char sign, int8_t n)
{
	uint8_t		i;

	i = 1;
	if ((__int128_t)nb < 0 && sign == 's')
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb > 10 - 1)
		n = put_base10(nb / 10, base_tab, sign, n);
	if (n-- > 0)
		write(1, &base_tab[nb % 10], 1);
	return (n);
}

int8_t			ft_putnnbr_base(__uint128_t nb, uint8_t base, char sign,
	int8_t n)
{
	char		base_tab[36];
	uint8_t		i;

	i = 1;
	if (base < 2 || base > 36 || n < 0 || n > 39)
		return (0);
	fill_base_tab(base_tab);
	if (base == 10)
		return (put_base10(nb, base_tab, sign, n));
	if (nb > base - 1)
		n = ft_putnnbr_base(nb / base, base, sign, n);
	if (n-- > 0)
		write(1, &base_tab[nb % base], 1);
	return (n);
}
