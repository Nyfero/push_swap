/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/19 17:09:16 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_sort(t_swap tab)
{
	while (ft_check_sort(tab.a) == 0)
	{
		if (ft_lstrlen(tab.a) <= 5)
			tab = ft_sort_5(tab);
		else
			tab = ft_classic_sort(tab);
	}
	while (ft_lstrlen(tab.b) > 0)
		tab = ft_pa(tab);
	return (tab);
}

t_swap	ft_classic_sort(t_swap tab)
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
