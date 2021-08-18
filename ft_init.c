/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/18 14:19:19 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_init_arg(t_swap tab, char **argv)
{
	tab.a = ft_split(argv[1], ' ');
	if (!tab.a)
		ft_error();
	ft_check(tab.a);
	tab.b = (char **)malloc(sizeof(char) * 1);
	tab.b[0] = 0;
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
			ft_error();
		i++;
	}
	tab.a[i] = 0;
	ft_check(tab.a);
	tab.b = (char **)malloc(sizeof(char *) * 1);
	tab.b[0] = 0;
	return (tab);
}

void	ft_check(char **ls)
{
	int	i;
	int	j;

	i = 0;
	while (ls[i])
	{
		if (ft_atoi(ls[i]) > 2147483647 || ft_atoi(ls[i]) < -2147483648)
			ft_error();
		j = 0;
		while (ls[i][j])
		{
			if (ft_isalpha(ls[i][j]))
				ft_error();
			j++;
		}
		j = i + 1;
		while (ls[j])
		{
			if (ft_atoi(ls[i]) == ft_atoi(ls[j]))
				ft_error();
			j++;
		}
		i++;
	}
	return ;
}
