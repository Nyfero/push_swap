/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/18 14:23:55 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	tab;
	int		i;

	if (argc == 1)
		return (0);
	tab.a = NULL;
	tab.b = NULL;
	if (argc == 2)
		tab = ft_init_arg(tab, argv);
	else
		tab = ft_init(tab, argc, argv);
	i = 0;
	while (tab.a[i])
		printf("tab.a :%s\n", tab.a[i++]);
	i = 0;
	while (tab.b[i])
		printf("tab.b :%s\n", tab.b[i++]);
	return (0);
}
