/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/08/19 17:28:28 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_sa(t_swap tab)
{
	char	*tmp;

	if (ft_lstrlen(tab.a) <= 1)
		return (tab);
	tmp = tab.a[0];
	tab.a[0] = tab.a[1];
	tab.a[1] = tmp;
	write(1, "sa\n", 3);
	return (tab);
}

t_swap	ft_sb(t_swap tab)
{
	char	*tmp;

	if (ft_lstrlen(tab.b) <= 1)
		return (tab);
	tmp = tab.b[0];
	tab.b[0] = tab.b[1];
	tab.b[1] = tmp;
	write(1, "sb\n", 3);
	return (tab);
}

t_swap	ft_ss(t_swap tab)
{
	char	*tmp;

	if (ft_lstrlen(tab.a) <= 1 || ft_lstrlen(tab.b) <= 1)
		return (tab);
	tmp = tab.a[0];
	tab.a[0] = tab.a[1];
	tab.a[1] = tmp;
	tmp = tab.b[0];
	tab.b[0] = tab.b[1];
	tab.b[1] = tmp;
	write(1, "ss\n", 3);
	return (tab);
}
