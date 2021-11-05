/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/11/04 15:15:29 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

t_swap	ft_sort_3_a(t_swap stack)
{
	while (ft_check_sort(stack.a) == 0)
	{
		if (ft_find_bigger(stack.a) == 0)
			stack = ft_ra(stack);
		else if (ft_find_bigger(stack.a) == 2)
			stack = ft_sa(stack);
		else if (ft_find_bigger(stack.a) == 1)
			stack = ft_rra(stack);
	}
	return (stack);
}

t_swap	ft_sort_5_a(t_swap stack)
{
	while (ft_check_sort(stack.a) == 0)
	{
		while (ft_lstrlen(stack.a) > 3)
		{
			if (ft_find_smaller(stack.a) == 0)
				stack = ft_pb(stack);
			else if (ft_find_smaller(stack.a) == 1)
				stack = ft_sa(stack);
			else if (ft_lstrlen(stack.a) - ft_find_smaller(stack.a)
				>= ft_find_smaller(stack.a))
				stack = ft_ra(stack);
			else
				stack = ft_rra(stack);
		}
		if (ft_check_sort(stack.a) == 0)
			stack = ft_sort_3_a(stack);
		if (ft_lstrlen(stack.b) > 1)
		{
			stack = ft_pa(stack);
			stack = ft_pa(stack);
		}
	}
	return (stack);
}
