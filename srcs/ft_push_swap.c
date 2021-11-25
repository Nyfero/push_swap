/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/11/23 12:37:33 by gsap             ###   ########.fr       */
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
	if (ft_check_space(argv) == 1)
		ft_error();
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

int	ft_check_space(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == ' ')
			return (1);
		i++;
	}
	return (0);
}
