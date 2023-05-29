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

int	find_largest_num(t_dlist *stk)
{
	int	largest_num;

	largest_num = -2147483648;
	while (stk)
	{
		if (stk->content > largest_num && stk->index == 0)
			largest_num = stk->content;
		stk = stk->next;
	}
	return (largest_num);
}

void	assign_index(t_dlist **stk, int size_a)
{
	int		largest_num;
	t_dlist	*head;

	while (size_a >= 1)
	{
		head = *stk;
		largest_num = find_largest_num(head);
		while (head)
		{
			if (head->content == largest_num && head->index == 0)
			{
				head->index = size_a;
				break ;
			}
			head = head->next;
		}
		size_a--;
	}
}

void	find_num_rot_medium(t_dlist **stk_a, t_dlist **stk_b, t_info *info)
{
	t_dlist	*head_a;

	head_a = *stk_a;
	info->pos = 0;
	while (head_a && info->search != head_a->index)
	{
		info->pos++;
		head_a = head_a->next;
	}
	opt_rot('a', info, stk_a, stk_b);
}

void	sort_medium(t_dlist **stk_a, t_dlist **stk_b, int size_a, t_info *info)
{
	assign_index(stk_a, size_a);
	while (info->size_b < info->input_size - 3)
	{
		find_num_rot_medium(stk_a, stk_b, info);
		push('b', stk_a, stk_b);
		info->size_a--;
		info->size_b++;
		info->search++;
	}
	sort_small(stk_a, stk_b);
	while (info->size_b-- > 0)
		push('a', stk_a, stk_b);
}
