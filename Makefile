# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/13 16:37:35 by hvashchu          #+#    #+#              #
#    Updated: 2017/09/13 16:37:39 by hvashchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC	= 	main.c \
		parser.c \
		init_win.c \
		draw.c \
		keyhook.c \
		color.c \
		transform.c

OBJ = $(SRC:.c=.o)
FLAGS = -framework OpenGL -framework AppKit -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx/ 
	make -C libft/
	gcc -o $(NAME) $(OBJ) libft/*.o minilibx/*.o $(FLAGS)
	@echo fdf has been made

%.o: %.c
	gcc -c -o  $@ $<

cleanlib:
	make clean -C ./libft
	make clean -C ./minilibx

fcleanlib:
	make fclean -C ./libft
	make clean -C ./minilibx

clean: cleanlib
	rm -f $(OBJ)
	@echo *.o have been cleaned.

fclean: clean fcleanlib
	rm -f $(NAME)
	@echo *.a and *.o have been cleaned.

re: fclean all
