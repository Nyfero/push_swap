/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/17 14:20:45 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_init_arg(t_swap tab, char **argv)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = ft_split(argv[1], ' ');
	tab.a = (char **)malloc(sizeof(char) * (ft_lstrlen(tmp) + 1));
	if (!tab.a)
		ft_error(4);
	i = 0;
	while (tmp[i])
	{
		j = 0;
		tab.a[i] = (char *)malloc(sizeof(char) * (ft_strlen(tmp[i]) + 1));
		if (!tab.a[i])
			ft_error(4);
		while (tmp[i][j])
		{
			tab.a[i][j] = tmp[i][j];
			j++;
		}
		tab.a[i][j] = 0;
		i++;
	}
	tab.a[i] = 0;
	if (ft_check_dbl(tab.a) == 1)
		ft_error(3);
	tab.b = (char **)malloc(sizeof(char) * 1);
	tab.b[0] = 0;
	return (tab);
}

t_swap	ft_init(t_swap tab, int argc, char **argv)
{
	int	i;
	int	j;

	tab.a = (char **)malloc(sizeof(char) * (ft_lstrlen(argv)));
	if (!tab.a)
		ft_error(4);
	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		tab.a[i] = (char *)malloc(sizeof(char) * (ft_strlen(argv[i + 1]) + 1));
		if (!tab.a[i])
			ft_error(4);
		while (argv[i + 1][j])
		{
			tab.a[i][j] = argv[i + 1][j];
			j++;
		}
		tab.a[i][j] = 0;
		i++;
	}
	tab.a[i] = 0;
	if (ft_check_dbl(tab.a) == 1)
		ft_error(3);
	tab.b = (char **)malloc(sizeof(char) * 1);
	tab.b[0] = 0;
	return (tab);
}

int	ft_check_dbl(char **ls)
{
	int	i;
	int	j;

	i = 0;
	while (ls[i])
	{
		j = i + 1;
		while (ls[j])
		{
			if (ft_atoi(ls[i]) == ft_atoi(ls[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
