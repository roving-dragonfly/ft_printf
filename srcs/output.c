/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:33:41 by aalves            #+#    #+#             */
/*   Updated: 2019/06/15 20:13:54 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Reverses the output of backwards made string
**	Also handles the padding
*/
size_t	ft_reverse_out(t_printf_meta *meta, t_printf_output *out, t_printf_integer *integer)
{
	size_t	i;

	i = 0;
	if (!(meta->flags & FT_PRINTF_FLAG_LEFT_AJUST)
		&& !(meta->flags & FT_PRINTF_FLAG_ZERO_PAD))
	{
		while (i++ + integer->len < (size_t)meta->width)
            out->fn(' ', out->buf, out->i++, out->max);
	}
	while (integer->len)
        out->fn(integer->buffer[--(integer->len)], out->buf, out->i++, out->max);
	if (meta->flags & FT_PRINTF_FLAG_LEFT_AJUST)
	{
		while (i++ + integer->len < (size_t)meta->width)
			out->fn(' ', out->buf, out->i++, out->max);
	}
    return (out->i);
}

void ft_buffer_out(char c, void *buf, size_t i, size_t max)
{
	if (i < max)
		((char*)buf)[i] = c;
}

void ft_null_out(char c, void *buf, size_t i, size_t max)
{
	(void)c;
	(void)buf;
    (void)i;
	(void)max;
}

void ft_std_out(char c, void *buf, size_t i, size_t max)
{
	(void)buf;
	(void)max;
	(void)i;
	write(1, &c, 1);
}
