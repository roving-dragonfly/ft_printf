/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 23:01:48 by aalves            #+#    #+#             */
/*   Updated: 2019/07/18 23:12:52 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_printf_specifier_string(t_printf_meta *meta, t_printf_output *out, char **format, va_list ap)
{
	size_t	len;
	char	*s;

	(*format)++;
	s = va_arg(ap, char *);
	len = ft_strlen(s);
	if (meta->flags & FT_PRINTF_FLAG_PRECISION)
		len = len < (size_t)meta->precision ? len : (size_t)meta->precision;
	if (!(meta->flags & FT_PRINTF_FLAG_LEFT_AJUST))
	{
		while (len++ < (size_t)meta->width)
            out->fn(' ', out->buf, out->i++, out->max);
	}
	while (*s &&
		   (!(meta->flags & FT_PRINTF_FLAG_PRECISION) || meta->precision--))
		out->fn(*(s++), out->buf, out->i++, out->max);
	if (meta->flags & FT_PRINTF_FLAG_LEFT_AJUST)
	{
		while (len++ < (size_t)meta->width)
			out->fn(' ', out->buf, out->i++, out->max);
	}
	return (true);
}
