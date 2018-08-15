# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 13:13:35 by jechoque          #+#    #+#              #
#    Updated: 2018/02/07 14:08:41 by jechoque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc

RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror

LIB1 =		./libft/libft.a

LIB2 =		./minilibx_macos/libmlx.a

NAME =		fractol

HDR =		./include/fractol.h

SRC =		./src/batman.c		\
		./src/burningship.c	\
		./src/complex.c		\
		./src/hook.c		\
		./src/init.c		\
		./src/julia.c		\
		./src/main.c		\
		./src/mandelbrot.c	\
		./src/utils.c		\

OBJ =		$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ) $(HDR)
	@make -C ./libft
	@make -C ./minilibx_macos
	@$(CC) $(CFLAGS) -I ./include $(OBJ) -o $(NAME) $(LIB1) $(LIB2) -framework OpenGL -framework Appkit
	@echo "#####################################"
	@echo "##  ___ __   __   __ ___  __  _    ##"
	@echo "##  |_  |_) |__| |    |  |  | |    ##"
	@echo "##  |   | \ |  | |__  |  |__| |__  ##"
	@echo "##                                 ##"
	@echo "#####################################"
	@echo "\033[1;34mfractol\t\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

clean :
	@make -C ./libft clean
	@make -C ./minilibx_macos clean
	@$(RM) $(OBJ)

fclean : clean
	@make -C ./libft fclean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
