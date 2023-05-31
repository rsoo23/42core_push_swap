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
	if (ac == 2)
	{
		if (check_digits_create_stk(av[1], &stk_a))
		{
			if (move_check_execute(&stk_a, &stk_b))
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

int	move_check_execute(t_dlist **stk_a, t_dlist **stk_b)
{
	char	*input_move;
	int		move_index;

	input_move = get_next_line(0);
	move_index = 0;
	while (input_move != NULL)
	{
		move_index = check_valid_action(input_move);
		free(input_move);
		if (move_index == -1)
			return (0);
		execute_action(stk_a, stk_b, move_index);
		input_move = get_next_line(0);
	}
	if (is_stk_sorted(*stk_a) && !(*stk_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(input_move);
	return (1);
}

int	check_valid_action(char *move)
{
	int		i;
	char	**valid_actions;

	i = -1;
	valid_actions = init_valid_actions();
	while (++i < 11)
		if (!ft_strncmp(move, valid_actions[i], ft_strlen(move)))
			return (free_v_actions(valid_actions, i));
	return (free_v_actions(valid_actions, -1));
}

char	**init_valid_actions(void)
{
	char	**valid_actions;

	valid_actions = malloc(sizeof(char *) * 11);
	valid_actions[0] = ft_strdup("sa\n");
	valid_actions[1] = ft_strdup("sb\n");
	valid_actions[2] = ft_strdup("ss\n");
	valid_actions[3] = ft_strdup("pa\n");
	valid_actions[4] = ft_strdup("pb\n");
	valid_actions[5] = ft_strdup("ra\n");
	valid_actions[6] = ft_strdup("rb\n");
	valid_actions[7] = ft_strdup("rr\n");
	valid_actions[8] = ft_strdup("rra\n");
	valid_actions[9] = ft_strdup("rrb\n");
	valid_actions[10] = ft_strdup("rrr\n");
	return (valid_actions);
}

void	execute_action(t_dlist **stk_a, t_dlist **stk_b, int i)
{
	if (i == 0)
		swap_bonus('a', stk_a, stk_b);
	else if (i == 1)
		swap_bonus('b', stk_a, stk_b);
	else if (i == 2)
		swap_bonus('s', stk_a, stk_b);
	else if (i == 3)
		push_bonus('a', stk_a, stk_b);
	else if (i == 4)
		push_bonus('b', stk_a, stk_b);
	else if (i == 5)
		rotate_bonus('a', stk_a, stk_b);
	else if (i == 6)
		rotate_bonus('b', stk_a, stk_b);
	else if (i == 7)
		rotate_bonus('r', stk_a, stk_b);
	else if (i == 8)
		rev_rotate_bonus('a', stk_a, stk_b);
	else if (i == 9)
		rev_rotate_bonus('b', stk_a, stk_b);
	else if (i == 10)
		rev_rotate_bonus('r', stk_a, stk_b);
}
