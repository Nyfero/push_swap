/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/19 16:57:54 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_sort_3(t_swap tab)
{
	while (ft_check_sort(tab.a) == 0)
	{
		if (ft_find_bigger(tab.a) == 0)
			tab = ft_ra(tab);
		else if (ft_find_bigger(tab.a) == 2)
			tab = ft_sa(tab);
		else if (ft_find_bigger(tab.a) == 1)
			tab = ft_rra(tab);
	}
	return (tab);
}

t_swap	ft_sort_5(t_swap tab)
{
	while (ft_check_sort(tab.a) == 0)
	{
		while (ft_lstrlen(tab.a) > 3)
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
		}
		if (ft_check_sort(tab.a) == 0)
			tab = ft_sort_3(tab);
	}
	return (tab);
}
