/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:30:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/19 15:54:31 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
optimisation ideas:
- trailing partition?
	- instead of finding 1 - 20 until all numbers in the range are found, 
	  maybe 

- midpoint calculations for rot_prev_to_tail and rotate

- different approach instead of pa * size_a when everything is sorted in 
  stack_b
*/

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

int	find_next_smallest(int head_index_a, t_dlist **stack_b)
{
	int		min_pos_diff;
	int		diff;
	int		pos;
	t_dlist	*tail_b;

	tail_b = ft_dlstlast(*stack_b);
	pos = 0;
	min_pos_diff = 2147483647;
	while (tail_b)
	{
		diff = head_index_a - tail_b->index;
		if (diff < min_pos_diff && diff > 0)
			min_pos_diff = diff;
		tail_b = tail_b->prev;
	}
	tail_b = ft_dlstlast(*stack_b);
	while (tail_b && tail_b->index != head_index_a - min_pos_diff)
	{
		tail_b = tail_b->prev;
		pos++;
	}
	return (pos);
}

void	push_b_sequence(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	if (info->size_b == 0 || check_bigger_than_all((*stack_a)->index, *stack_b))
		push('b', stack_a, stack_b);
	else if (check_smaller_than_all((*stack_a)->index, *stack_b))
	{
		push('b', stack_a, stack_b);
		rotate('b', stack_a, stack_b);
	}
	else
	{
		info->pos = find_next_smallest((*stack_a)->index, stack_b);
		opt_rot('b', info, stack_a, stack_b);
		push('b', stack_a, stack_b);
	}
	while ((*stack_b)->index - 1 == ft_dlstlast(*stack_b)->index)          // while the head has a bigger index than tail do rrb
		rev_rotate('b', stack_a, stack_b);
	return ;
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
		printf("head_a_index: %d\n", (*stack_a)->index);
		push_b_sequence(stack_a, stack_b, info);
		info->size_b++;
		info->size_a--;
	}
	while ((*stack_b)->index != 1)
		rotate('b', stack_a, stack_b);  //use midpoint optimizer
	while (info->size_b-- > 0)
		push('a', stack_a, stack_b);
	free(info);
}
