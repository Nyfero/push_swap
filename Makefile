# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 14:07:19 by gsap              #+#    #+#              #
#    Updated: 2021/11/17 11:24:12 by gsap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREY = \e[90m
RED = \e[91m
GREEN = \e[92m
YELLOW = \e[93m
BLUE = \e[34m
PURPLE = \e[95m
CYAN = \e[96m
END = \e[39m

NAME = push_swap

BONUS = checker

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS_PATH = srcs

SRCS_BONUS_PATH = srcs_bonus

SRCS = $(addprefix $(SRCS_PATH)/,ft_push_swap.c ft_error.c ft_init.c ft_push.c \
	ft_reverse.c ft_rotate.c ft_swap.c ft_sort.c ft_sort_utils0.c \
	ft_small_sort.c ft_radix_sort.c ft_radix_sort_utils.c ft_display.c)

SRCS_BONUS = $(addprefix $(SRCS_BONUS_PATH)/, ft_checker.c ft_display.c \
	ft_error_bonus.c ft_init_bonus.c ft_push_bonus.c ft_reverse_bonus.c \
	ft_rotate_bonus.c ft_swap_bonus.c)

OBJS_PATH = objs/

OBJS_BONUS_PATH = objs_bonus/

OBJS = $(patsubst $(SRCS_PATH)%.c,	$(OBJS_PATH)%.o, $(SRCS))

OBJS_BONUS = $(patsubst $(SRCS_BONUS_PATH)%.c,	$(OBJS_BONUS_PATH)%.o, $(SRCS_BONUS))

INC = inc/ft_push_swap.h

INC_BONUS = inc/ft_push_swap_bonus.h

DIR = libft/

LIBFT = $(addprefix $(DIR)/,libft.a)

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(LIBFT) $(OBJS_PATH) $(OBJS)
	@ echo "$(BLUE)\n		*** Make $(NAME) ***\n$(END)"
	@ $(CC) $(FLAGS) $(OBJS_PATH)/*.o -o $(NAME) $(DIR)libft.a
	@ echo "$(GREEN)\n		---$(NAME) created ---\n$(END)"

$(BONUS): $(LIBFT) $(OBJS_BONUS_PATH) $(OBJS_BONUS)
	@ echo "$(BLUE)\n		*** Make $(BONUS) ***\n$(END)"
	@ $(CC) $(FLAGS) $(OBJS_BONUS_PATH)/*.o -o $(BONUS) $(DIR)libft.a
	@ echo "$(GREEN)\n		---$(BONUS) created ---\n$(END)"

$(LIBFT):
	@ echo "$(BLUE)\n		*** Make Libft ***\n$(END)"
	@ make -C $(DIR)

$(OBJS_PATH):
	@ mkdir -p $(OBJS_PATH)

$(OBJS_BONUS_PATH):
	@mkdir -p $(OBJS_BONUS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)
	@ $(CC) $(FLAGS) -I $(INC) -c $< -o $@

$(OBJS_BONUS_PATH)%.o: $(SRCS_BONUS_PATH)%.c $(INC_BONUS)
	@ $(CC) $(FLAGS) -I $(INC_BONUS) -c $< -o $@

clean:
	@ $(RM) $(OBJS_PATH)
	@ $(RM) $(OBJS_BONUS_PATH)
	@ echo "$(PURPLE)\n		*** Clean objects ***\n$(END)"

fclean: clean
	@ make fclean -C $(DIR)
	@ $(RM) $(NAME)
	@ $(RM) $(BONUS)
	@ echo "$(RED)\n		*** Remove $(NAME) ***\n$(END)"

re: fclean all

.PHONY: all clean fclean re
