/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/27 17:35:48 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_error_free(t_swap tab)
{
	ft_free_ls(tab.a);
	ft_free_ls(tab.b);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_ls(char **ls)
{
	int	i;

	i = 0;
	while (ls[i])
	{
		free(ls[i]);
		i++;
	}
	free(ls);
	return ;
}
