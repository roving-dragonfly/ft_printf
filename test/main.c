/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:26:33 by aalves            #+#    #+#             */
/*   Updated: 2019/07/18 23:18:00 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int		ft_printf_toto(t_printf_output *out, const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	return (ft_printf_handler(out, format, ap));
}


int main()
{
	t_printf_output out;

	char *fmt = "lskdjflksdjf \n%56.88s";

	int	own, glib;

	out = (t_printf_output){.fn = ft_std_out, .buf = fmt, .i = 0, .max = (size_t)-1U};
    //ft_printf_toto(&out ,"integer %056.3hhd\n hexa maj %12.5X\n, hexa std %15.8x\noctal %15.8o\n binary %b, lol %y", 56, 65266, 5484, 5489, 9879);
	own = ft_printf_toto(&out, fmt, "ayyyy lmao\n");
	glib = printf(fmt, "ayyyy lmao\n");
	printf("own > %d\nglib > %d\n", own, glib);
	return 0;
}

