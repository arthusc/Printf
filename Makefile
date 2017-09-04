# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achambon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/10 16:46:50 by achambon          #+#    #+#              #
#    Updated: 2017/08/28 16:29:57 by achambon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(FT_LIB)

FT_LIB_NAME = ftprintf

FT_LIB = lib$(FT_LIB_NAME).a

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = $(SRC_DIR)libft.h

FT_SRC_DIR = libft/srcs

PRINTF_HEADER = $(PRINTF_DIR)ft_printf.h

PRINTF_DIR = includes/

LIBFT_COMPILED = libft/srcs/ft_putchar.o \
				 libft/srcs/ft_memdel.o \
				 libft/srcs/ft_strclr.o \
				 libft/srcs/ft_strmap.o \
				 libft/srcs/ft_strstr.o \
				 libft/srcs/ft_itoa_base.o \
				 libft/srcs/ft_memmove.o \
				 libft/srcs/ft_strcmp.o \
				 libft/srcs/ft_strmapi.o \
				 libft/srcs/ft_strsub.o \
				 libft/srcs/ft_atoi.o \
				 libft/srcs/ft_lstadd.o \
				 libft/srcs/ft_memset.o \
				 libft/srcs/ft_strcpy.o \
				 libft/srcs/ft_strncat.o \
				 libft/srcs/ft_strtrim.o \
				 libft/srcs/ft_bzero.o \
				 libft/srcs/ft_lstdel.o \
				 libft/srcs/ft_itoa.o\
				 libft/srcs/ft_strcut.o\
				 libft/srcs/ft_strncmp.o\
				 libft/srcs/ft_swap.o\
				 libft/srcs/ft_count_word.o\
				 libft/srcs/ft_lstdelone.o\
				 libft/srcs/ft_putchar_fd.o\
				 libft/srcs/ft_strdel.o\
				 libft/srcs/ft_strncpy.o\
				 libft/srcs/ft_tolower.o\
				 libft/srcs/ft_double_memalloc.o\
				 libft/srcs/ft_lstiter.o\
				 libft/srcs/ft_putendl.o\
				 libft/srcs/ft_strdup.o\
				 libft/srcs/ft_strndup.o\
				 libft/srcs/ft_toupper.o\
				 libft/srcs/ft_error.o\
				 libft/srcs/ft_lstmap.o\
				 libft/srcs/ft_putendl_fd.o\
				 libft/srcs/ft_strequ.o\
				 libft/srcs/ft_strnequ.o\
				 libft/srcs/ft_wordlen.o\
				 libft/srcs/ft_isalnum.o\
				 libft/srcs/ft_lstnew.o\
				 libft/srcs/ft_putnbr.o\
				 libft/srcs/ft_striter.o\
				 libft/srcs/ft_strnew.o\
				 libft/srcs/ft_isalpha.o\
				 libft/srcs/ft_memalloc.o\
				 libft/srcs/ft_putnbr_fd.o\
				 libft/srcs/ft_striteri.o\
				 libft/srcs/ft_strnjoinfree.o\
				 libft/srcs/ft_isascii.o\
				 libft/srcs/ft_memccpy.o\
				 libft/srcs/ft_putstr.o\
				 libft/srcs/ft_strjoin.o\
				 libft/srcs/ft_strnstr.o\
				 libft/srcs/ft_isdigit.o\
				 libft/srcs/ft_memchr.o\
				 libft/srcs/ft_putstr_fd.o\
				 libft/srcs/ft_strlcat.o\
				 libft/srcs/ft_strrchr.o\
				 libft/srcs/ft_isprint.o\
				 libft/srcs/ft_memcmp.o\
				 libft/srcs/ft_strcat.o\
				 libft/srcs/ft_strlen.o\
				 libft/srcs/ft_strrev.o\
				 libft/srcs/ft_iterative_factorial.o\
				 libft/srcs/ft_memcpy.o\
				 libft/srcs/ft_strchr.o\
				 libft/srcs/ft_strlen_c.o\
				 libft/srcs/ft_strsplit.o

PRINTF_COMPILED =	srcs/conv_b.o\
					srcs/ft_error_management.o\
					srcs/no_conv.o\
					srcs/conversion_specifier.o\
					srcs/call_buffer.o\
					srcs/ft_printf.o\
					srcs/conv_c.o\
					srcs/conv_d.o\
					srcs/conv_o.o\
					srcs/conv_p.o\
					srcs/conv_s.o\
					srcs/conv_u.o\
					srcs/conv_x.o\
					srcs/init_conv.o\
					srcs/option.o\
					srcs/parse_conversion.o\


COMPILED = $(LIBFT_COMPILED) $(PRINTF_COMPILED)

all: $(FT_LIB)

$(FT_LIB):  $(COMPILED)
	@ar rc $(FT_LIB) $(COMPILED)

$(FT_COMPILED): %.o : $(FT_SRC_DIR)%.c $(HEADER)
	$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) $< -o $@

$(PRINTF_COMPILED): %.o : %.c $(PRINTF_HEADER)
	$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) -I $(PRINTF_DIR) $< -o $@

clean:
	-/bin/rm -f $(COMPILED)

fclean: clean
	-/bin/rm -f $(FT_LIB)

re: fclean all

.PHONY.: all clean fclean re