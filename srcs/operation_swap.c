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
swap_a: (head is at the top)
 NULL<-node1->node2		 [NULL]<-node2->[node1]
node1<-node2->node3		[node2]<-node1->[node3]
node2<-node3->node4		[node1]<-node3->node4

node1: head
node2: next_node
*/

static void	swap_a(t_dlist **stack_a)
{
	t_dlist	*head;
	t_dlist	*next_node;

	head = *stack_a;
	next_node = head->next;
	if (head->next == NULL)
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
	t_dlist	*prev_node;
	t_dlist	*tail;

	tail = ft_dlstlast(*stack_b);
	prev_node = tail->prev;
	if (tail->prev == NULL)
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

void	swap(char stack, t_dlist **stack_a, t_dlist **stack_b)
{
	if (stack == 'a')
	{
		swap_a(stack_a);
		write(1, "sa\n", 3);
	}
	else if (stack == 'b')
	{
		swap_b(stack_b);
		write(1, "sb\n", 3);
	}
	else if (stack == 's')
	{
		swap_a(stack_a);
		swap_b(stack_b);
		write(1, "ss\n", 3);
	}
	return ;
}
