/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/29 17:31:31 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_radix_sort(t_swap stack, char **ls)
{
	char	**tmp;
	int		j;

	tmp = ft_stack_index(stack, ls);
	if (!tmp)
		ft_error_free(stack);
	j = ft_strlen(tmp[0]);
	stack = ft_radix(stack, tmp, --j, 0);
	ft_free_ls(tmp);
	return (stack);
}

t_swap	ft_radix(t_swap stack, char **tmp, int j, int i)
{
	int	k;

	k = ft_compt_zero(tmp, j);
	while (k > 1)
	{
		if (tmp[i][j] == '0')
			stack = ft_pb(stack);
		else
			stack = ft_ra(stack);
		i++;
	}
	if (k == 1)
		stack = ft_less_cost(stack, ft_find_zero(tmp, j));
	while (ft_lstrlen(stack.b) > 0)
		stack = ft_pa(stack);
	tmp = ft_move_up(tmp, j);
	if (ft_check_sort(stack.a) == 0 && (j - 1) >= 0)
		stack = ft_radix(stack, tmp, --j, 0);
	return (stack);
}

int	ft_compt_zero(char **ls, int j)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (ls[i])
	{
		if (ls[i][j] == '0')
			compt++;
		i++;
	}
	return (compt);
}

int	ft_find_zero(char **ls, int j)
{
	int	i;

	i = ft_lstrlen(ls) - 1;
	while (i >= 0)
	{
		if (ls[i][j] == '0')
			return (i);
		i--;
	}
	return (-1);
}
