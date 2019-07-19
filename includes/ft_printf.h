/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves <aalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 04:22:34 by aalves            #+#    #+#             */
/*   Updated: 2019/07/18 23:11:22 by aalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
 #define FT_PRINTF_H

 #include <stdint.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdarg.h>
 #include <stdbool.h>
 #include "libft.h"

#define PRINTF_STATIC_BUFFER 4096
#define PRINTF_LTOA_BUFFER 4096		//change this shiet lata

struct	s_printf_meta
{
    size_t	flags;
	int		width;
	int		precision;
};
typedef	struct s_printf_meta t_printf_meta;

typedef	void (*output_fn)(char c, void *buf, size_t i, size_t max);

struct	s_printf_output
{
    output_fn	fn;
	void		*buf;
	size_t		i;
	size_t		max;
};
typedef	struct s_printf_output t_printf_output;

typedef	bool (*specifier_fn)(t_printf_meta *meta, t_printf_output *out, char **format, va_list ap);

struct	s_printf_integer
{
	uint64_t	value;
	bool		neg;
	size_t		base;
	char		*buffer;
	size_t		len;
};
typedef	struct s_printf_integer t_printf_integer;

/*
**	Main functionality
*/
int		ft_printf(const char *format, ...);
int		ft_fprintf(FILE *stream, const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);
int		ft_snprintf(char *str, size_t size, const char *format, ...);

int		ft_vprintf(const char *format, va_list ap);
int		ft_vfprintf(FILE *stream, const char *format, va_list ap);	//todo: output fn to stream
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_vsprintf(char *str, const char *format, va_list ap);
int		ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);


int		ft_printf_handler(t_printf_output *out, const char *format, va_list ap);
/*
**	Internal data structure & parsing
*/
 #define FT_PRINTF_FLAG_ALTERNATE (1U << 0U)
 #define FT_PRINTF_FLAG_ZERO_PAD (1U << 1U)
 #define FT_PRINTF_FLAG_LEFT_AJUST (1U << 2U)
 #define FT_PRINTF_FLAG_SPACE (1U << 3U)
 #define FT_PRINTF_FLAG_SIGN (1U << 4U)
 #define FT_PRINTF_FLAG_CHAR (1U << 5U)
 #define FT_PRINTF_FLAG_SHORT (1U << 6U)
 #define FT_PRINTF_FLAG_LONG (1U << 7U)
 #define FT_PRINTF_FLAG_LONG_LONG (1U << 8U)
 #define FT_PRINTF_FLAG_PRECISION (1U << 9U)
 #define FT_PRINTF_FLAG_UPCASE (1U << 10U)

bool	ft_printf_parse_flags(t_printf_meta *meta, char **format);
bool	ft_printf_parse_width(t_printf_meta *meta, char **format, va_list ap);
bool	ft_printf_parse_precision(t_printf_meta *meta, char **format, va_list ap);
bool	ft_printf_parse_length(t_printf_meta *meta, char **format);
bool	ft_printf_parse_specifier(t_printf_meta *meta, t_printf_output *out, char **format, va_list ap);

/*
**	Output interface
*/

void	ft_buffer_out(char c, void *buf, size_t i, size_t max);
void	ft_null_out(char c, void *buf, size_t i, size_t max);
void	ft_std_out(char c, void *buf, size_t i, size_t max);

//need stuct 4 params

/*
**	Utilities
*/
int		ft_printf_atoi(char **str);
size_t	ft_printf_ltoa(t_printf_meta *meta, t_printf_output *out, t_printf_integer *integer);

size_t	ft_reverse_out(t_printf_meta *meta, t_printf_output *out, t_printf_integer *integer);

/*
**	Specifier
*/
bool	ft_printf_specifier_integer(t_printf_meta *meta, t_printf_output *out, char **format, va_list ap);
bool	ft_printf_specifier_string(t_printf_meta *meta, t_printf_output *out, char **format, va_list ap);
/*
**	Formating
*/
size_t	ft_printf_integer_format(t_printf_meta *meta, t_printf_output *out, t_printf_integer *integer);

/*
**	Debugging shiet, remove later
*/

void	ft_debug_flags(size_t flags);
void	ft_debug_width(int width);
void	ft_debug_precision(int prec);
void	ft_debug_length(size_t flags);

#endif
