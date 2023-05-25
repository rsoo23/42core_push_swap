/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:30:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/25 15:57:24 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_top_bottom_index(t_dlist *stack_a, t_info *info)
{
	t_dlist		*head;
	t_dlist		*tail;

	head = stack_a;
	tail = ft_dlstlast(stack_a);
	if (info->size_b == info->upper_lim)
	{
		info->part_size /= 2;
		info->upper_lim += info->part_size;
	}
	while (head)
	{
		if (head->index <= info->upper_lim)
			break ;
		info->top_pos++;
		head = head->next;
	}
	while (tail)
	{
		if (tail->index <= info->upper_lim)
			break ;
		info->bot_pos++;
		tail = tail->prev;
	}
}

void	push_a_sequence(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	if (info->size_b == info->input_size - 3)
		info->midpoint = info->input_size / 2;
	else if (info->size_b == info->input_size / 2)
		info->midpoint = info->input_size / 4;
	else if (info->size_b == info->rem_midpoint)
		info->midpoint = 0;
	while (info->size_b > info->midpoint)
	{
		rotate_best_num(stack_a, stack_b, info);
		if ((*stack_a)->index - ft_dlstlast(*stack_b)->index >= 1)
		{
			push('a', stack_a, stack_b);
			info->size_b--;
		}
		else
			while((*stack_a)->index < ft_dlstlast(*stack_b)->index)
				rotate('a', stack_a, stack_b);
		while ((*stack_a)->index - ft_dlstlast(*stack_a)->index == 1)
			rev_rotate('a', stack_a, stack_b);
	}
}

/*
for the example of 500 numbers: once 250 - 500 is sorted we are left with numbers 1 - 250
which are quite scattered and leads to inefficiency.

So the function below finds all numbers that are larger than the midpoint of the range 125 - 250
and pushes them to pa while rb the numbers that are smaller than the midpoint above.

Then the numbers pushed to a will be pushed back to b, ready for push sequence a.
*/
void	exp_half_sort_rem(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	int		original_size_b;

	original_size_b = info->size_b;
	info->lower_lim = original_size_b - info->rem_midpoint;
	while (info->size_b > info->lower_lim)
	{
		push('a', stack_a, stack_b);
		info->size_b--;
	}
	if (info->size_b == 0)
		info->upper_lim = 0;
	else
		info->upper_lim = (original_size_b + info->lower_lim) / 2;
	info->part_size = info->rem_midpoint / 2;
	while (info->size_b < original_size_b)
	{
		exp_half_sort_a(stack_a, stack_b, info);
		info->size_b++;
	}
}

/*
1. range: 0 - 50: part_size = 100 / 2, upperlim = 50, pivot = (0 + 50) = 25, 
2. range: 50 - 75: part_size = 50 / 2, upperlim += part_size = 75, pivot =  (50 + 75) / 2 = 62.5,
3. range: 75 - 87.5: part_size = 25 / 2, upperlim = 87.5, pivot = (75 + 87.5) = 81.25, 

(upperlimit - partsize + upperlimit) / 2
*/

void	exp_half_sort_a(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	info->top_pos = 0;
	info->bot_pos = 1;
	find_top_bottom_index(*stack_a, info);
	opt_rot_top_bot('a', stack_a, stack_b, info);
	push('b', stack_a, stack_b);
	info->pivot = info->upper_lim - info->part_size / 2;
	if (ft_dlstlast(*stack_b)->index < info->pivot)
		rotate('b', stack_a, stack_b);
}

void	sort_big(t_dlist **stack_a, t_dlist **stack_b, int size_a)
{
	t_info	*info;
	
	info = malloc(sizeof(t_info));
	init_info(info, size_a);
	assign_index(stack_a, size_a);
	while (info->size_a > 3)
	{
		exp_half_sort_a(stack_a, stack_b, info);
		info->size_b++;
		info->size_a--;
	}
	sort_small(stack_a, stack_b);
	while (info->size_b > 0)
	{
		push_a_sequence(stack_a, stack_b, info);
		if (info->input_size >= 200)
			exp_half_sort_rem(stack_a, stack_b, info);
	}
	free(info);
}
