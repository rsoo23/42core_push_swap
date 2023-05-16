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

static void	init_info(t_sortbig *info)
{
	info->size_b = 0;
	info->pos = 0;
	info->search = 1;
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
		// printf("%d:%d\n", (head)->index, (head)->content);
		arr_size--;
	}
}

void	sort_big(t_dlist **stack_a, t_dlist **stack_b, int size_a)
{
	t_sortbig	*info;
	t_dlist		*head;
	int			rev_rot_count;
	int			midpoint;

	info = malloc(sizeof(t_sortbig));
	init_info(info);
	assign_index(stack_a, size_a);
	// while (*stack_a)
	// {
	// 	printf("%d\n", (*stack_a)->content);
	// 	*stack_a = (*stack_a)->next;
	// }
	while (size_a > 3)
	{
		midpoint = size_a / 2;
		head = *stack_a;
		info->pos = 0;
		while (head && info->search != head->index)
		{
			info->pos++;
			head = head->next;
		}
		// printf("pos:%d of %d, mid:%d\n", info->pos, info->search, midpoint);
		rev_rot_count = size_a - info->pos;
		// printf("pos:%d, mid:%d\n", info->pos, midpoint);
		if (info->pos >= midpoint)
			while (rev_rot_count-- > 0)
				rev_rotate('a', stack_a, stack_b);
		else if (info->pos < midpoint)
			while (info->pos-- > 0)
				rotate('a', stack_a, stack_b);
		push('b', stack_a, stack_b);
		size_a--;
		info->size_b++;
		info->search++;
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