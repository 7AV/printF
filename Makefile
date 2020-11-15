# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 13:57:34 by sbudding          #+#    #+#              #
#    Updated: 2020/11/15 17:57:28 by sbudding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -g
SRC = base/ft_printf.c \
	parser/ft_parser.c \
	parser/ft_flag_parse.c \
	parser/ft_width_parse.c \
	parser/ft_precision_parse.c \
	parser/ft_type_parse.c \
	processor/ft_processor.c

GRBG = ft_flag_parse.o \
		ft_parser.o \
		ft_precision_parse.o \
		ft_printf.o \
		ft_processor.o \
		ft_type_parse.o \
		ft_width_parse.o

INCLUDES = -I./includes

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) bonus -C ./libft
		cp libft/libft.a $(NAME)
		$(CC) $(CFLAGS) $(INCLUDES) $(SRC)
		ar rcs $(NAME) $(OBJ)

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(GRBG)
		rm -rf $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re: fclean all

.PHONY: bonus clean fclean all re