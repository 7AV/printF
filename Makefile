# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 13:57:34 by sbudding          #+#    #+#              #
#    Updated: 2020/11/20 22:50:53 by sbudding         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRC = base/ft_printf.c \
	parser/ft_parser.c \
	parser/ft_flag_parse.c \
	parser/ft_width_parse.c \
	parser/ft_precision_parse.c \
	parser/ft_precision_parse_helper.c \
	parser/ft_type_parse.c \
	processor/ft_processor.c \
	processor/ft_c_type.c \
	processor/ft_di_type.c \
	processor/ft_p_type.c \
	processor/ft_s_type.c \
	processor/ft_u_type.c \
	processor/ft_x_type.c \
	processor/ft_ux_type.c \
	processor/ft_percent_type.c

GRBG = ft_flag_parse.o \
		ft_parser.o \
		ft_precision_parse.o \
		ft_precision_parse_helper.o \
		ft_printf.o \
		ft_processor.o \
		ft_type_parse.o \
		ft_width_parse.o \
		ft_c_type.o \
		ft_di_type.o \
		ft_p_type.o \
		ft_s_type.o \
		ft_u_type.o \
		ft_x_type.o \
		ft_ux_type.o \
		ft_percent_type.o 

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
		rm -rf a.out

re: fclean all

.PHONY: bonus clean fclean all re