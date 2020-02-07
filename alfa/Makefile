# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 20:31:59 by mlarraq           #+#    #+#              #
#    Updated: 2020/02/01 16:15:27 by mlarraq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

CFLAGS = -Wall -Werror -Wextra

SRC = *.c

LIBFT_DIR = libft
LIBS = libft/libft.a

OBJ = $(SRC:.c=.o)

HEADERS = printf.h

all: $(NAME)

$(LIBS):
	make -C $(LIBFT_DIR)

$(NAME): $(SRC) $(LIBS)
	gcc -I $(HEADERS) -o $(NAME) $(SRC) $(LIBS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
