/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:29:08 by aalves            #+#    #+#             */
/*   Updated: 2019/06/29 03:02:02 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_short(t_printf_meta *meta, char **format)
{
    if (**format == 'h')
	{
		meta->flags |= FT_PRINTF_FLAG_SHORT;
        (*format)++;
		if (**format == 'h')
		{
			meta->flags |= FT_PRINTF_FLAG_CHAR;
			(*format)++;
		}
	}
}

static void	parse_long(t_printf_meta *meta, char **format)
{
    if (**format == 'l')
	{
        meta->flags |= FT_PRINTF_FLAG_LONG;
        (*format)++;
		if (**format == 'l')
		{
            meta->flags |= FT_PRINTF_FLAG_LONG_LONG;
			(*format)++;
		}
	}
	if (**format == 'q')
	{
		meta->flags |= FT_PRINTF_FLAG_LONG_LONG;
		(*format)++;
	}
}

static void	parse_intmax_t(t_printf_meta *meta, char **format)
{
	if (**format == 'j')
	{
        meta->flags |= sizeof(intmax_t) == sizeof(long) ? FT_PRINTF_FLAG_LONG : FT_PRINTF_FLAG_LONG_LONG;
		(*format)++;
	}
}

static void	parse_size_t(t_printf_meta *meta, char **format)
{
	if (**format == 'z' || **format == 'Z')
	{
        meta->flags |= sizeof(size_t) == sizeof(long) ? FT_PRINTF_FLAG_LONG : FT_PRINTF_FLAG_LONG_LONG;
		(*format)++;
	}
}

bool	ft_printf_parse_length(t_printf_meta *meta, char **format)
{
	if (!*format || !**format)
		return (false);
    parse_short(meta, format);
	parse_long(meta, format);
	parse_intmax_t(meta, format);
	parse_size_t(meta, format);
	return (true);
}
