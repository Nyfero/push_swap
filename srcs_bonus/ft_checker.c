/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:13:18 by gsap              #+#    #+#             */
/*   Updated: 2021/11/17 15:36:31 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_swap	stack;

	if (argc == 1)
		return (0);
	stack.a = NULL;
	stack.b = NULL;
	stack = ft_init(stack, argc, argv);
	ft_read_output(stack);
	return (0);
}

void ft_read_output(t_swap stack)
{
  char  *tmp;
	int		len_a;

	len_a = ft_lstrlen(stack.a);
  tmp = get_next_line(0);
  while ((ft_check_sort(stack.a) != 1 && ft_lstrlen(stack.a) != len_a) || tmp != NULL)
  {
    stack = ft_choose_action(tmp, stack);
		printf("len_a = %d\nft_lstrlen = %d\nft_check_sort = %d\n", len_a, ft_lstrlen(stack.a), ft_check_sort(stack.a));
		ft_display_stack(stack);
    free(tmp);
		if (ft_check_sort(stack.a) == 1 && ft_lstrlen(stack.a) == len_a)
		{
			write(1, "OK\n", 3);
			ft_free_ls(stack.a);
			ft_free_ls(stack.b);
			return ;
		}
    tmp = get_next_line(0);
  }
	write(1, "KO\n", 3);
	free(tmp);
	ft_free_ls(stack.a);
	ft_free_ls(stack.b);
}

t_swap ft_choose_action(char *str, t_swap stack)
{
  if (ft_strncmp(str, "pa", 3) == 0)
    stack = ft_pa(stack);
  else if (ft_strncmp(str, "pb", 3) == 0)
    stack = ft_pb(stack);
  else if (ft_strncmp(str, "ra", 3) == 0)
    stack = ft_ra(stack);
  else if (ft_strncmp(str, "rb", 3) == 0)
    stack = ft_rb(stack);
  else if (ft_strncmp(str, "rr", 3) == 0)
    stack = ft_rr(stack);
  else if (ft_strncmp(str, "sa", 3) == 0)
    stack = ft_sa(stack);
  else if (ft_strncmp(str, "sb", 3) == 0)
    stack = ft_sb(stack);
  else if (ft_strncmp(str, "ss", 3) == 0)
    stack = ft_ss(stack);
  else if (ft_strncmp(str, "rra", 4) == 0)
    stack = ft_rra(stack);
  else if (ft_strncmp(str, "rrb", 4) == 0)
    stack = ft_rrb(stack);
  else if (ft_strncmp(str, "rrr", 4) == 0)
    stack = ft_rrr(stack);
	else
		ft_error_free_read(stack, str);
	return (stack);
}

int	ft_check_sort(char **ls)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (ls[i])
	{
		min = ft_atoi(ls[i]);
		j = i + 1;
		while (ls[j])
		{
			if (min > ft_atoi(ls[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
