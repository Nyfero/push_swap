/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/17 14:20:13 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_error(int type)
{
	write(2, "Error", 5);
	if (type == 1)
		write(2, " some arguments aren’t integers", 31);
	else if (type == 2)
		write(2, " some arguments are bigger than an integer", 42);
	else if (type == 3)
		write(2, " some arguments are duplicates", 30);
	else if (type == 4)
		write(2, " initialisation", 15);
	write(2, "\n", 1);
	exit(0);
}
