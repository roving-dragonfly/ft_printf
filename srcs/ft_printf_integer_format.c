/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer_format.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 22:01:39 by aalves            #+#    #+#             */
/*   Updated: 2019/06/29 22:37:10 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Handles all formating flags, padding
**	Note that the integer buffer is still not reversed
*/

static void	pad_leading_zeros(t_printf_meta *meta, t_printf_integer *integer)
{
	if ((meta->flags & FT_PRINTF_FLAG_ZERO_PAD) && meta->width
		&& ((meta->flags & FT_PRINTF_FLAG_SIGN)
			|| (meta->flags & FT_PRINTF_FLAG_SPACE)
			|| integer->neg))
        meta->width--;
	while (integer->len < (size_t)meta->precision
		   && integer->len < PRINTF_LTOA_BUFFER)
		integer->buffer[integer->len++] = '0';
    if (meta->flags & FT_PRINTF_FLAG_ZERO_PAD)
	{
		while (integer->len < (size_t)meta->width
			   && integer->len < PRINTF_LTOA_BUFFER)
			integer->buffer[integer->len++] = '0';
	}
}

static void	alternate_handling(t_printf_meta *meta, t_printf_integer *integer)
{
	if (integer->len < PRINTF_LTOA_BUFFER)
	{
		if (integer->base == 16U && meta->flags & FT_PRINTF_FLAG_UPCASE)
			integer->buffer[integer->len++] = 'X';
		else if (integer->base == 16U)
			integer->buffer[integer->len++] = 'x';
		else if (integer->base == 2U)
			integer->buffer[integer->len++] = 'b';	
	}
	if (integer->len < PRINTF_LTOA_BUFFER)
        integer->buffer[integer->len++] = '0';
	if (integer->len < PRINTF_LTOA_BUFFER)
	{
		if (integer->neg)
            integer->buffer[integer->len++] = '-';
		else if (meta->flags & FT_PRINTF_FLAG_SIGN)
            integer->buffer[integer->len++] = '+';
		else if (meta->flags & FT_PRINTF_FLAG_SPACE)
			integer->buffer[integer->len++] = ' ';
	}
    //here reverse the output buffer into the output buffer
	
}

size_t	ft_printf_integer_format(t_printf_meta *meta, t_printf_output *out, t_printf_integer *integer)
{
    if (!(meta->flags & FT_PRINTF_FLAG_LEFT_AJUST))
		pad_leading_zeros(meta, integer);
	if (meta->flags & FT_PRINTF_FLAG_ALTERNATE)
		alternate_handling(meta, integer);
	return (ft_reverse_out(meta, out, integer));
}
