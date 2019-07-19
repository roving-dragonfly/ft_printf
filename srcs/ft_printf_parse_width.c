/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_width.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 21:30:04 by aalves            #+#    #+#             */
/*   Updated: 2019/06/29 03:35:34 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_printf_parse_width(t_printf_meta *meta, char **format, va_list ap)
{
	int		width;

	if (!*format || !**format)
		return (false);
	if (**format == '*')
	{
		width = va_arg(ap, int);
		(*format)++;
		if (width < 0)
		{
			meta->flags |= FT_PRINTF_FLAG_LEFT_AJUST;
			width = -width;
		}
	}
	else if (ft_isdigit(**format))
        width = ft_printf_atoi(format);
	else
        width = 0;
    meta->width = width;
	return (true);
}
