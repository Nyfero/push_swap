/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/12/01 14:56:10 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

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

void	ft_error_chunk(t_swap stack, char **ls)
{
	ft_free_ls(stack.a);
	ft_free_ls(stack.b);
	ft_free_ls(ls);
	write(2, "Error\n", 6);
	exit(1);
}
