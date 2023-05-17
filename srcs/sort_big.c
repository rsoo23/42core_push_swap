/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:30:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/17 21:56:55 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_top_bottom_index(t_dlist *stack_a, t_info *info)
{
	t_dlist		*head;
	t_dlist		*tail;
	static int	i;

	head = stack_a;
	tail = ft_dlstlast(stack_a);
	while (head)
	{
		if (head->index > info->part * i && head->index <= info->part * (i + 1))
			break ;
		info->top_pos++;
		head = head->next;
		if (info->top_pos + 1 == info->size_a)
			i++;
	}
	while (tail)
	{
		if (head->index > info->part * i && head->index <= info->part * (i + 1))
			break ;
		info->bot_pos++;
		tail = tail->prev;
	}
}

void	rot_a_num_to_head(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	if (info->bot_pos >= info->top_pos)
		while (info->pos-- > 0)
			rotate('a', stack_a, stack_b);
	else if (info->bot_pos < info->top_pos)
		while (info->bot_pos-- > 0)
			rev_rotate('a', stack_a, stack_b);
}

void	rot_b_to_correct_pos(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	if (info->size_b == 0 || info->size_b == 1) 
		return ;
		
}

void	sort_big(t_dlist **stack_a, t_dlist **stack_b, int size_a)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	init_info(info, size_a);
	assign_index(stack_a, size_a);
	info->part = size_a / 5;
	while (info->size_a > 3)
	{
		info->top_pos = 0;
		info->bot_pos = 1;
		find_top_bottom_index(*stack_a, info);
		rot_a_num_to_head(stack_a, stack_b, info);
		rot_b_to_correct_pos(stack_a, stack_b, info);
		push('b', stack_a, stack_b);
		info->size_b++;
		info->size_a--;
	}
	sort_small(stack_a, stack_b);
	while (info->size_b-- > 0)
		push('a', stack_a, stack_b);
	free(info);
}
