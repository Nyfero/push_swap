# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 14:07:19 by gsap              #+#    #+#              #
#    Updated: 2021/08/19 14:08:02 by gsap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -Wall -Wextra -Werror

SRCS = ft_push_swap.c ft_error.c ft_init.c ft_push.c ft_reverse.c ft_rotate.c \
	ft_swap.c ft_sort.c ft_sort_utils0.c ft_small_sort.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

DIR = libft/

LIBFTMAKE = $(MAKE) -C $(DIR)

all: $(OBJS) lmake
	$(CC) $(OBJS) $(DIR)*.o -o $(NAME)

lmake:
	$(LIBFTMAKE)

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

clean:
	$(RM) *.o
	$(RM) $(DIR)*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re lmake .c.o
