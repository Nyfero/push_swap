/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fusion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/27 17:37:25 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_fusion_sort(t_swap tab, char **ls)
{
	int	i;

	while (ft_lstrlen(tab.a) > 5)
	{
		while (ft_find_smaller(tab.a) == 0 || ft_find_bigger(tab.a) == 0)
			tab = ft_ra(tab);
		tab = ft_pb(tab);
	}
	tab = ft_sort_5_a(tab);
	while (ft_lstrlen(tab.b) > 0)
		tab = ft_random_index(tab, ls);
	i = ft_find_smaller(tab.a);
	tab = ft_short_way_a(tab, i);
	return (tab);
}

t_swap	ft_random_index(t_swap tab, char **ls)
{
	int	i;
	int	pivot;
	int	tmp;

	i = 0;
	tmp = ft_index(tab.b[0], ls);
	if (tmp < ft_index(tab.a[0], ls))
		while (tmp < ft_index(tab.a[i], ls))
			i++;
	while (tmp > ft_index(tab.a[i % ft_lstrlen(tab.a)], ls))
		i++;
	i = (i % ft_lstrlen(tab.a));
	pivot = ft_index(tab.a[i], ls);
	tab = ft_short_way_a(tab, i);
	if (ft_lstrlen(tab.b) > 1)
	{
		while (tmp < ft_index(tab.b[1], ls) && ft_index(tab.b[1], ls) < pivot)
		{
			tab = ft_sb(tab);
			tab = ft_pa(tab);
		}
	}
	tab = ft_pa(tab);
	return (tab);
}

int	ft_index(char *s, char **ls)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = ft_atoi(s);
	while (ls[i])
	{
		if (tmp == ft_atoi(ls[i]))
			return (i);
		i++;
	}
	return (-1);
}
