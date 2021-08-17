# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 14:07:19 by gsap              #+#    #+#              #
#    Updated: 2021/08/17 11:58:13 by gsap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -Wall -Wextra -Werror

RM = rm -f

DIR = libft/

LIBFTMAKE = $(MAKE) -C $(DIR)

all: lmake
	${CC} ft_push_swap.c ft_push_swap_utils.c ft_error.c ft_init.c -o $(NAME)

lmake:
	$(LIBFTMAKE)

clean:
	${RM} *.o
	${RM} $(DIR)*.o

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re lmake .c.o
