/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:05:38 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/30 18:30:36 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_strlen_v2(char *s)
{
	char *str;

	if (!s && (write(2, RED"\astrlen v2 -> ∅ pointer\n"RESET, 45)))
		return (-1);
	str = s;
	while (1)
	{
		if (!*str)
			return ((int)(str - s));
		if (!*(str + 1))
			return ((int)((str + 1) - s));
		if (!*(str + 2))
			return ((int)((str + 2) - s));
		if (!*(str + 3))
			return ((int)((str + 3) - s));
		if (!*(str + 4))
			return ((int)((str + 4) - s));
		if (!*(str + 5))
			return ((int)((str + 5) - s));
		if (!*(str + 6))
			return ((int)((str + 6) - s));
		if (!*(str + 7))
			return ((int)((str + 7) - s));
		str += 8;
	}
}
