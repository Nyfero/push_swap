/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/11/04 15:14:55 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap_bonus.h"

void	ft_display_stack(t_swap stack)
{
	int	i;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = ft_lstrlen(stack.a);
	size_b = ft_lstrlen(stack.b);
	while (i < size_a || i < size_b)
	{
		if (i < size_a && i < size_b)
			printf("%d : %s    %s\n", i, stack.a[i], stack.b[i]);
		else if (i < size_a && i >= size_b)
			printf("%d : %s    |\n", i, stack.a[i]);
		else if (i >= size_a && i < size_b)
			printf("%d : |    %s\n", i, stack.b[i]);
		i++;
	}
	printf("--- a -- b ---\n");
}
