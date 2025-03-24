# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 11:54:56 by igngonza          #+#    #+#              #
#    Updated: 2024/12/22 12:36:52 by igngonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf_utils.c ft_printf.c
OBJ = $(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ) 
		ar rcs $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	: 	clean
		rm -f $(NAME)

re	: 	fclean all

.DEFAULT_GOAL := all
.PHONY: all clean fclean re