/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 03:32:34 by aalves            #+#    #+#             */
/*   Updated: 2019/06/29 03:45:40 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This atoi takes a char** as input in order to increment the format string
**	when parsing numbers.
*/

int		ft_printf_atoi(char **str)
{
	unsigned int	nbr;

	nbr = 0U;
	while (**str && **str >= '0' && **str <= '9')
	{
		nbr = nbr * 10 + **str - '0';
		(*str)++;
	}
	return (nbr);
}
