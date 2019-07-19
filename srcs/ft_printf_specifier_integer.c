/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier_integer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 03:50:02 by aalves            #+#    #+#             */
/*   Updated: 2019/07/18 01:45:59 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	set_integer_base(t_printf_meta *meta, char specifier)
{
	if (specifier == 'x' || specifier == 'X')
	{
		if (specifier == 'X')
            meta->flags |= FT_PRINTF_FLAG_UPCASE;
		return (16);
	}
	else if (specifier == 'd' || specifier == 'i')
		return (10);
	else if (specifier == 'o')
		return (8);
	else if (specifier == 'b')
		return (2);
	return (0);
}

bool	ft_printf_specifier_integer(t_printf_meta *meta, t_printf_output *out, char **format, va_list ap)
{
    size_t				base;
	t_printf_integer	integer;

	base = set_integer_base(meta, **format);
	if (!base)
		return (false);
	else
		(*format)++;
	integer = (t_printf_integer){.value = va_arg(ap, int), .base = base};
	ft_printf_ltoa(meta, out, &integer);
	return (true);
}

