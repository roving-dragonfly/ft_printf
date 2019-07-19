/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ltoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 21:24:36 by aalves            #+#    #+#             */
/*   Updated: 2019/06/29 22:28:20 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Sets the buffer with the value of integer (as uint64_t)
**	The output still need reversing and formating
**	PRINTF_LTOA_BUFFER limits the maximal size of the integer representation
*/

size_t	ft_printf_ltoa(t_printf_meta *meta, t_printf_output *out, t_printf_integer *integer)
{
    static char		buffer[PRINTF_LTOA_BUFFER];
	char			digit;
	uint64_t		val;

	integer->len = 0;
	val = integer->value;
	ft_bzero(buffer, PRINTF_LTOA_BUFFER);
    integer->buffer = buffer;
	if (!val)
		meta->flags &= ~FT_PRINTF_FLAG_ALTERNATE;
	if (meta->precision)
	{
		while (val && integer->len < PRINTF_LTOA_BUFFER)
		{
			digit = val % integer->base;
			if (digit < 10)
                buffer[integer->len++] = digit + '0';
			else
				buffer[integer->len++] = digit - 10 + (meta->flags & FT_PRINTF_FLAG_UPCASE ? 'A' : 'a');
			val /= integer->base;
		}
	}
	return (ft_printf_integer_format(meta, out, integer));
}
