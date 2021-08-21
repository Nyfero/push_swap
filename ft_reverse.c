/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/21 16:28:00 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_rra(t_swap tab)
{
	if (ft_lstrlen(tab.a) <= 1)
		return (tab);
	if (ft_lstrlen(tab.a) == 2)
		return (ft_sa(tab));
	tab.a = ft_rotate_right(tab.a);
	if (!tab.a)
		ft_error_free(tab);
	write(1, "rra\n", 4);
	return (tab);
}

t_swap	ft_rrb(t_swap tab)
{
	if (ft_lstrlen(tab.b) <= 1)
		return (tab);
	if (ft_lstrlen(tab.b) == 2)
		return (ft_sb(tab));
	tab.b = ft_rotate_right(tab.b);
	if (!tab.b)
		ft_error_free(tab);
	write(1, "rrb\n", 4);
	return (tab);
}

t_swap	ft_rrr(t_swap tab)
{
	if (ft_lstrlen(tab.a) <= 1 || ft_lstrlen(tab.b) <= 1)
		return (tab);
	if (ft_lstrlen(tab.a) == 2 && ft_lstrlen(tab.b) == 2)
		return (ft_ss(tab));
	if (ft_lstrlen(tab.a) == 2)
		tab = ft_sa(tab);
	else
	{
		tab.a = ft_rotate_right(tab.a);
		if (!tab.a)
			ft_error_free(tab);
	}
	if (ft_lstrlen(tab.b) == 2)
		tab = ft_sb(tab);
	else
	{
		tab.b = ft_rotate_right(tab.b);
		if (!tab.b)
			ft_error_free(tab);
	}
	write(1, "rrr\n", 4);
	return (tab);
}

char	**ft_rotate_right(char **ls)
{
	char	**dup;
	char	*tmp;
	int		i;

	i = ft_lstrlen(ls);
	dup = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (NULL);
	dup[i--] = 0;
	tmp = ls[i];
	while (i > 0)
	{
		dup[i] = ft_strdup(ls[i - 1]);
		if (!dup[i])
			return (NULL);
		i--;
	}
	dup[i--] = ft_strdup(tmp);
	free(ls);
	return (dup);
}
