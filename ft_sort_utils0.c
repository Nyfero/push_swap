/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/18 15:49:44 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_sort(char **ls)
{
	int	i;
	int	min;

	i = 1;
	min = ft_atoi(ls[0]);
	while (ls[i])
	{
		if (min > ft_atoi(ls[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_revert_sort(char **ls)
{
	int	i;
	int	max;

	i = 1;
	max = ft_atoi(ls[0]);
	while (ls[i])
	{
		if (max < ft_atoi(ls[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_smaller(char **ls)
{
	int	i;
	int	compt;
	int	min;

	i = 1;
	compt = 0;
	min = ft_atoi(ls[0]);
	while (ls[i])
	{
		if (min > ft_atoi(ls[i]))
		{
			min = ft_atoi(ls[i]);
			compt = i;
		}
		i++;
	}
	return (compt);
}

int	ft_find_bigger(char **ls)
{
	int	i;
	int	compt;
	int	max;

	i = 1;
	compt = 0;
	max = ft_atoi(ls[0]);
	while (ls[i])
	{
		if (max < ft_atoi(ls[i]))
		{
			max = ft_atoi(ls[i]);
			compt = i;
		}
		i++;
	}
	return (compt);
}
/*
t_swap	ft_sort_3(t_swap tab)
{

}
*/
