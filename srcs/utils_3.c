/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:57:58 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/30 11:57:58 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exp_half_sort_2(t_dlist **stk_a, t_dlist **stk_b, t_info *info)
{
	info->top_pos = 0;
	info->bot_pos = 1;
	if (info->size_b <= info->input_size / 2)
	{
		find_top_bottom_index_rem(*stk_a, info);
		opt_rot_top_bot('a', stk_a, stk_b, info);
	}
	push('b', stk_a, stk_b);
	info->pivot = info->upper_lim - info->part_size / 2;
	if (ft_dlstlast(*stk_b)->index < info->pivot)
		rotate('b', stk_a, stk_b);
}
