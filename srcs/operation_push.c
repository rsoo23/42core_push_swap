/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 06:25:03 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/16 06:25:03 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
take the top num from stk_b (tail), push it to the top of stk_a (head)
possible cases:
	- [x] stk a is empty
	- [x] stk b is empty
	- [x] only one node in stk b

vice versa for push_b
*/

void	push_a(t_dlist **stk_a, t_dlist **stk_b)
{
	t_dlist	*head_a;
	t_dlist	*tail_b;

	if (*stk_b == NULL)
		return ;
	head_a = *stk_a;
	tail_b = ft_dlstlast(*stk_b);
	if (tail_b->prev != NULL)
		tail_b->prev->next = NULL;
	else
		*stk_b = NULL;
	if (head_a != NULL)
		head_a->prev = tail_b;
	tail_b->prev = NULL;
	tail_b->next = head_a;
	*stk_a = tail_b;
}

void	push_b(t_dlist **stk_a, t_dlist **stk_b)
{
	t_dlist	*head_a;
	t_dlist	*tail_b;

	if (*stk_a == NULL)
		return ;
	head_a = *stk_a;
	tail_b = ft_dlstlast(*stk_b);
	if (head_a->next != NULL)
		head_a->next->prev = NULL;
	else
		*stk_a = NULL;
	*stk_a = head_a->next;
	head_a->prev = tail_b;
	head_a->next = NULL;
	if (tail_b != NULL)
		tail_b->next = head_a;
	else
		*stk_b = head_a;
}

void	push(char stk, t_dlist **stk_a, t_dlist **stk_b)
{
	if (stk == 'a')
	{
		push_a(stk_a, stk_b);
		write(1, "pa\n", 3);
	}
	else if (stk == 'b')
	{
		push_b(stk_a, stk_b);
		write(1, "pb\n", 3);
	}
	return ;
}
