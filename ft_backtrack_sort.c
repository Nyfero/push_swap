/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/10/04 17:53:47 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_find_following(char **ls, t_swap stack)
{
	int	i;
	int	j;
	int	tmp;
	int	compt[ft_lstrlen(ls) + 1];

	i = -1;
	while (ls[++i])
	{
		j = i;
		compt[i] = 1;
		tmp = ft_atoi(ls[j]);
		while (ls[++j])
		{
			if (ft_atoi(ls[j]) == tmp + 1)
			{
				tmp++;
				compt[i]++;
			}
		}
	}
	compt[i] = 0;
	stack = ft_find_biggest_follow(compt, stack , ls);
	return (stack);
}

t_swap	ft_find_biggest_follow(int *compt, t_swap stack ,char **ls)
{
	int	i;
	int	j;
	int	first;

	i = -1;
	first = compt[0];
	while (compt[++i])
	{
		if (first < compt[i])
		{
			first = compt[i];
			j = i;
		}
	}
	first = ft_atoi(ls[j]);
	stack = ft_send_on_b(first, stack, j, ls);
	return (stack);
}

t_swap	ft_send_on_b(int first, t_swap stack, int j, char **ls)
{
	int	i;

	i = -1;
	while (++i < j)
		stack = ft_pb(stack);
	i = -1;
	while (ls[++i])
	{
		if (ft_atoi(ls[i]) != first)
			stack = ft_pb(stack);
		else
		{
			stack = ft_ra(stack);
			first++;
		}
	}
	return (stack);
}

