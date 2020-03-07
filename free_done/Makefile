# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 20:31:59 by mlarraq           #+#    #+#              #
#    Updated: 2020/03/07 15:49:57 by mlarraq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../../libftprintf.a

CFLAGS = -Wall -Werror -Wextra -g

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
		# // write(1, "YOYOYOY\n", 8);
