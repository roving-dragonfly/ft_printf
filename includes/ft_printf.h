/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 04:22:34 by aalves            #+#    #+#             */
/*   Updated: 2019/05/29 04:25:40 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
 #define FT_PRINTF_H

 #include <stdint.h>
 #include <stdlib.h>
 #include <stdarg.h>

int		ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);

#endif
