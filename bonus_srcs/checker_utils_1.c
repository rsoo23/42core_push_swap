/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:07:10 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/29 16:22:46 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	check_all_digits_bonus(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac - 1)
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && av[i][0] == '-')
				j++;
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
	}
	return (1);
}

int	check_num_size_bonus(char **av)
{
	int		av_count;
	long	num;

	av_count = 1;
	num = 0;
	while (av[av_count + 1])
	{
		num = ft_atoi_long(av[av_count]);
		if (num > 2147483647 || num < -2147483648)
			return (0);
		av_count++;
	}
	return (1);
}

char	**init_valid_actions(void)
{
	char	**valid_actions;

	valid_actions = malloc(sizeof(char *) * 11);
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

static void	execute_action(t_dlist **stk_a, t_dlist **stk_b, int j)
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

int	check_valid_action_exec(t_dlist **stk_a, t_dlist **stk_b, char **a_lst)
{
	int		i;
	int		j;
	char	**valid_actions;

	if (!(*a_lst) || !(**a_lst))
		return (0);
	i = 0;
	valid_actions = init_valid_actions();
	while (a_lst[i])
	{
		j = 0;
		while (j < 11)
		{
			if (!ft_strncmp(a_lst[i], valid_actions[j], ft_strlen(a_lst[i])))
			{
				execute_action(stk_a, stk_b, j);
				break ;
			}
			j++;
		}
		if (j == 11)
			return (0);
		i++;
	}
	return (1);
}
