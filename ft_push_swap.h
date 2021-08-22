/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/22 13:18:26 by gsap             ###   ########.fr       */
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

int		main(int argc, char **argv);

void	ft_error(void);
void	ft_error_free(t_swap tab);

t_swap	ft_init_arg(t_swap tab, char **argv);
t_swap	ft_init(t_swap tab, int argc, char **argv);
void	ft_check(t_swap tab);

t_swap	ft_sa(t_swap tab);
t_swap	ft_sb(t_swap tab);
t_swap	ft_ss(t_swap tab);

t_swap	ft_pa(t_swap tab);
t_swap	ft_pb(t_swap tab);
char	**ft_push_left(char **ls);
char	**ft_push_right(char **ls, char *new);

t_swap	ft_ra(t_swap tab);
t_swap	ft_rb(t_swap tab);
t_swap	ft_rr(t_swap tab);
char	**ft_rotate_left(char **ls);

t_swap	ft_rra(t_swap tab);
t_swap	ft_rrb(t_swap tab);
t_swap	ft_rrr(t_swap tab);
char	**ft_rotate_right(char **ls);

int		ft_check_sort(char **ls);
int		ft_check_revert_sort(char **ls);
int		ft_find_smaller(char **ls);
int		ft_find_bigger(char **ls);

t_swap	ft_sort_3_a(t_swap tab);
t_swap	ft_sort_5_a(t_swap tab);
t_swap	ft_revert_sort_3_b(t_swap tab);
t_swap	ft_revert_sort_5_b(t_swap tab);

t_swap	ft_sort(t_swap tab);
t_swap	ft_classic_sort_a(t_swap tab);
t_swap	ft_classic_sort_b(t_swap tab);

t_swap	ft_fusion_sort(t_swap tab, int len);

//t_swap	ft_comb_sort(t_swap tab);
//t_swap	ft_fastest_comb(t_swap tab, int i, int len_comb);

//t_swap	ft_quick_sort(t_swap tab, int taille);

#endif
