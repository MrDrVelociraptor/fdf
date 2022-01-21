# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 16:11:55 by nspeedy           #+#    #+#              #
#    Updated: 2022/01/13 14:32:37 by nspeedy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
 
SRCS = srcs/*.c

MLX = mlx
LIBFT = libft
INC = includes

LIBS = -L$(MLX) -lmlx -L$(LIBFT) -lft
HEADERS = -I$(INC) -I$(MLX) -I$(LIBFT)
FLAGS = $(LIBS) $(HEADERS) -framework OpenGL -framework AppKit

all:
	make -s -C $(MLX)
	make -s -C $(LIBFT)
	gcc $(SRCS) $(FLAGS) -o $(NAME)

clean:
	make clean -s -C $(MLX)
	make fclean -s -C $(LIBFT)
	rm -f $(NAME)
	
fclean: clean

re: clean all
