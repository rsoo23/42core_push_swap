/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:30:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/17 10:41:05 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_top_bottom_index(t_dlist *stack_a, t_info *info)
{
	t_dlist	*head;
	t_dlist	*tail;

	head = stack_a;
	tail = ft_dlstlast(stack_a);
	info->top_pos = 0;
	info->bot_pos = 1;
	while (head)
	{
		if (head->index >= (10 * info->part - 9) \
		&& head->index <= 10 * info->part)
			break ;
		info->top_pos++;
		head = head->next;
	}
	while (tail)
	{
		if (head->index >= (10 * info->part - 9) \
		&& head->index <= 10 * info->part)
			break ;
		info->bot_pos++;
		tail = tail->prev;
	}
}

void	find_num_rot_big(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	if (info->bot_pos < info->top_pos)
		while (info->bot_pos-- > 0)
			rev_rotate('a', stack_a, stack_b);
	else if (info->bot_pos > info->top_pos)
		while (info->pos-- > 0)
			rotate('a', stack_a, stack_b);
}

void	sort_big(t_dlist **stack_a, t_dlist **stack_b, int size_a)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	init_info(info, size_a);
	assign_index(stack_a, size_a);
	while (info->size_a > 3)
	{
		find_top_bottom_index(*stack_a, info);
		find_num_rot_big(stack_a, stack_b, info);
		info->size_a--;
	}
	sort_small(stack_a, stack_b);
	while (info->size_b-- > 0)
		push('a', stack_a, stack_b);
	free(info);
}
