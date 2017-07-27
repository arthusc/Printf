# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achambon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 13:25:00 by achambon          #+#    #+#              #
#    Updated: 2017/01/06 14:27:39 by achambon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_atoi.c ft_putchar.c ft_putstr.c ft_strlen.c ft_isalpha.c ft_strcpy.c \
ft_strdup.c ft_strncpy.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c  \
ft_toupper.c ft_tolower.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_memset.c   \
ft_bzero.c ft_memcpy.c ft_memmove.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
ft_putstr_fd.c ft_lstpush.c ft_isspace.c ft_power.c ft_swapchar.c ft_swapint.c

HEADER = libft.h
NAME = libft.a
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	$(CC) -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJ)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

