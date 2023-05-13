/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:37:15 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/13 15:37:15 by rsoo             ###   ########.fr       */
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

void	push(char stack_char, t_dlist **stack_a, t_dlist **stack_b)
{
	if (stack_char == 'a')
	{
		push_stack(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
	else if (stack_char == 'b')
	{
		push_stack(stack_b, stack_a);
		write(1, "pb\n", 3);
	}
	else
		return ;
}

static void	push_stack(t_dlist **stack_a, t_dlist **stack_b)
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
	tail_b->prev = NULL;
	tail_b->next = head_a;
	if (head_a != NULL)
		head_a->prev = tail_b;
	*stack_a = tail_b;
}

void	swap(char stack_char, t_dlist **stack_a, t_dlist **stack_b)
{
	if (stack_char == 'a')
	{
		swap_a(stack_a);
		write(1, "pa\n", 3);
	}
	else if (stack_char == 'b')
	{
		swap_b(stack_b);
		write(1, "pb\n", 3);
	}
	else if (stack_char == 's')
	{
		swap_a(stack_a);
		swap_b(stack_b);
		write(1, "ss\n", 3);
	}
	else
		return ;
}

/*
swap_a: (head is at the top)
 NULL<-node1->node2		 [NULL]<-node2->[node1]
node1<-node2->node3		[node2]<-node1->[node3]
node2<-node3->node4		[node1]<-node3->node4

node1: head
node2: next_node
*/

static void	swap_a(t_dlist **stack_a)
{
	t_dlist *head;
	t_dlist *next_node;

	head = *stack_a;
	next_node = head->next;
	if (*head = NULL || (*head)->next == NULL)
		return ;
	head->prev = next_node;
	head->next = next_node->next;
	next_node->prev = NULL;
	next_node->next = head;
	if (head->next != NULL)
		head->next->prev = head;
	*stack_a = next_node;
}

/*
swap_b: (head is at the top)
 NULL<-node1->node2		   NULL<-node1->[node3]
node1<-node2->node3		[node1]<-node3->[node2]
node2<-node3->NULL		[node3]<-node2->[NULL]

node2: prev_node
node3: tail
*/

static void	swap_b(t_dlist **stack_b)
{
	t_dlist *prev_node;
	t_dlist *tail;

	tail = ft_dlstlast(*stack_b);
	prev_node = tail->prev;
	if (*tail = NULL || (*tail)->prev == NULL)
		return ;
	tail->prev = prev_node->prev;
	tail->next = prev_node;
	prev_node->prev = tail;
	prev_node->next = NULL; 
	if (tail->prev != NULL)
		tail->prev->next = tail;
	else
		*stack_b = tail;
}

