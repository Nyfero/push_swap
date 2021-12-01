/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/12/01 15:12:30 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

t_swap	ft_sort_stack(t_swap stack)
{
	char	**tmp;

	tmp = ft_duplicate_ls(stack.a);
	if (!tmp)
		ft_error_free(stack);
	tmp = ft_free_sort(tmp);
	if (ft_lstrlen(stack.a) == 100)
		stack = ft_sort_chunk(stack, tmp);
	else if (ft_lstrlen(stack.a) < 100)
	{
		stack = ft_basic_sort_a(stack);
		ft_free_ls(tmp);
	}
	else
		stack = ft_radix_sort(stack, tmp);
	return (stack);
}

t_swap	ft_basic_sort_a(t_swap stack)
{
	while (ft_lstrlen(stack.a) > 5)
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
	stack = ft_sort_5_a(stack);
	while (ft_lstrlen(stack.b) > 0)
		stack = ft_pa(stack);
	return (stack);
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
