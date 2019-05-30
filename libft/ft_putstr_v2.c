/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:35:26 by vphongph          #+#    #+#             */
/*   Updated: 2019/03/30 18:45:40 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_putstr_v2(char *s)
{
	int i;

	i = 0;
	if (!s)
	{
		write(2, RED"\aputstr v2 -> ∅ pointer\n"RESET, 45);
		return (-1);
	}
	if ((i = write(1, s, (size_t)ft_strlen_v2(s))) == -1)
	{
		write(2, RED"\aputstr v2 -> write ∅\n"RESET, 43);
		return (-1);
	}
	return (i);
}
