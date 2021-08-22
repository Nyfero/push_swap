# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 14:07:19 by gsap              #+#    #+#              #
#    Updated: 2021/08/22 12:51:06 by gsap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -Wall -Wextra -Werror

FS = -fsanitize=address -static-libsan -g

SRCS = ft_push_swap.c ft_error.c ft_init.c ft_push.c ft_reverse.c ft_rotate.c \
	ft_swap.c ft_sort.c ft_sort_utils0.c ft_small_sort.c ft_fusion_sort.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

DIR = libft/

LIBFTMAKE = $(MAKE) -C $(DIR)

all: $(OBJS) lmake
	@ echo "*** Make push_swap ***"
	@$(CC) $(OBJS) $(DIR)*.o -o $(NAME)
	@ echo "$(NAME) created"

lmake:
	@ echo "*** Make Libft ***"
	@$(LIBFTMAKE)

.c.o:
	@$(CC) -c $< -o $(<:.c=.o)

debug: $(OBJS) lmake
	@ echo "*** Make debug ***"
	@$(CC) $(FS) $(OBJS) $(DIR)*.o -o debug
	@ echo "debug created"

clean:
	$(RM) *.o
	$(RM) $(DIR)*.o

dclean:
	$(RM) debug
	rm -rf $(NAME).dSYM

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean dclean re lmake .c.o debug
