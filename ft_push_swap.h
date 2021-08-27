/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/27 17:31:33 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_pushswap
{
	char	**a;
	char	**b;
}	t_swap;

//	ft_push_swap.c
int		main(int argc, char **argv);

//	ft_error.c
void	ft_error(void);
void	ft_error_free(t_swap tab);
void	ft_free_ls(char **ls);

//	ft_init.c
t_swap	ft_init_arg(t_swap tab, char **argv);
t_swap	ft_init(t_swap tab, int argc, char **argv);
void	ft_check(t_swap tab);
char	**ft_duplicate(char **ls);

//	ft_swap.c
t_swap	ft_sa(t_swap tab);
t_swap	ft_sb(t_swap tab);
t_swap	ft_ss(t_swap tab);

//	ft_push.c
t_swap	ft_pa(t_swap tab);
t_swap	ft_pb(t_swap tab);
char	**ft_push_left(char **ls);
char	**ft_push_right(char **ls, char *new);

//	ft_rotate.c
t_swap	ft_ra(t_swap tab);
t_swap	ft_rb(t_swap tab);
t_swap	ft_rr(t_swap tab);
char	**ft_rotate_left(char **ls);

//	ft_reverse.c
t_swap	ft_rra(t_swap tab);
t_swap	ft_rrb(t_swap tab);
t_swap	ft_rrr(t_swap tab);
char	**ft_rotate_right(char **ls);

//	ft_sort.c
t_swap	ft_sort(t_swap tab);
t_swap	ft_classic_sort_a(t_swap tab);
t_swap	ft_classic_sort_b(t_swap tab);
char	**ft_free_sort(char **ls);

//	ft_sort_utils0.c
int		ft_check_sort(char **ls);
int		ft_find_smaller(char **ls);
int		ft_find_bigger(char **ls);
t_swap	ft_short_way_a(t_swap tab, int i);
size_t	ft_lenght(int nb);

//	ft_small_sort.c
t_swap	ft_sort_3_a(t_swap tab);
t_swap	ft_sort_5_a(t_swap tab);

//	ft_radix_sort.c
t_swap	ft_radix_sort(t_swap tab, char **ls);
int		ft_compt_zero(char **ls, int j);
int		ft_find_zero(char **ls, int j);

//	ft_radix_sort_utils.c
char	*ft_dec_to_bin(int n);
char	*ft_dec_to_bin_sized(int n, int size);
char	**ft_tab_index(t_swap tab, char **ls);
int		ft_find_size(char **ls);
char	**ft_move_up(char **ls, int i);

//	ft_fusion_sort.c
t_swap	ft_fusion_sort(t_swap tab, char **ls);
t_swap	ft_random_index(t_swap tab, char **ls);
int		ft_index(char *s, char **ls);

#endif
