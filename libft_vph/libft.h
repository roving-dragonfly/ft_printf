/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphongph <vphongph@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:26:35 by vphongph          #+#    #+#             */
/*   Updated: 2019/05/30 17:20:29 by aalvesph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
/* # include <i386/endian.h> */

/*
**___________________________PORTABILITY PROTECTION_____________________________
*/

/* # if BYTE_ORDER == LITTLE_ENDIAN */
# if 1

/*
**_________________________COLORS_(ESCAPE SEQUENCES)____________________________
** \e instead of \033 is ok too, but not standard (-pedantic)
*/

#  define RED			"\033[38;2;255;0;0m"
#  define DARKPINK		"\033[38;2;252;19;104m"
#  define PINK			"\033[38;2;253;155;203m"
#  define BLUE			"\033[38;2;57;154;250m"
#  define GREEN			"\033[38;2;175;215;44m"
#  define YELLOW		"\033[38;2;243;197;80m"
#  define ALLIANCE		"\033[38;2;51;196;127m"
#  define FEDERATION	"\033[38;2;65;128;219m"
#  define ASSEMBLY		"\033[38;2;160;97;209m"
#  define ORDER			"\033[38;2;255;105;80m"
#  define BLINK			"\033[5:m"
#  define BELL			"\a"
#  define RESET			"\033[0m"

/*
**_________________________________CONSTANTS____________________________________
*/

#  define EXP_LF		16383

/*
**_________________________________LIBRARIES____________________________________
*/

#  include <stdlib.h>
#  include <stdint.h>
/*
**_________________________________STRUCTURES___________________________________
*/

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef	struct	s_dlist
{
	struct s_dlist	*prev;
	struct s_dlist	*next;
	void			*content;
	size_t			content_size;
}				t_dlist;

typedef struct	s_512speed
{
	char	ram[511];
	char	init;
}				t_512speed;

typedef struct	s_64speed
{
	char	ram[63];
	char	init;
}				t_64speed;

typedef union	u_lftochar
{
	long double	x;
	char		y[sizeof(long double)];
}				t_lftochar;

typedef union	u_lftoint
{
	long double	x;
	__int128_t	y;
}				t_lftoint;

struct			s_long_double
{
	uint64_t		mantissa;
	uint16_t		exponent : 15;
	uint8_t			sign : 1;
	uint64_t		padding : 48;
};

typedef union	u_longf
{
	long double				x;
	struct s_long_double	y;
}				t_longf;

/*
** One implicit bit in the mantissa, but cast in long double -> will be explicit
*/
struct			s_double
{
	uint64_t		mantissa : 52;
	uint16_t		exponent : 11;
	uint8_t			sign : 1;
	uint64_t		padding : 64;
};

typedef union	u_float
{
	double			x;
	struct s_double	y;
}				t_float;

/*
**_________________________________PROTOTYPES___________________________________
*/

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memjoin(void *s1, void *s2, size_t l, size_t n);
void			*ft_memjoinfree_l(void *s1, void *s2, size_t l, size_t n);
void			*ft_memcpy_v2(void *dst, void *src, size_t n);
int				ft_strlen_v2(char *s);
int				ft_putstr_fd_v2(char *s, int fd);
int				ft_putstr_v2(char *s);
void			ft_bzero_v2(void *s, size_t n);
char			*ft_strsub_v2(char *s, unsigned int start, size_t len);
t_dlist			*ft_dlstnew(void *content, size_t content_size);
int				ft_dlstdelone(t_dlist **top, void (*del)(void *, size_t));
int				ft_dlstadd(t_dlist **top, t_dlist *new);
int				ft_atoi(const char *str);
void			*ft_memset(void *b, int c, size_t len);
int				ft_strlen_v3(char *s);
char			*ft_itoa(int n);
int64_t			mth_pow_int(int64_t x, int64_t y);
int16_t			ft_printbin(__uint128_t nb, uint8_t size, uint8_t format_0b);
uint8_t			ft_putnbr_base(__uint128_t nb, uint8_t base, char signedness);
__uint128_t		detectchar(__uint128_t mem, uint8_t memsize, uint8_t c);
int16_t			lf_get_exponent(uint16_t to_get);
uint16_t		lf_set_exponent(int16_t to_set);
long double		lf_set_nan_inf(int8_t c, int8_t sign);
int8_t			lf_check_nupi(long double x);
long double		lf_remove_decimal(long double x);
int8_t			ft_putnnbr_base(__uint128_t nb, uint8_t base, char sign,
	int8_t n);

# endif
#endif
