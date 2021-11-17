/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/11/17 15:36:57 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap_bonus.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_error_free(t_swap stack)
{
	ft_free_ls(stack.a);
	ft_free_ls(stack.b);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_error_free_read(t_swap stack, char *str)
{
	free(str);
	ft_free_ls(stack.a);
	ft_free_ls(stack.b);
	write(2, "Error\n", 6);
	exit(1);
}
