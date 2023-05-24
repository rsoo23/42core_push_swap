/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:02:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/24 16:45:56 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	opt_rot(char stack, t_info *info, t_dlist **stack_a,  t_dlist **stack_b)
{
	int		rev_rot_count;
	int		rot_count;
	int		stack_size;

	stack_size = 0;
	if (stack == 'a')
		stack_size = info->size_a;
	else if (stack == 'b')
		stack_size = info->size_b;
	rev_rot_count = stack_size - info->pos;
	rot_count = info->pos;
	if (rot_count <= rev_rot_count)
		while (rot_count-- > 0)
			rotate(stack, stack_a, stack_b);
	else if (rot_count > rev_rot_count)
		while (rev_rot_count-- > 0)
			rev_rotate(stack, stack_a, stack_b);	
}

void	opt_rot_top_bot(char s, t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	if (info->bot_pos >= info->top_pos)
		while (info->top_pos-- > 0)
			rotate(s, stack_a, stack_b);
	else if (info->bot_pos < info->top_pos)
		while (info->bot_pos-- > 0)
			rev_rotate(s, stack_a, stack_b);
}

/*
Search stack b starting from the tail for any index where the difference between
head_a index and tail_b index is between 1 to 3.

Find the index that takes the least amount of rotations to bring it to tail_b
*/
void	rotate_best_num(t_dlist **stack_a, t_dlist **stack_b, t_info *info)
{
	t_dlist	*tail_b;
	t_dlist	*head_b;
	int		diff;
	
	tail_b = ft_dlstlast(*stack_b);
	head_b = *stack_b;
	info->top_pos = 0;
	info->bot_pos = 1;
	while (tail_b)
	{
		diff = (*stack_a)->index - tail_b->index;
		if (diff <= 2)
			break ;
		info->top_pos++;
		tail_b = tail_b->prev;
	}
	while (head_b)
	{
		diff = (*stack_a)->index - (head_b)->index;
		if (diff <= 2)
			break ;
		info->bot_pos++;
		head_b = (head_b)->next;
	}
	opt_rot_top_bot('b', stack_a, stack_b, info);
}
