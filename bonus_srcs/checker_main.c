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

int	main(int ac, char **av)
{
	t_dlist	*stk_a;
	t_dlist	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (ac == 3)
	{
		if (check_digits_create_stk(av[1], &stk_a))
		{
			if (is_stk_sorted(stk_a))
			{
				write(1, "OK\n", 3);
				return (0);
			}
			if (move_check_execute(&stk_a, &stk_b, av[2]))
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

int	move_check_execute(t_dlist **stk_a, t_dlist **stk_b, char *move_arr)
{
	char	**action_list;

	action_list = ft_split(move_arr, '\n');
	if (!(*action_list) || !(**action_list))
		return (free_2D_array(action_list, 0));
	else if (check_valid_action_exec(stk_a, stk_b, action_list))
	{
		if (is_stk_sorted(*stk_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		return (free_2D_array(action_list, 1));
	}
	return (free_2D_array(action_list, 0));
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

char	**init_valid_actions(void)
{
	char	**valid_actions;

	valid_actions = malloc(sizeof(char *) * 12);
	valid_actions[0] = ft_strdup("sa");
	valid_actions[1] = ft_strdup("sb");
	valid_actions[2] = ft_strdup("ss");
	valid_actions[3] = ft_strdup("pa");
	valid_actions[4] = ft_strdup("pb");
	valid_actions[5] = ft_strdup("ra");
	valid_actions[6] = ft_strdup("rb");
	valid_actions[7] = ft_strdup("rr");
	valid_actions[8] = ft_strdup("rra");
	valid_actions[9] = ft_strdup("rrb");
	valid_actions[10] = ft_strdup("rrr");
	return (valid_actions);
}

void	execute_action(t_dlist **stk_a, t_dlist **stk_b, int j)
{
	if (j == 0)
		swap_bonus('a', stk_a, stk_b);
	else if (j == 1)
		swap_bonus('b', stk_a, stk_b);
	else if (j == 2)
		swap_bonus('s', stk_a, stk_b);
	else if (j == 3)
		push_bonus('a', stk_a, stk_b);
	else if (j == 4)
		push_bonus('b', stk_a, stk_b);
	else if (j == 5)
		rotate_bonus('a', stk_a, stk_b);
	else if (j == 6)
		rotate_bonus('b', stk_a, stk_b);
	else if (j == 7)
		rotate_bonus('r', stk_a, stk_b);
	else if (j == 8)
		rev_rotate_bonus('a', stk_a, stk_b);
	else if (j == 9)
		rev_rotate_bonus('b', stk_a, stk_b);
	else if (j == 10)
		rev_rotate_bonus('r', stk_a, stk_b);
}
