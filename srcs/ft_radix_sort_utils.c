/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/11/23 10:30:01 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

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

char	**ft_stack_index(t_swap stack, char **ls)
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
		dup[i] = ft_dec_to_bin_sized(ft_index(stack.a[i], ls), tmp);
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

// radix pour une tab de char of char sans restriction
char	**ft_move_up(char **ls, int j)
{
	int		i;
	int		k;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * (ft_lstrlen(ls) + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	k = 0;
	while (ls[i])
	{
		if (ls[i][j] == '0')
			tmp[k++] = ft_strdup(ls[i]);
		i++;
	}
	i = 0;
	while (ls[i])
	{
		if (ls[i][j] != '0')
			tmp[k++] = ft_strdup(ls[i]);
		i++;
	}
	tmp[k] = 0;
	return (tmp);
}
