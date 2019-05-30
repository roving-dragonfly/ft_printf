/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:59:08 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/30 20:19:17 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_malloc(int n, unsigned int *nb, int *tmp, int len)
{
	char *str;

	if (n < 0)
	{
		if (!(str = (char *)ft_memalloc((uint32_t)(len + 2) * sizeof(*str))))
			return (NULL);
		*nb = (unsigned int)-n;
		str[0] = '-';
		*tmp = len;
	}
	else
	{
		if (!(str = (char *)ft_memalloc((uint32_t)(len + 1) * sizeof(*str))))
			return (NULL);
		*nb = (unsigned int)n;
		*tmp = len - 1;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	int				tmp;
	int				len;

	nb = 0;
	len = (n == 0) ? 1 : 0;
	tmp = n;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		len++;
	}
	if (!(str = ft_malloc(n, &nb, &tmp, len)))
		return (NULL);
	while (len > 0)
	{
		str[tmp] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
		tmp--;
	}
	return (str);
}
