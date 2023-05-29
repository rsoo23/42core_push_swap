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

static int	find_largest_num_small(t_dlist *stk)
{
	int	largest_num;

	largest_num = -2147483648;
	while (stk)
	{
		if (stk->content > largest_num)
			largest_num = stk->content;
		stk = stk->next;
	}
	return (largest_num);
}

void	sort_small(t_dlist **stk_a, t_dlist **stk_b)
{
	int		largest_num;

	largest_num = find_largest_num_small(*stk_a);
	if ((*stk_a)->content == largest_num)
		rotate('a', stk_a, stk_b);
	else if ((*stk_a)->next->content == largest_num)
		rev_rotate('a', stk_a, stk_b);
	if (!is_stk_sorted((*stk_a)))
		swap('a', stk_a, stk_b);
}
