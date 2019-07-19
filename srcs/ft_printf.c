/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:15:14 by aalves            #+#    #+#             */
/*   Updated: 2019/05/30 18:15:14 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		ret;

	va_list va;
	va_start(va, format);

	ret = ft_vsnprintf(ft_std_out, (char*)(uintptr_t)&out_fct_wrap, (size_t)-1, format, va);
	va_end(va);
	return ret;
}

int		ft_fprintf(FILE *stream, const char *format, ...)
{
	va_list va;
	va_start(va, format);


	va_end(va);
	return ret;
}
