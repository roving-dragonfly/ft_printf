/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:26:33 by aalves            #+#    #+#             */
/*   Updated: 2019/07/19 04:45:22 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#define BUFFER_SIZE 4096

static bool		test_char(char **suite, ...)
{
	va_list ap, copy;
	t_printf_output out;
	int	own, glib;
	char got[BUFFER_SIZE];
	char expected[BUFFER_SIZE];
	bool ret = true;

	va_start(ap, suite);
	va_copy(copy, ap);
    out = (t_printf_output){.fn = ft_buffer_out, .buf = got, .i = 0, .max = (size_t)-1U};
	for (char **test = suite; *test; test++)
	{
		own = ft_printf_handler(&out, *test, ap);
		glib = vsprintf(expected, *test, ap);
		if (own != glib)
		{
			printf("OWN > %d\tGLIB > %d\n<%s>", own, glib, *test);
			ret = false;
		}
		if (ft_strcmp(got, expected))
        {
			printf("GOT > <%s>\nEXPECTED > <%s>\n<%s>\n", got, expected, *test);
			ret = false;
		}
        ft_bzero(got, BUFFER_SIZE);
		ft_bzero(expected, BUFFER_SIZE);
		out = (t_printf_output){.fn = ft_buffer_out, .buf = got, .i = 0, .max = (size_t)-1U};
	}
	return ret;
}

int main()
{
	char	*test_char_suite[3] = {"Random string",
								   "toto %c",
								   NULL};
 	if (test_char(test_char_suite, '5'))
		printf("test char ok\n");
	return 0;
}
