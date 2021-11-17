/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/11/17 15:37:45 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/inc/libft.h"

typedef struct s_pushswap
{
	char	**a;
	char	**b;
}	t_swap;

//	ft_push_swap.c
int		main(int argc, char **argv);
void 	ft_read_output(t_swap stack);
t_swap	ft_choose_action(char *str, t_swap stack);
int		ft_check_sort(char **ls);

//	ft_error.c
void	ft_error(void);
void	ft_error_free(t_swap stack);
void	ft_error_free_read(t_swap stack, char *str);

//	ft_init.c
t_swap	ft_init(t_swap stack, int argc, char **argv);
int		ft_nbr_arg(int argc, char **argv);
void	ft_check_arg(t_swap stack);
char	**ft_duplicate_ls(char **ls);

//	ft_swap.c
t_swap	ft_sa(t_swap stack);
t_swap	ft_sb(t_swap stack);
t_swap	ft_ss(t_swap stack);

//	ft_push.c
t_swap	ft_pa(t_swap stack);
t_swap	ft_pb(t_swap stack);
char	**ft_push_left(char **ls);
char	**ft_push_right(char **ls, char *new);

//	ft_rotate.c
t_swap	ft_ra(t_swap stack);
t_swap	ft_rb(t_swap stack);
t_swap	ft_rr(t_swap stack);
char	**ft_rotate_left(char **ls);

//	ft_reverse.c
t_swap	ft_rra(t_swap stack);
t_swap	ft_rrb(t_swap stack);
t_swap	ft_rrr(t_swap stack);
char	**ft_rotate_right(char **ls);

//	ft_sort_utils0.c
int		ft_check_sort(char **ls);

//	ft_display.c
void	ft_display_stack(t_swap stack);

#endif
