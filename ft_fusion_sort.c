/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fusion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/29 17:12:49 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_fusion_sort(t_swap stack, char **ls)
{
	int	i;

	while (ft_lstrlen(stack.a) > 5)
	{
		while (ft_find_smaller(stack.a) == 0 || ft_find_bigger(stack.a) == 0)
			stack = ft_ra(stack);
		stack = ft_pb(stack);
	}
	stack = ft_sort_5_a(stack);
	while (ft_lstrlen(stack.b) > 0)
		stack = ft_random_index(stack, ls);
	i = ft_find_smaller(stack.a);
	stack = ft_short_way_a(stack, i);
	return (stack);
}

t_swap	ft_random_index(t_swap stack, char **ls)
{
	int	i;
	int	pivot;
	int	tmp;

	i = 0;
	tmp = ft_index(stack.b[0], ls);
	if (tmp < ft_index(stack.a[0], ls))
		while (tmp < ft_index(stack.a[i], ls))
			i++;
	while (tmp > ft_index(stack.a[i % ft_lstrlen(stack.a)], ls))
		i++;
	i = (i % ft_lstrlen(stack.a));
	pivot = ft_index(stack.a[i], ls);
	stack = ft_short_way_a(stack, i);
	if (ft_lstrlen(stack.b) > 1)
	{
		while (tmp < ft_index(stack.b[1], ls) && ft_index(stack.b[1], ls) < pivot)
		{
			stack = ft_sb(stack);
			stack = ft_pa(stack);
		}
	}
	stack = ft_pa(stack);
	return (stack);
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
