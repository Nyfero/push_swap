/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/22 13:17:08 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_sort(t_swap tab)
{
	//while (ft_check_sort(tab.a) == 0)
	//{
		if (ft_lstrlen(tab.a) <= 5)
			tab = ft_sort_5_a(tab);
		else
			tab = ft_fusion_sort(tab, ft_lstrlen(tab.a));
	//}
	while (ft_lstrlen(tab.b) > 0)
		tab = ft_pa(tab);
	return (tab);
}

t_swap	ft_classic_sort_a(t_swap tab)
{
	if (ft_find_smaller(tab.a) == 0)
		tab = ft_pb(tab);
	else if (ft_find_smaller(tab.a) == 1)
		tab = ft_sa(tab);
	else if (ft_lstrlen(tab.a) - ft_find_smaller(tab.a)
		>= ft_find_smaller(tab.a))
		tab = ft_ra(tab);
	else
		tab = ft_rra(tab);
	return (tab);
}

t_swap	ft_classic_sort_b(t_swap tab)
{
	if (ft_find_smaller(tab.b) == 0)
		tab = ft_pa(tab);
	else if (ft_find_smaller(tab.b) == 1)
		tab = ft_sb(tab);
	else if (ft_lstrlen(tab.b) - ft_find_smaller(tab.b)
		>= ft_find_smaller(tab.b))
		tab = ft_rb(tab);
	else
		tab = ft_rrb(tab);
	return (tab);
}
