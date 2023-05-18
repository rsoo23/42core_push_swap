/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:30:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/18 14:11:06 by rsoo             ###   ########.fr       */
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
		if (tail->index > info->part * i && tail->index <= info->part * (i + 1))
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

void	rot_b_to_tail(int head_index_a, t_dlist **stack_a, t_dlist **stack_b)
{
	int		rot_b_count;
	t_dlist	*tail_b;

	tail_b = ft_dlstlast(*stack_b);
	rot_b_count = 0;
	while (tail_b)
	{	
		if (head_index_a - tail_b->index == 1)
			break ;
		else (head_index_a - tail_b->index > 1)
			break ;
		tail_b = tail_b->prev;
		rot_b_count++;
	}
	while (rot_b_count-- > 0)
		rotate('b', stack_a, stack_b);
}

void	push_b_sequence(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	if (info->size_b == 0 || check_bigger_than_all((*stack_a)->index, *stack_b))
	{
		push('b', stack_a, stack_b);
		write(1, "\n", 1);
	}
	else if (check_smaller_than_all((*stack_a)->index, *stack_b))
	{
		push('b', stack_a, stack_b);
		write(1, "\n", 1);
		rotate('b', stack_a, stack_b);
	}
	else
	{
		write(1, "\n", 1);
		rot_b_to_tail((*stack_a)->index, stack_a, stack_b);
		push('b', stack_a, stack_b);
	}
	while ((*stack_b)->index == ft_dlstlast(*stack_b)->index + 1)
	{
		rev_rotate('b', stack_a, stack_b);
		write(1, "\n", 1);
	}
	return ;
}

void	sort_big(t_dlist **stack_a, t_dlist **stack_b, int size_a)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	init_info(info, size_a);
	assign_index(stack_a, size_a);
	info->part = size_a / 5;
	while (info->size_a > 0)
	{
		info->top_pos = 0;
		info->bot_pos = 1;
		find_top_bottom_index(*stack_a, info);
		rot_a_num_to_head(stack_a, stack_b, info);
		push_b_sequence(stack_a, stack_b, info);
		info->size_b++;
		info->size_a--;
	}
	while ((*stack_b)->index != 1)
		rotate('b', stack_a, stack_b);
	while (info->size_b-- > 0)
		push('a', stack_a, stack_b);
	free(info);
}

/*
10
24
19
2
1
3
5
12
9

19
2
1
3
5
12	24
9	10


*/