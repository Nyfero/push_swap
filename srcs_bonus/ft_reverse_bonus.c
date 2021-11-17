/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/11/04 15:15:24 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap_bonus.h"

t_swap	ft_rra(t_swap stack)
{
	if (ft_lstrlen(stack.a) <= 1)
		return (stack);
	if (ft_lstrlen(stack.a) == 2)
		return (ft_sa(stack));
	stack.a = ft_rotate_right(stack.a);
	if (!stack.a)
		ft_error_free(stack);
	return (stack);
}

t_swap	ft_rrb(t_swap stack)
{
	if (ft_lstrlen(stack.b) <= 1)
		return (stack);
	if (ft_lstrlen(stack.b) == 2)
		return (ft_sb(stack));
	stack.b = ft_rotate_right(stack.b);
	if (!stack.b)
		ft_error_free(stack);
	return (stack);
}

t_swap	ft_rrr(t_swap stack)
{
	if (ft_lstrlen(stack.a) <= 1 || ft_lstrlen(stack.b) <= 1)
		return (stack);
	if (ft_lstrlen(stack.a) == 2 && ft_lstrlen(stack.b) == 2)
		return (ft_ss(stack));
	if (ft_lstrlen(stack.a) == 2)
		stack = ft_sa(stack);
	else
	{
		stack.a = ft_rotate_right(stack.a);
		if (!stack.a)
			ft_error_free(stack);
	}
	if (ft_lstrlen(stack.b) == 2)
		stack = ft_sb(stack);
	else
	{
		stack.b = ft_rotate_right(stack.b);
		if (!stack.b)
			ft_error_free(stack);
	}
	return (stack);
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
	ft_free_ls(ls);
	return (dup);
}
