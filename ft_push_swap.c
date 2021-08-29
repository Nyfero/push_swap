/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/29 17:25:41 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	stack;

	if (argc == 1)
		return (0);
	stack.a = NULL;
	stack.b = NULL;
	if (ft_check_sort(argv) == 1)
		return (0);
	if (argc == 2)
		stack = ft_init_arg(stack, argv);
	else
		stack = ft_init(stack, argc, argv);
	stack = ft_sort_stack(stack);
	if (ft_check_sort(stack.a) == 1)
	{
		write(1, "oui\n", 4);
		ft_free_ls(stack.a);
		ft_free_ls(stack.b);
		return (0);
	}
	else
	{
		write(1, "non\n", 4);
		ft_free_ls(stack.a);
		ft_free_ls(stack.b);
		return (1);
	}
}
