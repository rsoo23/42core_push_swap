/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:05:58 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/19 12:05:58 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

#include <stdio.h>

int	main(int ac, char **av)
{
	t_dlist	*stk_a;
	t_dlist	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (ac - 1 >= 1)
	{
		if (check_all_digits_bonus(ac, av) && check_num_size_bonus(av))
		{
			stk_a = create_stk_a_bonus(av);
			if (lst_check_dup(stk_a) && move_check_execute(&stk_a, &stk_b, av))
			{
				free_stk(&stk_a);
				free_stk(&stk_b);
				return (0);
			}
		}
		write(2, "Error\n", 6);
	}
	free_stk(&stk_a);
	free_stk(&stk_b);
}

int	move_check_execute(t_dlist **stk_a, t_dlist **stk_b, char **av)
{
	int		pos;
	char	**action_list;

	pos = 0;
	while (av[pos + 1])
		pos++;
	action_list = ft_split(av[pos], ' ');
	if (check_valid_action_exec(stk_a, stk_b, action_list))
	{
		if (is_stk_sorted(*stk_a))
			write(1, "OK", 2);
		else
			write(1, "KO", 2);
		return (1);
	}
	return (0);
}
