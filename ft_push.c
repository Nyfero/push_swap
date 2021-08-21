/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/19 13:19:23 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_pa(t_swap tab)
{
	if (!tab.b)
		return (tab);
	tab.a = ft_push_right(tab.a, tab.b[0]);
	if (!tab.a)
		ft_error();
	if (!tab.b)
		tab.b[0] = 0;
	else
	{
		tab.b = ft_push_left(tab.b);
		if (!tab.b)
			ft_error();
	}
	write(1, "pa\n", 3);
	return (tab);
}

t_swap	ft_pb(t_swap tab)
{
	if (!tab.a)
		return (tab);
	tab.b = ft_push_right(tab.b, tab.a[0]);
	if (!tab.b)
		ft_error();
	if (!tab.a)
		tab.a[0] = 0;
	else
	{
		tab.a = ft_push_left(tab.a);
		if (!tab.a)
			ft_error();
	}
	write(1, "pb\n", 3);
	return (tab);
}

char	**ft_push_left(char **ls)
{
	char	**dup;
	int		i;

	dup = (char **)malloc(sizeof(char *) * ft_lstrlen(ls));
	if (!dup)
		ft_error();
	i = 0;
	while (ls[i + 1])
	{
		dup[i] = ft_strdup(ls[i + 1]);
		if (!dup[i])
			ft_error();
		i++;
	}
	free(ls);
	dup[i] = 0;
	return (dup);
}

char	**ft_push_right(char **ls, char *new)
{
	char	**dup;
	int		i;

	dup = (char **)malloc(sizeof(char *) * (ft_lstrlen(ls) + 2));
	if (!dup)
		ft_error();
	dup[0] = ft_strdup(new);
	i = 1;
	while (ls[i - 1])
	{
		dup[i] = ft_strdup(ls[i - 1]);
		if (!dup[i])
			ft_error();
		i++;
	}
	dup[i] = 0;
	free(ls);
	return (dup);
}
