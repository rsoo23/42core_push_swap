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

void	init_info(t_info *info, int size_a)
{
	info->size_a = size_a;
	info->size_b = 0;
	info->pos = 0;
	info->search = 1;
	info->part = 1;
	info->top_pos = 0;
	info->bot_pos = 1;
}

int	find_largest_num(t_dlist *stack)
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

void	assign_index(t_dlist **stack, int arr_size)
{
	int		largest_num;
	t_dlist	*head;

	while (arr_size >= 1)
	{
		head = *stack;
		largest_num = find_largest_num(head);
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

	// printf("index %d is in pos %d\n", info->search, info->pos);
	// printf("mid: %d, rrcount: %d\n", info->midpoint, rev_rot_count);

void	find_num_rot_medium(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	info->pos = 0;
	while ((*stack_a) && info->search != (*stack_a)->index)
	{
		info->pos++;
		(*stack_a) = (*stack_a)->next;
	}
	opt_rot('a', info, stack_a, stack_b);
}

void	sort_medium(t_dlist **stack_a, t_dlist **stack_b, int size_a)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	init_info(info, size_a);
	assign_index(stack_a, size_a);
	while (info->size_a > 3)
	{
		find_num_rot_medium(stack_a, stack_b, info);
		push('b', stack_a, stack_b);
		info->size_b++;
		info->search++;
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