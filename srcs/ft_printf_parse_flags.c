/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:53:12 by aalves            #+#    #+#             */
/*   Updated: 2019/06/29 02:58:32 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	set_flag(t_printf_meta *meta, char c)
{
	if (c == '#')
        meta->flags |= FT_PRINTF_FLAG_ALTERNATE;
	else if (c == '0')
        meta->flags |= FT_PRINTF_FLAG_ZERO_PAD;
	else if (c == '-')
		meta->flags |= FT_PRINTF_FLAG_LEFT_AJUST;
	else if (c == ' ')
		meta->flags |= FT_PRINTF_FLAG_SPACE;
	else if (c == '+')
		meta->flags |= FT_PRINTF_FLAG_SIGN;
	else
		return (false);
	return (true);
}

bool ft_printf_parse_flags(t_printf_meta *meta, char **format)
{
	meta->flags = 0U;
	if (!*format && !**format)
		return (false);
	while (set_flag(meta, **format))
		(*format)++;
	return (true);
}
