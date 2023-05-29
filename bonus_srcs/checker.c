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
		if (check_all_digits(ac - 1, av) && check_num_size_bonus(av))
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
	action_list = ft_split(av[pos], '\n');
	if (!(*action_list) || !(**action_list))
		return (free_action_list(action_list, 0));
	else if (check_valid_action_exec(stk_a, stk_b, action_list))
	{
		if (is_index_sorted(*stk_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		return (free_action_list(action_list, 1));
	}
	return (free_action_list(action_list, 0));
}

int	check_valid_action_exec(t_dlist **stk_a, t_dlist **stk_b, char **a_lst)
{
	int		i;
	int		j;
	char	**valid_actions;

	i = -1;
	valid_actions = init_valid_actions();
	while (a_lst[++i])
	{
		j = -1;
		while (++j < 11)
		{
			if (!ft_strncmp(a_lst[i], valid_actions[j], ft_strlen(a_lst[i])))
			{
				execute_action(stk_a, stk_b, j);
				break ;
			}
		}
		if (j == 11)
			return (free_v_actions(valid_actions, 0));
	}
	return (free_v_actions(valid_actions, 1));
}
