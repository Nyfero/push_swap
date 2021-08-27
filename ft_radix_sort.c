/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/27 17:31:49 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_radix_sort(t_swap tab, char **ls)
{
	char	**index;
	char	**tmp;
	int		i;
	int		j;
	int		k;

	index = ft_tab_index(tab, ls);
	if (!index)
		ft_error_free(tab);
	tmp = (char **)malloc(sizeof(char *) * 1);
	tmp[0] = 0;
	j = ft_strlen(index[0]);
	while (ft_check_sort(tab.a) == 0 && j >= 0)
	{
		i = 0;
		j--;
		k = ft_compt_zero(index, j);
		while (k > 1)
		{
			if (index[i][j] == '0')
			{
				tab = ft_pb(tab);
				tmp = ft_push_right(tmp, index[i]);
				index = ft_move_up(index, i);
				i--;
			}
			else
				tab = ft_ra(tab);
			i++;
			k--;
		}
		if (k == 1)
		{
			tab = ft_short_way_a(tab, ft_find_zero(index, j));
			while (index[0][j] != '0')
				index = ft_push_left(index);
		}
		while (ft_lstrlen(tab.b) > 0)
		{
			tab = ft_pa(tab);
			index = ft_push_right(index, tmp[0]);
			tmp = ft_push_left(tmp);
		}
	}
	ft_free_ls(tmp);
	ft_free_ls(index);
	return (tab);
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

	i = 0;
	while (ls[i])
	{
		if (ls[i][j] == '0')
			return (i);
		i++;
	}
	return (-1);
}
