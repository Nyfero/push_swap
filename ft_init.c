/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/23 13:11:56 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_init_arg(t_swap tab, char **argv)
{
	tab.a = ft_split(argv[1], ' ');
	if (!tab.a)
		ft_error();
	tab.b = (char **)malloc(sizeof(char) * 1);
	tab.b[0] = 0;
	ft_check(tab);
	return (tab);
}

t_swap	ft_init(t_swap tab, int argc, char **argv)
{
	int	i;

	tab.a = (char **)malloc(sizeof(char *) * argc);
	if (!tab.a)
		ft_error();
	i = 0;
	while (i < argc - 1)
	{
		tab.a[i] = ft_strdup(argv[i + 1]);
		if (!tab.a[i])
			ft_error_free(tab);
		i++;
	}
	tab.a[i] = 0;
	tab.b = (char **)malloc(sizeof(char *) * 1);
	tab.b[0] = 0;
	ft_check(tab);
	return (tab);
}

void	ft_check(t_swap tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab.a[i])
	{
		if (ft_atoi(tab.a[i]) > 2147483647 || ft_atoi(tab.a[i]) < -2147483648)
			ft_error_free(tab);
		j = 0;
		while (tab.a[i][j])
		{
			if (ft_isalpha(tab.a[i][j]))
				ft_error_free(tab);
			j++;
		}
		j = i + 1;
		while (tab.a[j])
		{
			if (ft_atoi(tab.a[i]) == ft_atoi(tab.a[j]))
				ft_error_free(tab);
			j++;
		}
		i++;
	}
	return ;
}

char	**ft_duplicate(char **ls)
{
	char	**dup;
	int		i;

	dup = (char **)malloc(sizeof(char *) * (ft_lstrlen(ls) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (ls[i])
	{
		dup[i] = ft_strdup(ls[i]);
		if (!dup[i])
			return (NULL);
		i++;
	}
	dup[i] = 0;
	return (dup);
}
