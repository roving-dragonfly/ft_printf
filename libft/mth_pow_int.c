/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mth_pow_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:47:58 by vphongph          #+#    #+#             */
/*   Updated: 2019/04/03 04:11:09 by vphongph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <i386/limits.h>

/*
** __Protection__
** on divise INT64 MAX par notre nombre,
** si le quotient < nombre, trigger sécurité et renvoie 0
** Attention pour les nombre < 0, le prochain nombre sera du signe opposé
** et donc la division est différente selon le cas, INT64 MAX ou INT64 MIN
*/

static int8_t	check_result(int64_t original_x, int64_t current_x)
{
	if (original_x > 0 && LLONG_MAX / current_x < original_x)
	{
		ft_putstr_fd_v2(RED"Result too big\n"RESET, 2);
		return (1);
	}
	if (original_x < 0)
	{
		if (current_x > 0 && (-LLONG_MAX - 1) / -current_x < -original_x)
		{
			ft_putstr_fd_v2(RED"Result too big\n"RESET, 2);
			return (1);
		}
		if (current_x < 0 && ((-LLONG_MAX) / current_x <= 1
				|| (-LLONG_MAX) / current_x < -original_x))
		{
			ft_putstr_fd_v2(RED"Result too big\n"RESET, 2);
			return (1);
		}
	}
	return (0);
}

static int64_t	calc_result(int64_t x, int64_t y)
{
	int64_t original_x;

	original_x = x;
	while (--y > 0)
	{
		x *= original_x;
		if (y != 1 && check_result(original_x, x))
			return (0);
	}
	return (x);
}

static int64_t	known_pow(int64_t x, int64_t y)
{
	if (y == 1)
		return (x);
	if (y == 0)
		return (1);
	return (0);
}

// static int64_t	zero_one_pow(int64_t x, int64_t y)
// {
// 	if (y == 0)
// 		return (1);
// 	if (x == 0)
// 	{
// 		if (y < 0)
// 			ft_putstr_fd_v2(RED"Infinity\n"RESET, 2);
// 		return (0);
// 	}
// 	if (x == -1 && y & 1)
// 		return (-1);
// 	return (1);
// }

int64_t			mth_pow_int(int64_t x, int64_t y)
{
	// if (x == 0 || x == 1 || x == -1)
		// return (zero_one_pow(x, y));
	if (y < 2)
		return (known_pow(x, y));
	if (check_result(x, x))
		return (0);
	return (calc_result(x, y));
}
