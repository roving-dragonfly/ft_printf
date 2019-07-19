/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 21:20:34 by aalves            #+#    #+#             */
/*   Updated: 2019/06/29 03:46:09 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_debug_flags(size_t flags)
{
	printf("FLAGS : \n");
    if (flags & FT_PRINTF_FLAG_ALTERNATE)
		printf("ALTERNATE\n");
    if (flags & FT_PRINTF_FLAG_ZERO_PAD)
		printf("ZERO_PAD\n");
	if (flags & FT_PRINTF_FLAG_LEFT_AJUST)
		printf("LEFT_AJUST\n");
    if (flags & FT_PRINTF_FLAG_SPACE)
		printf("SPACE\n");
    if (flags & FT_PRINTF_FLAG_SIGN)
		printf("SIGN\n");
}

void	ft_debug_width(int width)
{
    printf("WIDTH = <%d>\n", width);
}

void	ft_debug_precision(int prec)
{
	printf("PRECISION = <%d>\n", prec);
}

void	ft_debug_length(size_t flags)
{
	printf("LENGTH : \n");
    if (flags & FT_PRINTF_FLAG_CHAR)
		printf("CHAR\n");
    if (flags & FT_PRINTF_FLAG_SHORT)
		printf("SHORT\n");
    if (flags & FT_PRINTF_FLAG_LONG)
		printf("LONG\n");
    if (flags & FT_PRINTF_FLAG_LONG_LONG)
		printf("LONG LONG\n");
}
