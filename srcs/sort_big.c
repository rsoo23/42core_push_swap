/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:30:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/20 12:55:04 by rsoo             ###   ########.fr       */
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
	if (info->size_b == info->part * (i + 1))
		i++;
	while (head)
	{
		if (head->index > info->part * i && head->index <= info->part * (i + 1))
			break ;
		info->top_pos++;
		head = head->next;
	}
	// printf("top_pos:%d\n", info->top_pos);
	while (tail)
	{
		if (tail->index > info->part * i && tail->index <= info->part * (i + 1))
			break ;
		info->bot_pos++;
		tail = tail->prev;
	}
	// printf("bot_pos:%d\n", info->bot_pos);
}

void	rot_a_num_to_head(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	if (info->bot_pos >= info->top_pos)
		while (info->top_pos-- > 0)
			rotate('a', stack_a, stack_b);
	else if (info->bot_pos < info->top_pos)
		while (info->bot_pos-- > 0)
			rev_rotate('a', stack_a, stack_b);
}

void	push_a_sequence(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	t_dlist *tail_b;

	info->search = info->size_b;
	while (info->search > 0)
	{
		tail_b = ft_dlstlast(*stack_b);
		info->pos = 0;
		while (tail_b && info->search != tail_b->index)
		{
			// printf("search: %d\n", info->search);
			info->pos++;
			tail_b = tail_b->prev;
		}
		opt_rot('b', info, stack_a, stack_b);
		push('a', stack_a, stack_b);
		info->search--;
		info->size_b--;
	}
}

void	sort_big(t_dlist **stack_a, t_dlist **stack_b, int size_a)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	init_info(info, size_a);
	assign_index(stack_a, size_a);
	assign_part_size(info);
	while (info->size_a > 0)
	{
		info->top_pos = 0;
		info->bot_pos = 1;
		find_top_bottom_index(*stack_a, info);
		rot_a_num_to_head(stack_a, stack_b, info);
		// printf("index pushed to b: %d\n", (*stack_a)->index);
		push('b', stack_a, stack_b);
		info->size_b++;
		info->size_a--;
	}
	push_a_sequence(stack_a, stack_b, info);
	free(info);
}
