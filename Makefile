# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalves <aalves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 09:39:48 by aalves            #+#    #+#              #
#    Updated: 2016/03/06 02:38:27 by aalves           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 # -fsanitize=address
INCLUDES= -I./includes -I./libft/includes
LIBS= -L. -L./libft
SRCS =	srcs/ft_printf_handler.c \
	srcs/ft_printf_atoi.c \
	srcs/output.c \
	srcs/ft_printf_parse_flags.c \
	srcs/ft_printf_parse_width.c \
	srcs/ft_printf_parse_precision.c \
	srcs/ft_printf_parse_length.c \
	srcs/ft_printf_parse_specifier.c \
	srcs/ft_printf_specifier_integer.c \
        srcs/ft_printf_specifier_string.c \
	srcs/ft_printf_specifier_char.c \
	srcs/ft_printf_ltoa.c \
	srcs/ft_printf_integer_format.c \
	srcs/debug.c

OBJS = $(patsubst %.c, %.o, $(SRCS))
RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -o $(subst srcs/, build/, $@) -c $<

all: $(NAME)

$(NAME): build_dir $(OBJS)
	make -C ./libft/
	ar rcs $@ $(subst srcs/, build/, $(OBJS))
	ranlib $@

build_dir:
	mkdir -p ./build

test: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -o test_run ./test/main.c -lftprintf -lft

clean:
	$(RM) ./build
	make -C ./libft/ clean

fclean: clean
	$(RM) $(NAME)

re: fclean all
