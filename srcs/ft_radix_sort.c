/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/11/23 10:31:14 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

t_swap	ft_radix_sort(t_swap stack, char **ls)
{
	char	**tmp;
	int		j;

	tmp = ft_stack_index(stack, ls);
	if (!tmp)
		ft_error_free(stack);
	j = ft_strlen(tmp[0]) - 1;
	stack = ft_radix(stack, tmp, j, 0);
	ft_free_ls(tmp);
	return (stack);
}

t_swap	ft_radix(t_swap stack, char **tmp, int j, int i)
{
	int	k;

	k = ft_compt_zero(tmp, j);
	if (k > ft_lstrlen(tmp) / 2)
		stack = ft_radix_opti(stack, tmp, j, k);
	else
		stack = ft_radix_base(stack, tmp, j, i);
	while (ft_lstrlen(stack.b) > 0)
		stack = ft_pa(stack);
	tmp = ft_move_up(tmp, j);
	if (ft_check_sort(stack.a) == 0 && j > 0)
		stack = ft_radix(stack, tmp, --j, 0);
	ft_free_ls(tmp);
	return (stack);
}

t_swap	ft_radix_base(t_swap stack, char **tmp, int j, int i)
{
	while (tmp[i])
	{
		if (tmp[i][j] == '0')
			stack = ft_pb(stack);
		else
			stack = ft_ra(stack);
		i++;
	}
	return (stack);
}

t_swap	ft_radix_opti(t_swap stack, char **tmp, int j, int k)
{
	int	compt;
	int	i;

	compt = 0;
	i = 0;
	while (k > 0)
	{
		if (tmp[i][j] == '0')
		{
			stack = ft_pb(stack);
			k--;
		}
		else
		{
			stack = ft_ra(stack);
			compt++;
		}
		i++;
	}
	while (compt > 0)
	{
		stack = ft_rra(stack);
		compt--;
	}
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
