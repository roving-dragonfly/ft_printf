/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 23:15:53 by aalves            #+#    #+#             */
/*   Updated: 2019/07/18 23:18:47 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_handler(t_printf_output *out, const char *format, va_list ap)
{
	t_printf_meta meta;

	ft_bzero(&meta, sizeof(meta));
	if (!out->buf)	//maybe relocate it on output buffer ?
		out->fn = ft_null_out;
	while (*format)
	{
		if (*format != '%')
		{
			out->fn(*format, out->buf, out->i++, out->max);
			format++;
			continue;
		}
        format++;

		//format %[flags][width][.precision][length]
        /* ft_printf_parse_flags(&meta, (char**)&format); */
		/* ft_debug_flags(meta.flags); */
        /* ft_printf_parse_width(&meta, (char**)&format, ap); */
		/* ft_debug_width(meta.width); */
        /* ft_printf_parse_precision(&meta, (char**)&format, ap); */
        /* ft_debug_precision(meta.precision); */
        /* ft_printf_parse_length(&meta, (char**)&format); */
		/* ft_debug_length(meta.flags); */
        /* ft_printf_parse_specifier(&meta, out, (char**)&format, ap); */

		if (!ft_printf_parse_flags(&meta, (char**)&format)
			|| !ft_printf_parse_width(&meta, (char**)&format, ap)
			|| !ft_printf_parse_precision(&meta, (char**)&format, ap)
			|| !ft_printf_parse_length(&meta, (char**)&format)
			|| !ft_printf_parse_specifier(&meta, out, (char**)&format, ap))
		{
			ft_putstr("\n\nft_printf error, stack unwind\n\n");	//remove lata
			return (-1);
		}
	}
	out->fn('\0', out->buf, out->i, out->max);	//dont increment i on \0
	return (out->i);
}
