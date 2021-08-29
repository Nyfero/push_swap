/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/29 17:13:18 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_sa(t_swap stack)
{
	char	*tmp;

	if (ft_lstrlen(stack.a) <= 1)
		return (stack);
	tmp = stack.a[0];
	stack.a[0] = stack.a[1];
	stack.a[1] = tmp;
	write(1, "sa\n", 3);
	return (stack);
}

t_swap	ft_sb(t_swap stack)
{
	char	*tmp;

	if (ft_lstrlen(stack.b) <= 1)
		return (stack);
	tmp = stack.b[0];
	stack.b[0] = stack.b[1];
	stack.b[1] = tmp;
	write(1, "sb\n", 3);
	return (stack);
}

t_swap	ft_ss(t_swap stack)
{
	char	*tmp;

	if (ft_lstrlen(stack.a) <= 1 || ft_lstrlen(stack.b) <= 1)
		return (stack);
	tmp = stack.a[0];
	stack.a[0] = stack.a[1];
	stack.a[1] = tmp;
	tmp = stack.b[0];
	stack.b[0] = stack.b[1];
	stack.b[1] = tmp;
	write(1, "ss\n", 3);
	return (stack);
}
