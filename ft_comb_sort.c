/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/21 17:19:49 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_comb_sort(t_swap tab)
{
	int	i;
	int	len_comb;

	len_comb = (ft_lstrlen(tab.a) / 2);
	while (ft_check_sort(tab.a) == 0)
	{
		i = 0;
		if (len_comb != 1)
			len_comb--;
		while (tab.a[i + len_comb])
		{
			if (ft_atoi(tab.a[i]) > ft_atoi(tab.a[i + len_comb]))
				tab = ft_fastest_comb(tab, i, len_comb);
			if (ft_find_bigger(tab.a) == 0)
				tab = ft_ra(tab);
			i++;
		}
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
		tab = ft_ra(tab);
		len_comb--;
	}
	tab = ft_pa(tab);
	return (tab);
}
