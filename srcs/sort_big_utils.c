/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:02:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/21 21:25:11 by rsoo             ###   ########.fr       */
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
	if (info->size_a <= 100)
		info->part_num = 5;
	else if (info->size_a <= 200)
		info->part_num = 10;
	else
		info->part_num = 12;
	info->part_size = info->size_a / info->part_num;
	info->upper_lim = info->part_size * info->part_ind;
}

void	opt_rot(char stack, t_info *info, t_dlist **stack_a,  t_dlist **stack_b)
{
	int		rev_rot_count;
	int		rot_count;
	int		stack_size;

	if (stack == 'a')
		stack_size = info->size_a;
	else if (stack == 'b')
		stack_size = info->size_b;
	// printf("size_b: %d", info->size_b);
	rev_rot_count = stack_size - info->pos;
	rot_count = info->pos;
	if (rot_count <= rev_rot_count)
		while (rot_count-- > 0)
			rotate(stack, stack_a, stack_b);
	else if (rot_count > rev_rot_count)
		while (rev_rot_count-- > 0)
			rev_rotate(stack, stack_a, stack_b);	
}
