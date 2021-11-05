/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/11/04 15:25:35 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	stack;

	if (argc == 1)
		return (0);
	stack.a = NULL;
	stack.b = NULL;
	stack = ft_init(stack, argc, argv);
	if (ft_check_sort(stack.a) == 1)
	{
		ft_free_ls(stack.a);
		ft_free_ls(stack.b);
		return (0);
	}
	stack = ft_sort_stack(stack);
	ft_free_ls(stack.a);
	ft_free_ls(stack.b);
	return (0);
}
