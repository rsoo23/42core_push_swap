/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:35 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/13 15:09:35 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_info(t_sortbig *info, int size_a)
{
	info->size_a = size_a;
	info->size_b = 0;
	info->pos = 0;
	info->midpoint = info->size_a / 2;
	info->search = 1;
	info->rev_rot_count = info->size_a - info->pos;
}

static int	find_largest_num_big(t_dlist *stack)
{
	int	largest_num;

	largest_num = -2147483648;
	while (stack)
	{
		if (stack->content > largest_num && stack->index == 0)
			largest_num = stack->content;
		stack = stack->next;
	}
	return (largest_num);
}

static void	assign_index(t_dlist **stack, int arr_size)
{
	int		largest_num;
	t_dlist	*head;

	while (arr_size >= 1)
	{
		head = *stack;
		largest_num = find_largest_num_big(head);
		while (head)
		{
			if (head->content == largest_num && head->index == 0)
			{
				head->index = arr_size;
				break ;
			}
			head = head->next;
		}
		arr_size--;
	}
}

static void find_num_rot_push(t_dlist **stack_a, t_dlist **stack_b, t_sortbig *info)
{
	info->pos = 0;
	while ((*stack_a) && info->search != (*stack_a)->index)
	{
		info->pos++;
		(*stack_a) = (*stack_a)->next;
	}
	if (info->pos >= info->midpoint)
		while (info->rev_rot_count-- > 0)
			rev_rotate('a', stack_a, stack_b);
	else if (info->pos < info->midpoint)
		while (info->pos-- > 0)
			rotate('a', stack_a, stack_b);
	push('b', stack_a, stack_b);
	info->size_b++;
	info->search++;
}

void	sort_big(t_dlist **stack_a, t_dlist **stack_b, int size_a)
{
	t_sortbig	*info;

	info = malloc(sizeof(t_sortbig));
	init_info(info, size_a);
	assign_index(stack_a, size_a);
	while (info->size_a > 3)
	{
		find_num_rot_push(stack_a, stack_b, info);
		info->size_a--;
	}
	sort_small(stack_a, stack_b);
	while (info->size_b-- > 0)
		push('a', stack_a, stack_b);
	free(info);
}

/*
testing 1:
5	
2		4
3		5			3
1		2			4	2
4		3	1		5	1	

rra rra pb
rra rra pb
small sort
pa pa
*/