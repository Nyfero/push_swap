/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/27 17:40:33 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	*ft_dec_to_bin(int n)
{
	char	*bin;
	char	*base;
	int		i;

	base = "01";
	bin = (char *)malloc(sizeof(char) * 33);
	if (!bin)
		return (NULL);
	bin[32] = 0;
	i = 31;
	while (i >= 0)
	{
		bin[i] = base[(n % 2)];
		n = (n / 2);
		i--;
	}
	return (bin);
}

char	*ft_dec_to_bin_sized(int n, int size)
{
	char	*bin;
	char	*base;
	int		i;

	base = "01";
	bin = (char *)malloc(sizeof(char) * (size + 1));
	if (!bin)
		return (NULL);
	bin[size] = 0;
	i = size - 1;
	while (i >= 0)
	{
		bin[i] = base[(n % 2)];
		n = (n / 2);
		i--;
	}
	return (bin);
}

char	**ft_tab_index(t_swap tab, char **ls)
{
	char	**dup;
	int		i;
	int		tmp;

	tmp = ft_find_size(ls);
	dup = (char **)malloc(sizeof(char *) * (ft_lstrlen(ls) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (ls[i])
	{
		dup[i] = ft_dec_to_bin_sized(ft_index(tab.a[i], ls), tmp);
		if (!dup[i])
			return (NULL);
		i++;
	}
	ft_free_ls(ls);
	dup[i] = 0;
	return (dup);
}

int	ft_find_size(char **ls)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_dec_to_bin(ft_atoi(ls[ft_lstrlen(ls) - 1]));
	while (tmp[i])
	{
		if (tmp[i] == '1')
		{
			free(tmp);
			return (32 - i);
		}
		i++;
	}
	free(tmp);
	return (-1);
}

char	**ft_move_up(char **ls, int i)
{
	char	**dup;
	int		j;

	dup = (char **)malloc(sizeof(char *) * ft_lstrlen(ls));
	if (!dup)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dup[j] = ft_strdup(ls[j]);
		if (!dup[j])
			return (NULL);
		j++;
	}
	while (ls[i + 1])
	{
		dup[i] = ft_strdup(ls[i + 1]);
		if (!dup[i])
			return (NULL);
		i++;
	}
	ft_free_ls(ls);
	dup[i] = 0;
	return (dup);
}
