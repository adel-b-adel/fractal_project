# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 15:48:36 by rfrankly          #+#    #+#              #
#    Updated: 2019/10/20 19:57:54 by rfrankly         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = ./src
OBJ_DIR = ./obj

INCLUDES = -I libft -I include
LIBS = -L libft -lft -lmlx -framework OpenGL -framework AppKit

SRCS = main.c for_all_fractals.c create_mandelbrot.c create_julia.c\
create_burning_ship.c create_celtic_mandelbrot.c exit.c process_keys.c mouse.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(OBJ_DIR) $(NAME) 

$(OBJ_DIR):
	mkdir obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
		make -C libft
		$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
		/bin/rm -f $(OBJS) $(wildcard *.gch)
		make clean -C libft/

fclean: clean
		/bin/rm -f $(NAME)
		make fclean -C libft/

re: fclean all
