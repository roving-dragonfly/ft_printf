/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_precision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 02:59:55 by aalves            #+#    #+#             */
/*   Updated: 2019/06/29 03:38:26 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_printf_parse_precision(t_printf_meta *meta, char **format, va_list ap)
{
	int precision;

	if (!*format || !**format)
		return (false);
	if (**format == '.')
	{
		precision = 0;
		(*format)++;
		if (ft_isdigit(**format))
			precision = ft_printf_atoi(format);
		else if (**format == '*')
		{
			precision = va_arg(ap, int);
			(*format)++;
			precision = precision < 0 ? 0 : precision;
		}
		meta->precision = precision;
		meta->flags |= FT_PRINTF_FLAG_PRECISION;
	}
	return (true);
}
