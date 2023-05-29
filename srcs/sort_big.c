/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:30:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/29 08:55:15 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_big(t_dlist **stk_a, t_dlist **stk_b, int size_a, t_info *info)
{
	assign_index(stk_a, size_a);
	while (info->size_b < info->input_size - 3)
	{
		exp_half_sort_a(stk_a, stk_b, info);
		info->size_b++;
	}
	sort_small(stk_a, stk_b);
	if (info->input_size <= 200)
		while (info->size_b > 0)
			push_a_insertion(stk_a, stk_b, info);
	else if (info->input_size > 200)
	{
		push_a_sequence(stk_a, stk_b, info);
		while (!is_index_sorted(*stk_a))
		{
			exp_half_sort_rem(stk_a, stk_b, info);
			if (info->size_b == info->input_size / 2)
				info->lower_lim = info->input_size / 4;
			else if (info->size_b == info->input_size / 4)
				info->lower_lim = 0;
			while (info->size_b > info->lower_lim)
				push_a_insertion(stk_a, stk_b, info);
		}
	}
}

void	push_a_insertion(t_dlist **stk_a, t_dlist **stk_b, t_info *info)
{
	t_dlist		*head_b;
	t_dlist		*tail_b;

	head_b = *stk_b;
	tail_b = ft_dlstlast(*stk_b);
	info->top_pos = 0;
	info->bot_pos = 1;
	while (tail_b)
	{
		if ((*stk_a)->index - tail_b->index == 1)
			break ;
		info->top_pos++;
		tail_b = tail_b->prev;
	}
	while (head_b)
	{
		if ((*stk_a)->index - head_b->index == 1)
			break ;
		info->bot_pos++;
		head_b = head_b->next;
	}
	opt_rot_top_bot('b', stk_a, stk_b, info);
	push('a', stk_a, stk_b);
	info->size_b--;
}

void	push_a_sequence(t_dlist **stk_a, t_dlist **stk_b, t_info *info)
{
	while (info->size_b > info->input_size / 2)
	{
		rotate_best_num(stk_a, stk_b, info);
		if ((*stk_a)->index - ft_dlstlast(*stk_b)->index >= 1)
		{
			push('a', stk_a, stk_b);
			info->size_b--;
		}
		else
			while ((*stk_a)->index < ft_dlstlast(*stk_b)->index)
				rotate('a', stk_a, stk_b);
		while ((*stk_a)->index - ft_dlstlast(*stk_a)->index == 1)
			rev_rotate('a', stk_a, stk_b);
	}
}

void	exp_half_sort_a(t_dlist **stk_a, t_dlist **stk_b, t_info *info)
{
	info->top_pos = 0;
	info->bot_pos = 1;
	if (info->size_b > info->input_size / 2)
		find_top_bottom_index(*stk_a, info);
	else if (info->size_b <= info->input_size / 2)
		find_top_bottom_index_rem(*stk_a, info);
	opt_rot_top_bot('a', stk_a, stk_b, info);
	push('b', stk_a, stk_b);
	info->pivot = info->upper_lim - info->part_size / 2;
	if (ft_dlstlast(*stk_b)->index < info->pivot)
		rotate('b', stk_a, stk_b);
}

void	exp_half_sort_rem(t_dlist **stk_a, t_dlist **stk_b, t_info *info)
{
	info->original_size_b = info->size_b;
	info->lower_lim = info->original_size_b - info->rem_midpoint;
	info->midpoint = (info->original_size_b + info->lower_lim) / 2;
	while (info->size_b >= info->lower_lim && info->size_b != 0)
	{
		push('a', stk_a, stk_b);
		if ((*stk_a)->index > info->midpoint)
			rotate('a', stk_a, stk_b);
		info->size_b--;
	}
	info->upper_lim = (info->original_size_b + info->lower_lim) / 2;
	info->part_size = info->rem_midpoint / 2;
	while (info->size_b < info->original_size_b)
	{
		exp_half_sort_a(stk_a, stk_b, info);
		info->size_b++;
	}
}
