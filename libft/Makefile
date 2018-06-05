# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/27 21:31:13 by hvashchu          #+#    #+#              #
#    Updated: 2017/01/12 19:14:50 by hvashchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

INC = -I libft.h

OBJ = ft_atoi.o \
	  ft_atoi_long.o \
	  ft_atoi_base.o \
	  ft_bzero.o \
	  ft_isalnum.o \
	  ft_isalpha.o \
	  ft_isascii.o \
	  ft_isdigit.o \
	  ft_ishex.o \
	  ft_isprint.o \
	  ft_itoa.o \
	  ft_lstadd.o \
	  ft_lstaddback.o \
	  ft_lstdel.o \
	  ft_lstdelone.o \
	  ft_lstiter.o \
	  ft_lstmap.o \
	  ft_lstnew.o \
	  ft_lstprint.o \
	  ft_lstsplit.o \
	  ft_memalloc.o \
	  ft_memccpy.o \
	  ft_memchr.o \
	  ft_memcmp.o \
	  ft_memcpy.o \
	  ft_memdel.o \
	  ft_memmove.o \
	  ft_memset.o \
	  ft_putchar_fd.o \
	  ft_putchar.o \
	  ft_putendl_fd.o \
	  ft_putendl.o \
	  ft_putnbr_fd.o \
	  ft_putnbr.o \
	  ft_putstr_fd.o \
	  ft_putstr.o \
	  ft_strcat.o \
	  ft_strchr.o \
	  ft_strclr.o \
	  ft_strcmp.o \
	  ft_strcpy.o \
	  ft_strdel.o \
	  ft_strdup.o \
	  ft_strequ.o \
	  ft_striter.o \
	  ft_striteri.o \
	  ft_strjoin.o \
	  ft_strlcat.o \
	  ft_strlen.o \
	  ft_strmap.o \
	  ft_strmapi.o \
	  ft_strncat.o \
	  ft_strncmp.o \
	  ft_strncpy.o \
	  ft_strnequ.o \
	  ft_strnew.o \
	  ft_strnstr.o \
	  ft_strrchr.o \
	  ft_strrev.o \
	  ft_strsplit.o \
	  ft_strstr.o \
	  ft_strsub.o \
	  ft_strtrim.o \
	  ft_swap.o \
	  ft_tolower.o \
	  ft_toupper.o \
	  get_next_line.o \
	  ft_arrdel.o \
	  ft_arrlen.o \
	  ft_lstlen.o \
	  ft_numlen.o

.PHONY:	all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
