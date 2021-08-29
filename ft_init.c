/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/29 17:16:36 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_init_arg(t_swap stack, char **argv)
{
	stack.a = ft_split(argv[1], ' ');
	if (!stack.a)
		ft_error();
	stack.b = (char **)malloc(sizeof(char) * 1);
	stack.b[0] = 0;
	ft_check_arg(stack);
	return (stack);
}

t_swap	ft_init(t_swap stack, int argc, char **argv)
{
	int	i;

	stack.a = (char **)malloc(sizeof(char *) * argc);
	if (!stack.a)
		ft_error();
	i = 0;
	while (i < argc - 1)
	{
		stack.a[i] = ft_strdup(argv[i + 1]);
		if (!stack.a[i])
			ft_error_free(stack);
		i++;
	}
	stack.a[i] = 0;
	stack.b = (char **)malloc(sizeof(char *) * 1);
	stack.b[0] = 0;
	ft_check(stack);
	return (stack);
}

void	ft_check_arg(t_swap stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack.a[i])
	{
		if (ft_atoi(stack.a[i]) > 2147483647 || ft_atoi(stack.a[i]) < -2147483648)
			ft_error_free(stack);
		j = 0;
		while (stack.a[i][j])
		{
			if (ft_isalpha(stack.a[i][j]))
				ft_error_free(stack);
			j++;
		}
		j = i + 1;
		while (stack.a[j])
		{
			if (ft_atoi(stack.a[i]) == ft_atoi(stack.a[j]))
				ft_error_free(stack);
			j++;
		}
		i++;
	}
	return ;
}

char	**ft_duplicate_ls(char **ls)
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
