/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/19 17:31:20 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_ra(t_swap tab)
{
	if (ft_lstrlen(tab.a) <= 1)
		return (tab);
	if (ft_lstrlen(tab.a) == 2)
		return (ft_sa(tab));
	tab.a = ft_rotate_left(tab.a);
	if (!tab.a)
		ft_error();
	write(1, "ra\n", 3);
	return (tab);
}

t_swap	ft_rb(t_swap tab)
{
	if (ft_lstrlen(tab.b) <= 1)
		return (tab);
	if (ft_lstrlen(tab.b) == 2)
		return (ft_sb(tab));
	tab.b = ft_rotate_left(tab.b);
	if (!tab.b)
		ft_error();
	write(1, "rb\n", 3);
	return (tab);
}

t_swap	ft_rr(t_swap tab)
{
	if (ft_lstrlen(tab.a) <= 1 || ft_lstrlen(tab.b) <= 1)
		return (tab);
	if (ft_lstrlen(tab.a) == 2 && ft_lstrlen(tab.b) == 2)
		return (ft_ss(tab));
	if (ft_lstrlen(tab.a) == 2)
		tab = ft_sa(tab);
	else
	{
		tab.a = ft_rotate_left(tab.a);
		if (!tab.a)
			ft_error();
	}
	if (ft_lstrlen(tab.b) == 2)
		tab = ft_sb(tab);
	else
	{
		tab.b = ft_rotate_left(tab.b);
		if (!tab.b)
			ft_error();
	}
	write(1, "rr\n", 3);
	return (tab);
}

char	**ft_rotate_left(char **ls)
{
	char	**dup;
	char	*tmp;
	int		i;

	dup = (char **)malloc(sizeof(char *) * (ft_lstrlen(ls) + 1));
	if (!dup)
		ft_error();
	i = 0;
	tmp = ls[0];
	while (ls[i + 1])
	{
		dup[i] = ft_strdup(ls[i + 1]);
		if (!dup[i])
			ft_error();
		i++;
	}
	dup[i++] = ft_strdup(tmp);
	dup[i] = 0;
	free(ls);
	return (dup);
}
