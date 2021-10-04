# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 14:07:19 by gsap              #+#    #+#              #
#    Updated: 2021/10/03 13:01:43 by gsap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang -Wall -Wextra -Werror

SRCS = ft_push_swap.c ft_error.c ft_init.c ft_push.c ft_reverse.c ft_rotate.c \
	ft_swap.c ft_sort.c ft_sort_utils0.c ft_small_sort.c ft_fusion_sort.c \
	ft_radix_sort.c ft_radix_sort_utils.c ft_quick_sort.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

DIR = libft/

LIBFT = $(addprefix $(DIR)/,libft.a)

all: $(NAME)
	
$(NAME): $(OBJS) $(LIBFT)
	@ echo "\n		*** Make $(NAME) ***\n"
	@$(CC) $(OBJS) -o $(NAME) $(DIR)libft.a 
	@ echo "\n		---$(NAME) created ---\n"

$(LIBFT):
	@ echo "\n		*** Make Libft ***\n"
	@ make -C $(DIR)

.c.o:
	@$(CC) -c $< -o $(<:.c=.o)

clean:
	@ $(RM) $(OBJS)
	@ echo "\n		*** Clean *.o ***\n"

fclean: clean
	@ make fclean -C $(DIR)
	@ $(RM) $(NAME)
	@ echo "\n		*** Remove $(NAME) ***\n"

re: fclean all

.PHONY: all clean fclean re lmake .c.o
