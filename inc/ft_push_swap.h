/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/12/01 15:04:26 by gsap             ###   ########.fr       */
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
int		ft_check_space(char **argv);

//	ft_error.c
void	ft_error(void);
void	ft_error_free(t_swap stack);
void	ft_error_chunk(t_swap stack, char **ls);

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

//	ft_sort.c
t_swap	ft_sort_stack(t_swap stack);
t_swap	ft_basic_sort_a(t_swap stack);
char	**ft_free_sort(char **ls);
int		ft_index(char *s, char **ls);

//	ft_sort_utils0.c
int		ft_check_sort(char **ls);
int		ft_find_smaller(char **ls);
int		ft_find_bigger(char **ls);
t_swap	ft_less_cost(t_swap stack, int i);
size_t	ft_lenght_int(int nb);

//	ft_stack_sort.c
t_swap	ft_sort_chunk(t_swap stack, char **tmp);
char	**ft_create_chunk(char **ls, int i);
t_swap	ft_move_chunk(t_swap stack, char **tab);
int		ft_isin_chunk(char *stack, char **chunk);
t_swap	ft_chunk_to_a(t_swap stack);

//	ft_small_sort.c
t_swap	ft_sort_3_a(t_swap stack);
t_swap	ft_sort_5_a(t_swap stack);

//	ft_radix_sort.c
t_swap	ft_radix_sort(t_swap stack, char **ls);
t_swap	ft_radix(t_swap stack, char **index, int j, int i);
int		ft_compt_zero(char **ls, int j);
t_swap	ft_radix_base(t_swap stack, char **tmp, int j, int i);
t_swap	ft_radix_opti(t_swap stack, char **tmp, int j, int k);

//	ft_radix_sort_utils.c
char	*ft_dec_to_bin(int n);
char	*ft_dec_to_bin_sized(int n, int size);
char	**ft_stack_index(t_swap stack, char **ls);
int		ft_find_size(char **ls);
char	**ft_move_up(char **ls, int j);

//	ft_display.c
void	ft_display_stack(t_swap stack);

#endif
