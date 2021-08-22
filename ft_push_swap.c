/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/22 12:35:16 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	tab;
	int i;

	if (argc == 1)
		return (0);
	tab.a = NULL;
	tab.b = NULL;
	if (argc == 2)
		tab = ft_init_arg(tab, argv);
	else
		tab = ft_init(tab, argc, argv);
	if (ft_check_sort(tab.a) == 1)
/*	{
		i = -1;
		while (tab.a[++i])
			printf("tab.a[%d]:%s\n", i, tab.a[i]);
		write(1, "sorted\n", 7);*/
		return (0);
	//}
	tab = ft_sort(tab);
	i = -1;
	while (tab.a[++i])
		printf("tab.a[%d]:%s\n", i, tab.a[i]);
	if (ft_check_sort(tab.a) == 1)
	/*{
		write(1, "sorted\n", 7);*/
		return (0);
/*	}
	else
	{
		write(1, "error\n", 6);
		return (1);
	}*/
}
