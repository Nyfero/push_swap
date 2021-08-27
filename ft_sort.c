/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/27 17:41:49 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_sort(t_swap tab)
{
	char	**tmp;

	tmp = ft_duplicate(tab.a);
	if (!tmp)
		ft_error_free(tab);
	tmp = ft_free_sort(tmp);
	if (ft_lstrlen(tab.a) < 60)
		tab = ft_classic_sort_a(tab);
	else
		tab = ft_radix_sort(tab, tmp);
	ft_free_ls(tmp);
	return (tab);
}

t_swap	ft_classic_sort_a(t_swap tab)
{
	while (ft_lstrlen(tab.a) > 5)
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
	tab = ft_sort_5_a(tab);
	while (ft_lstrlen(tab.b) > 0)
		tab = ft_pa(tab);
	return (tab);
}

char	**ft_free_sort(char **ls)
{
	int		tmp;
	char	*swp;
	int		i;
	int		j;

	i = 0;
	while (ls[i])
	{
		j = i + 1;
		tmp = ft_atoi(ls[i]);
		while (ls[j])
		{
			if (tmp > ft_atoi(ls[j]))
			{
				swp = ls[i];
				ls[i] = ls[j];
				ls[j] = swp;
				tmp = ft_atoi(ls[i]);
			}
			j++;
		}
		i++;
	}
	return (ls);
}
