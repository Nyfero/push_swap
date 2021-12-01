/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:12:28 by gsap              #+#    #+#             */
/*   Updated: 2021/12/01 15:02:13 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

t_swap	ft_sort_chunk(t_swap stack, char **tmp)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	while (i < 100)
	{
		tab = ft_create_chunk(tmp, i);
		if (!tab)
			ft_error_chunk(stack, tmp);
		j = -1;
		while (++j < 20)
			stack = ft_move_chunk(stack, tab);
		ft_free_ls(tab);
		i += 20;
	}
	stack = ft_chunk_to_a(stack);
	ft_free_ls(tmp);
	return (stack);
}

char	**ft_create_chunk(char **ls, int i)
{
	char	**tmp;
	int		max_chunk;
	int		j;

	j = i % 20;
	max_chunk = j + 20;
	tmp = (char **)malloc(sizeof(char *) * 21);
	if (!tmp)
		ft_error();
	while (j < max_chunk)
	{
		tmp[j] = ft_strdup(ls[i]);
		if (!tmp[j])
		{
			ft_free_ls(tmp);
			return (NULL);
		}
		i++;
		j++;
	}
	tmp[20] = 0;
	return (tmp);
}

t_swap	ft_move_chunk(t_swap stack, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (ft_isin_chunk(stack.a[i], tab) == 0)
		i++;
	j = ft_lstrlen(stack.a) - 1;
	while (ft_isin_chunk(stack.a[j], tab) == 0)
		j--;
	j = ft_lstrlen(stack.a) - j - 1;
	if (i <= j)
		while (i-- > 0)
			stack = ft_ra(stack);
	else
		while (j-- >= 0)
			stack = ft_rra(stack);
	stack = ft_pb(stack);
	return (stack);
}

int	ft_isin_chunk(char *stack, char **chunk)
{
	int	i;

	i = -1;
	while (chunk[++i])
		if (ft_atoi(stack) == ft_atoi(chunk[i]))
			return (1);
	return (0);
}

t_swap	ft_chunk_to_a(t_swap stack)
{
	int	i;

	while (ft_lstrlen(stack.b) > 0)
	{
		i = ft_find_bigger(stack.b);
		if (i < ft_lstrlen(stack.b) / 2)
			while (i-- > 0)
				stack = ft_rb(stack);
		else
			while (i++ < ft_lstrlen(stack.b))
				stack = ft_rrb(stack);
		stack = ft_pa(stack);
	}
	return (stack);
}
