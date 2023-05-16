/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:08:52 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/13 15:08:52 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Possible sorting steps:
3			2			2
1	ra		1	sa		3	rra
2			3			1

1			3
3	rra sa	2	ra sa
2			1
*/

static int	find_largest_num_small(t_dlist *stack)
{
	int	largest_num;

	largest_num = -2147483648;
	while (stack)
	{
		if (stack->content > largest_num)
			largest_num = stack->content;
		stack = stack->next;
	}
	return (largest_num);
}

void	sort_small(t_dlist **stack_a, t_dlist **stack_b)
{
	int		largest_num;

	largest_num = find_largest_num_small(*stack_a);
	if ((*stack_a)->content == largest_num)
		rotate('a', stack_a, stack_b);
	else if ((*stack_a)->next->content == largest_num)
		rev_rotate('a', stack_a, stack_b);
	if (!is_stack_sorted((*stack_a)))
		swap('a', stack_a, stack_b);
}
