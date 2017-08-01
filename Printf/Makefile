# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/29 22:02:18 by mbriffau          #+#    #+#              #
#    Updated: 2017/08/01 16:04:13 by mbriffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC = libft/libft.a

SRCS = srcs/

DIR = ./

FILES = 		ft_printf.c \
				conversion_specifier.c \
				conv_c.c \
				conv_s.c \
				conv_d.c 

all : $(NAME)

$(NAME):
	@gcc -o $(NAME) $(DIR)$(FILES) main.c $(INC)
	@gcc -o true_printf test_printf.c

clean :
	rm ft_printf
	rm true_printf

fclean : clean

make re: fclean all