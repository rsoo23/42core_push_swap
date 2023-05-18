/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:02:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/18 09:03:22 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_bigger_than_all(int head_index_a, t_dlist *stack_b)
{
	while (stack_b)
	{
		if (head_index_a < stack_b->index)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

int	check_smaller_than_all(int head_index_a, t_dlist *stack_b)
{
	while (stack_b)
	{
		if (head_index_a > stack_b->index)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}
