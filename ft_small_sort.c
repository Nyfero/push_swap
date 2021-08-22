/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/22 13:32:02 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_sort_3_a(t_swap tab)
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

t_swap	ft_sort_5_a(t_swap tab)
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
			tab = ft_sort_3_a(tab);
	}
	return (tab);
}

t_swap	ft_revert_sort_3_b(t_swap tab)
{
	while (ft_check_revert_sort(tab.b) == 0)
	{
		if (ft_find_smaller(tab.b) == 0)
			tab = ft_rb(tab);
		else if (ft_find_smaller(tab.b) == 2)
			tab = ft_sb(tab);
		else if (ft_find_smaller(tab.b) == 1)
			tab = ft_rrb(tab);
	}
	return (tab);
}

t_swap	ft_revert_sort_5_b(t_swap tab)
{
	while (ft_check_revert_sort(tab.b) == 0)
	{
		while (ft_lstrlen(tab.b) > 3)
		{
			if (ft_find_bigger(tab.b) == 0)
			{
				tab = ft_pa(tab);
				tab = ft_ra(tab);
			}
			else if (ft_find_bigger(tab.b) == 1)
				tab = ft_sb(tab);
			else if (ft_lstrlen(tab.b) - ft_find_bigger(tab.b)
				>= ft_find_bigger(tab.b))
				tab = ft_rb(tab);
			else
				tab = ft_rrb(tab);
		}
		if (ft_check_revert_sort(tab.b) == 0)
			tab = ft_revert_sort_3_b(tab);
	}
	return (tab);
}
