/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:30:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/20 23:24:54 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// 77 71 76 15 82 92 24 9 89 19 36 96 6 41 31 22 88 81 90 40 62 84 52 3 12 61 60 98 100 14 69 94 46 4 85 68 99 48 86 32 16 45 7 27 2 56 51 28 10 44 5 80 39 1 83 20 50 55 64 93 79 54 97 38 47 70 73 34 95 29 53 37 17 57 13 35 21 66 43 26 59 8 33 78 74 72 49 23 87 11 65 75 42 25 67 30 63 18 91 58

// ra:113,pb:100,rra:103,rb:174,pa:100,rrb:144
// ra:113,pb:100,rra:103,rb:196,rrb:169,pa:100

// void	find_top_bottom_index(t_dlist *stack_a, t_info *info)
// {
// 	t_dlist		*head;
// 	t_dlist		*tail;
// 	static int	i;

// 	head = stack_a;
// 	tail = ft_dlstlast(stack_a);
// 	if (info->size_b == info->part * (i + 1))
// 		i++;
// 	while (head)
// 	{
// 		if (head->index <= info->part * (i + 1))
// 			break ;
// 		info->top_pos++;
// 		head = head->next;
// 	}
// 	while (tail)
// 	{
// 		if (tail->index <= info->part * (i + 1))
// 			break ;
// 		info->bot_pos++;
// 		tail = tail->prev;
// 	}
// }

void	find_top_bottom_index(t_dlist *stack_a, t_info *info)
{
	t_dlist		*head;
	t_dlist		*tail;

	head = stack_a;
	tail = ft_dlstlast(stack_a);
	while (head)
	{
		if (head->index <= info->part)
			break ;
		info->top_pos++;
		head = head->next;
	}
	while (tail)
	{
		if (tail->index <= info->part)
			break ;
		info->bot_pos++;
		tail = tail->prev;
	}
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
	// assign_part_size(info);
	info->part = size_a / 2;
	while (info->size_a > 0)
	{
		info->top_pos = 0;
		info->bot_pos = 1;
		find_top_bottom_index(*stack_a, info);
		rot_a_num_to_head(stack_a, stack_b, info);
		push('b', stack_a, stack_b);
		// if (info->size_b % 2 == 0)
		// 	rotate('b', stack_a, stack_b);
		if (info->part == info->size_a)
			info->part = info->part / 2;
		// printf("part:%d\n", info->part);
		info->size_b++;
		info->size_a--;
	}
	push_a_sequence(stack_a, stack_b, info);
	free(info);
}
