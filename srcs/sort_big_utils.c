/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:02:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/19 15:51:49 by rsoo             ###   ########.fr       */
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

void	assign_part_size(t_info *info)
{
	if (info->size_a == 20)
		info->part = info->size_a / 4;
	else if (info->size_a <= 100)
		info->part = info->size_a / 10;
	else if (info->size_a > 100)
		info->part = info->size_a / 20;
}

void	opt_rot(char stack, t_info *info, t_dlist **stack_a,  t_dlist **stack_b)
{
	int		midpoint;
	int		rev_rot_count;
	int		rot_count;
	int		stack_size;

	if (stack == 'a')
		stack_size = info->size_a;
	else
		stack_size = info->size_b;
	midpoint = stack_size / 2;
	rev_rot_count = stack_size - info->pos;
	rot_count = info->pos;
	if (info->pos <= midpoint)
		while (rot_count-- > 0)
			rotate(stack, stack_a, stack_b);
	else if (info->pos > midpoint)
		while (rev_rot_count-- > 0)
			rev_rotate(stack, stack_a, stack_b);	
}
