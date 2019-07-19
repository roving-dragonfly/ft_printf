/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_specifier.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 03:00:03 by aalves            #+#    #+#             */
/*   Updated: 2019/07/18 03:03:13 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool			ft_printf_specifier_error(t_printf_meta *meta, t_printf_output *out, char **format, va_list ap)
{
	(void)meta;
	(void)format;
	(void)ap;
	(void)out;
    ft_putstr("SPECIFIER ERROR\n");	//remove this shiet lata
	return (false);
}

static void			init_specifier_tab(specifier_fn *tab)
{
	tab['b'] = *ft_printf_specifier_integer;
    tab['d'] = *ft_printf_specifier_integer;
    tab['i'] = *ft_printf_specifier_integer;
	tab['o'] = *ft_printf_specifier_integer;
	tab['s'] = *ft_printf_specifier_string;
    tab['x'] = *ft_printf_specifier_integer;
	tab['X'] = *ft_printf_specifier_integer;
	//Add p as integer

}

static specifier_fn *ft_switch(void)
{
	static specifier_fn	tab[256];
	static bool			initialized;	//could be removed at redability cost
	size_t				i;

	if (initialized)
		return (tab);
	i = 0;
	while (i < 256)
		tab[i++] = *ft_printf_specifier_error;
	init_specifier_tab(tab);
	initialized = true;
	return (tab);
}

bool	ft_printf_parse_specifier(t_printf_meta *meta, t_printf_output *out, char **format, va_list ap)
{
	if (!*format || !**format)
		return (false);
	return (ft_switch()[(int)**format](meta, out, format, ap));
}
