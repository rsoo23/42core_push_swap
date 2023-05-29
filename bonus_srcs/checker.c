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
	if (ac - 1 >= 1 && check_all_digits(ac, av) && check_num_size(av))
	{
		stk_a = create_stk_a(av);
		if (lst_check_dup(stk_a))
		{
			push_swap(ac - 1, &stk_a, &stk_b);
			if (is_index_sorted(stk_a))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
			free_stk(&stk_a);
			free_stk(&stk_b);
			return (0);
		}
	}
	write(2, "Error\n", 6);
	free_stk(&stk_a);
	free_stk(&stk_b);
}

void	push_swap(int size_a, t_dlist **stk_a, t_dlist **stk_b)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	init_info(info, size_a);
	if (is_stk_sorted(*stk_a))
		return ;
	else if (size_a == 2)
		swap('a', stk_a, stk_b);
	else if (size_a == 3)
		sort_small(stk_a, stk_b);
	else if (size_a <= 20)
		sort_medium(stk_a, stk_b, size_a, info);
	else
		sort_big(stk_a, stk_b, size_a, info);
	free(info);
}
