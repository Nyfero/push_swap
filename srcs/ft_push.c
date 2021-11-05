/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/11/04 15:15:10 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

t_swap	ft_pa(t_swap stack)
{
	if (!stack.b)
		return (stack);
	stack.a = ft_push_right(stack.a, stack.b[0]);
	if (!stack.a)
		ft_error_free(stack);
	if (!stack.b)
		stack.b[0] = 0;
	else
	{
		stack.b = ft_push_left(stack.b);
		if (!stack.b)
			ft_error_free(stack);
	}
	write(1, "pa\n", 3);
	return (stack);
}

t_swap	ft_pb(t_swap stack)
{
	if (!stack.a)
		return (stack);
	stack.b = ft_push_right(stack.b, stack.a[0]);
	if (!stack.b)
		ft_error_free(stack);
	if (!stack.a)
		stack.a[0] = 0;
	else
	{
		stack.a = ft_push_left(stack.a);
		if (!stack.a)
			ft_error_free(stack);
	}
	write(1, "pb\n", 3);
	return (stack);
}

char	**ft_push_left(char **ls)
{
	char	**dup;
	int		i;

	dup = (char **)malloc(sizeof(char *) * ft_lstrlen(ls));
	if (!dup)
		return (NULL);
	i = 0;
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

char	**ft_push_right(char **ls, char *new)
{
	char	**dup;
	int		i;

	dup = (char **)malloc(sizeof(char *) * (ft_lstrlen(ls) + 2));
	if (!dup)
		return (NULL);
	dup[0] = ft_strdup(new);
	i = 1;
	while (ls[i - 1])
	{
		dup[i] = ft_strdup(ls[i - 1]);
		if (!dup[i])
			return (NULL);
		i++;
	}
	dup[i] = 0;
	ft_free_ls(ls);
	return (dup);
}
