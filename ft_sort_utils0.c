/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/27 12:44:05 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_sort(char **ls)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (ls[i])
	{
		min = ft_atoi(ls[i]);
		j = i + 1;
		while (ls[j])
		{
			if (min > ft_atoi(ls[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_find_smaller(char **ls)
{
	int	i;
	int	compt;
	int	min;

	i = 1;
	compt = 0;
	min = ft_atoi(ls[0]);
	while (ls[i])
	{
		if (min > ft_atoi(ls[i]))
		{
			min = ft_atoi(ls[i]);
			compt = i;
		}
		i++;
	}
	return (compt);
}

int	ft_find_bigger(char **ls)
{
	int	i;
	int	compt;
	int	max;

	i = 1;
	compt = 0;
	max = ft_atoi(ls[0]);
	while (ls[i])
	{
		if (max < ft_atoi(ls[i]))
		{
			max = ft_atoi(ls[i]);
			compt = i;
		}
		i++;
	}
	return (compt);
}

t_swap	ft_short_way_a(t_swap tab, int i)
{
	if (ft_lstrlen(tab.a) - i > i)
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
	return (tab);
}

size_t	ft_lenght(int nb)
{
	int		c;
	size_t	compt;

	c = nb;
	compt = 1;
	while ((c / 10) > 0)
	{
		compt++;
		c = c / 10;
	}
	return (compt);
}
