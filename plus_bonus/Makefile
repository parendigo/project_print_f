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

NAME = ../../libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRC1 = *.c

HEAD1 = printf.h

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) *.c -I $(HEAD1)
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
