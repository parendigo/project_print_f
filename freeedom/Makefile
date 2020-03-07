# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 20:31:59 by mlarraq           #+#    #+#              #
#    Updated: 2020/02/06 18:11:22 by mlarraq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = ../../libftprintf.a
NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRCS = dop_funcs.c \
		exception.c \
		finds.c \
		finds_2.c \
		ft_add_char.c \
		ft_atoi.c \
		ft_bonus.c \
		ft_bzero.c \
		ft_celoe.c \
		ft_flags.c \
		ft_float.c \
		ft_gotov.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_memalloc.c \
		ft_memset.c \
		ft_precision.c \
		ft_print_bits.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_save.c \
		ft_stolbik.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strnew.c \
		ft_strredup.c \
		ft_strrejoin.c \
		ft_strresub.c \
		ft_strsub.c \
		ft_width.c \

HEADER = printf.h

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	gcc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
