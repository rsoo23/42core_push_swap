/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:30:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/26 14:07:48 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_top_bottom_index_rem(t_dlist *stack_a, t_info *info)
{
	t_dlist		*head;
	t_dlist		*tail;

	head = stack_a;
	tail = ft_dlstlast(stack_a);
	if (info->size_b == info->upper_lim)
	{
		info->part_size /= 2;
		info->upper_lim += info->part_size;
		if (info->part_size <= 10)
			info->upper_lim = info->original_size_b;
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
		if (info->part_size <= 10)
			info->upper_lim = info->input_size - 3;
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
	else if (info->size_b == info->input_size / 4)
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

void	exp_half_sort_rem(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	info->original_size_b = info->size_b;
	info->lower_lim = info->original_size_b - info->rem_midpoint;
	info->midpoint = (info->original_size_b + info->lower_lim) / 2;
	while (info->size_b > info->lower_lim)
	{
		push('a', stack_a, stack_b);
		if ((*stack_a)->index > info->midpoint)
			rotate('a', stack_a, stack_b);
		info->size_b--;
	}
	info->upper_lim = (info->original_size_b + info->lower_lim) / 2;
	info->part_size = info->rem_midpoint / 2;
	while (info->size_b < info->original_size_b)
	{
		exp_half_sort_a(stack_a, stack_b, info);
		info->size_b++;
	}
}

/*
For: 125 - 250
upperlim = (250 + 125) / 2 = 187.5 = 187
partsize = 125 / 2 = 62.5 = 62

when size_b = upperlim (187)
partsize = 62 / 2 = 31
upperlim = 182 + 31 = 213

when size_b = upperlim (213)
partsize = 31 / 2 = 15
upperlim = 213 + 15 = 228

when size_b = upperlim (228)
partsize = 15 / 2 = 7
upperlim = 228 + 7 = 235

when size_b = upperlim (235)
partsize = 7 / 2 = 3
upperlim = 235 + 3 = 238

when size_b = upperlim (238)
partsize = 3 / 2 = 1
upperlim = 238 + 1 = 239
*/

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
	if (info->size_b > info->input_size / 2)
		find_top_bottom_index(*stack_a, info);
	else
		find_top_bottom_index_rem(*stack_a, info);
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
		if (is_index_sorted(*stack_a))
			break ;
		if (info->input_size >= 200)
			exp_half_sort_rem(stack_a, stack_b, info);
	}
	free(info);
}
