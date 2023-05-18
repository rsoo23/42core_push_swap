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
take the top num from stack_b (tail), push it to the top of stack_a (head)
possible cases:
	- [x] stack a is empty
	- [x] stack b is empty
	- [x] only one node in stack b

vice versa for push_b
*/

static void	push_a(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*head_a;
	t_dlist	*tail_b;

	if (*stack_b == NULL)
		return ;
	head_a = *stack_a;
	tail_b = ft_dlstlast(*stack_b);
	if (tail_b->prev != NULL)
		tail_b->prev->next = NULL;
	else
		*stack_b = NULL;
	if (head_a != NULL)
		head_a->prev = tail_b;
	tail_b->prev = NULL;
	tail_b->next = head_a;
	*stack_a = tail_b;
}

static void	push_b(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*head_a;
	t_dlist	*tail_b;

	if (*stack_a == NULL)
		return ;
	head_a = *stack_a;
	tail_b = ft_dlstlast(*stack_b);
	if (head_a->next != NULL)
		head_a->next->prev = NULL;
	else
		*stack_a = NULL;
	*stack_a = head_a->next;
	head_a->prev = tail_b;
	head_a->next = NULL;
	if (tail_b != NULL)
		tail_b->next = head_a;
	else
		*stack_b = head_a;
}

void	push(char stack, t_dlist **stack_a, t_dlist **stack_b)
{
	if (stack == 'a')
	{
		push_a(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
	else if (stack == 'b')
	{
		push_b(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
	return ;
}
