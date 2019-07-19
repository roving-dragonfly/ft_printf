/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 23:03:20 by aalves            #+#    #+#             */
/*   Updated: 2019/07/18 23:07:17 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_printf_specifier_char(t_printf_meta *meta, t_printf_output *out, char **format, va_list ap)
{
	unsigned char	c;
	size_t			len;

	(*format)++;
	len = 1;
	c = va_arg(ap, int);
	if (!(meta->flags & FT_PRINTF_FLAG_LEFT_AJUST))
	{
		while (len++ < (size_t)meta->width)
            out->fn(' ', out->buf, out->i++, out->max);
	}
	out->fn(c, out->buf, out->i++, out->max);
	if (meta->flags & FT_PRINTF_FLAG_LEFT_AJUST)
	{
		while (len++ < (size_t)meta->width)
			out->fn(' ', out->buf, out->i++, out->max);
	}
	return (true);
}
