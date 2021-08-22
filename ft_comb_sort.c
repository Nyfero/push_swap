/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/22 12:43:02 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_comb_sort(t_swap tab)
{
	int	i;
	int	len_comb;
	int j;

	len_comb = (ft_lstrlen(tab.a) / 2);
	j = 0;
	while (j < 1000)
//	while (ft_check_sort(tab.a) == 0)
	{
		i = 0;
		while (tab.a[i + len_comb])
		{
			if (ft_atoi(tab.a[i]) > ft_atoi(tab.a[i + len_comb]))
				tab = ft_fastest_comb(tab, i, len_comb);
			/*if (ft_find_bigger(tab.a) == 0)
				tab = ft_ra(tab);
			if (ft_lstrlen(tab.a) <= 5)
				tab = ft_sort_5(tab);*/
			i++;
		}
		if (len_comb > 1)
			len_comb--;
		j++;
	}
	return (tab);
}

t_swap	ft_fastest_comb(t_swap tab, int i, int len_comb)
{
	if (len_comb == 1 && i == 0)
		return (ft_sa(tab));
	if (i < (ft_lstrlen(tab.a) / 2))
	{
		while (i > 0)
		{
			tab = ft_ra(tab);
			i--;
		}
	}
	else
	{
		while (i < ft_lstrlen(tab.a))
		{
			tab = ft_rra(tab);
			i++;
		}
	}
	tab = ft_pb(tab);
	i = len_comb;
	while (i > 0)
	{
		tab = ft_ra(tab);
		i--;
	}
	tab = ft_pa(tab);
	tab = ft_sa(tab);
	tab = ft_pb(tab);
	while (i < len_comb)
	{
		tab = ft_rra(tab);
		len_comb--;
	}
	tab = ft_pa(tab);
	return (tab);
}
