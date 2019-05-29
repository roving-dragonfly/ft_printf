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
CFLAGS = -Wall -Wextra -Werror
INCLUDES= -I./includes -I./libft
SRCS = srcs/main.c

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

clean:
	$(RM) $(OBJS)
	make -C ./libft/ clean

fclean: clean
	$(RM) $(NAME)

re: fclean all
