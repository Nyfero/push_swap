/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fusion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/22 14:16:11 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_fusion_sort(t_swap tab, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		i++;
	}
	i = 1;
		while (i % 6 > 0)
		{
			tab = ft_pb(tab);
			i++;
		}
		tab = ft_revert_sort_5_b(tab);
		while (ft_lstrlen(tab.b) > 0)
		{
			tab = ft_pa(tab);
			tab = ft_ra(tab);
		}
	i++;
	while (i % 6 > 0)
	{
		tab = ft_pb(tab);
		i++;
	}
	tab = ft_revert_sort_5_b(tab);
	while (ft_lstrlen(tab.b) > 0)
	{


































		tab = ft_pa(tab);
		tab = ft_ra(tab);
	}
	return(tab);
}
