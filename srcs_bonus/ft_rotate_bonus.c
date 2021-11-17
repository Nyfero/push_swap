/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/11/04 15:15:27 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap_bonus.h"

t_swap	ft_ra(t_swap stack)
{
	if (ft_lstrlen(stack.a) <= 1)
		return (stack);
	if (ft_lstrlen(stack.a) == 2)
		return (ft_sa(stack));
	stack.a = ft_rotate_left(stack.a);
	if (!stack.a)
		ft_error_free(stack);
	return (stack);
}

t_swap	ft_rb(t_swap stack)
{
	if (ft_lstrlen(stack.b) <= 1)
		return (stack);
	if (ft_lstrlen(stack.b) == 2)
		return (ft_sb(stack));
	stack.b = ft_rotate_left(stack.b);
	if (!stack.b)
		ft_error_free(stack);
	return (stack);
}

t_swap	ft_rr(t_swap stack)
{
	if (ft_lstrlen(stack.a) <= 1 || ft_lstrlen(stack.b) <= 1)
		return (stack);
	if (ft_lstrlen(stack.a) == 2 && ft_lstrlen(stack.b) == 2)
		return (ft_ss(stack));
	if (ft_lstrlen(stack.a) == 2)
		stack = ft_sa(stack);
	else
	{
		stack.a = ft_rotate_left(stack.a);
		if (!stack.a)
			ft_error_free(stack);
	}
	if (ft_lstrlen(stack.b) == 2)
		stack = ft_sb(stack);
	else
	{
		stack.b = ft_rotate_left(stack.b);
		if (!stack.b)
			ft_error_free(stack);
	}
	return (stack);
}

char	**ft_rotate_left(char **ls)
{
	char	**dup;
	char	*tmp;
	int		i;

	dup = (char **)malloc(sizeof(char *) * (ft_lstrlen(ls) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	tmp = ls[0];
	while (ls[i + 1])
	{
		dup[i] = ft_strdup(ls[i + 1]);
		if (!dup[i])
			return (NULL);
		i++;
	}
	dup[i++] = ft_strdup(tmp);
	dup[i] = 0;
	ft_free_ls(ls);
	return (dup);
}
