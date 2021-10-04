/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/10/04 12:13:20 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_swap	ft_quick_sort(t_swap stack, char **ls)
{
	char	**tmp;
	int		i = -1;

	tmp = ft_create_dup_index(stack, ls);
	ft_free_ls(ls);
	while (tmp[++i])
		printf("tmp[%d]:%s\n", i, tmp[i]);
	ft_free_ls(tmp);
	return (stack);
}

char	**ft_create_dup_index(t_swap stack, char **ls)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(char *) * (ft_lstrlen(ls) + 1));
	if (!tmp)
		return NULL;
	i = -1;
	while (ls[++i])
		tmp[i] = ft_itoa(ft_index(stack.a[i], ls));
	tmp[i] = 0;
	ft_free_ls(ls);
	return (tmp);
}