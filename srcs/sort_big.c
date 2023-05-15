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

void	init_info(int size_a, t_sortbig *info)
{
	info->size_b = 0;
	info->pos = 0;
	info->midpoint = size_a / 2;
	info->rot_num = info->pos;
	info->rev_rot_num = size_a - info->pos;
}

void	assign_index(t_dlist **stack, int arr_size)
{
	int		largest_num;
	t_dlist	*head;

	while (arr_size-- >= 1)
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
	}
}

void	sort_big(t_dlist **stack_a, t_dlist **stack_b, int size_a)
{
	t_sortbig	*info;
	t_dlist		*head;
	int			search;

	info = malloc(sizeof(t_sortbig));
	search = 1;
	init_info(size_a, info);
	assign_index(stack_a, size_a);
	while (size_a != 3)
	{
		head = *stack_a;
		info->pos = 0;
		while (head && head->content != search)
		{
			info->pos++;
			head = head->next;
		}
		if (info->rev_rot_num <= info->rot_num)
			while (info->rev_rot_num-- > 0)
				rev_rotate('a', stack_a, stack_b);
		else
			while (info->rot_num-- > 0)
				rotate('a', stack_a, stack_b);
		push('b', stack_a, stack_b);
		size_a--;
		info->size_b++;
		search++;
	}
	sort_small(stack_a, stack_b);
	while (info->size_b-- > 0)
		push('a', stack_a, stack_b);
}
