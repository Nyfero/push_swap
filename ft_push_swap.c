/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/18 16:23:56 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	tab;

	if (argc == 1)
		return (0);
	tab.a = NULL;
	tab.b = NULL;
	if (argc == 2)
		tab = ft_init_arg(tab, argv);
	else
		tab = ft_init(tab, argc, argv);
	if (ft_check_sort(tab.a) == 1)
		return (0);
	tab = ft_magic_sort(tab);
	int i = -1;
	while (tab.a[++i])
		printf("tab.a[%d]:%s\n", i, tab.a[i]);
	return (0);
}
