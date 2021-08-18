/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/18 16:27:34 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


t_swap	ft_magic_sort(t_swap tab)
{
	int	i;
	int	j;

	i = ft_lstrlen(tab.a);
	write(1, "0|\n", 3);
	while (ft_lstrlen(tab.b) != i)
	{
		write(1, "1|\n", 3);
		j = ft_find_smaller(tab.a);
		if (j == 0)
		{
			tab = ft_pb(tab);
			write(1, "2|\n", 3);
		}
		else if (j == 1)
		{
			tab = ft_sa(tab);
			write(1, "3|\n", 3);
		}
		else if (i - j >= j)
		{
			write(1, "4|\n", 3);
			while (j > 0)
			{
				tab = ft_ra(tab);
				j--;
				write(1, "4b|\n", 4);
			}
		}
		else
		{
			write(1, "5|\n", 3);
			while (j <= i)
			{
				tab = ft_rra(tab);
				j++;
				write(1, "5b|\n", 4);
			}
		}
		write(1, "6|\n", 3);
		tab = ft_pb(tab);
		write(1, "7|\n", 3);
	}
	while (i > 0)
	{
		write(1, "8|\n", 3);
		tab = ft_pa(tab);
		i--;
	}
	write(1, "9|\n", 3);
	return (tab);
}
