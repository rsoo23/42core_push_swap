/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:21:42 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/13 15:21:42 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(char stack_char, t_dlist **stack_a, t_dlist **stack_b)
{
	if (stack_char == 'a')
	{
		rotate_a(stack_a);
		write(1, "ra\n", 3);
	}
	else if (stack_char == 'b')
	{
		rotate_b(stack_b);
		write(1, "rb\n", 3);
	}
	else if (stack_char == 'r')
	{
		rotate_a(stack_a);
		rotate_b(stack_b);
		write(1, "rr\n", 3);
	}
	else
		return ;
}

/*
rotate a: (put head under)
				top of stack
 NULL<-head->node1		 [NULL]<-node1->node2 (set node1 as head)
 head<-node1->node2		node1<-node2->node3
node1<-node2->node3		node2<-tail->[head]
node2<-tail->NULL		[node3]<-head->[NULL]
				bottom of stack
*/

static void	rotate_a(t_dlist **stack)
{
	t_dlist	head;
	t_dlist	tail;

	head = *stack;
	if (head->next = NULL)
		return ;
	tail = ft_dlstlast(*stack);
	tail->next = head;  
	head->next->prev = NULL;
	*stack = head->next;
	head->prev = tail;
	head->next = NULL;
}

/*
rotate b: (put tail under)
				top of stack
node2<-tail->NULL		  node1<-node2->[NULL]
node1<-node2->node3		  head<-node1->node2 
 head<-node1->node2		 [tail]<-head->node1
 NULL<-head->node1		  [NULL]<-tail->[head] (set tail as head)
				bottom of stack
*/

static void	rotate_b(t_dlist **stack)
{
	t_dlist	head;
	t_dlist	tail;

	head = *stack;
	if (head->next = NULL)
		return ;
	tail = ft_dlstlast(*stack);
	head->prev = tail;
	tail->prev->next = NULL;
	tail->next = head;
	tail->prev = NULL;
	*stack = tail;
}

void	rev_rotate(char stack_char, t_dlist **stack_a, t_dlist **stack_b)
{
	if (stack_char == 'a')
	{
		rotate_b(stack_a);
		write(1, "rra\n", 4);
	}
	else if (stack_char == 'b')
	{
		rotate_a(stack_b);
		write(1, "rrb\n", 4);
	}
	else if (stack_char == 'r')
	{
		rotate_a(stack_a);
		rotate_b(stack_b);
		write(1, "rrr\n", 4);
	}
	else
		return ;
}

/*
rev rotate a: (put tail over)
				top of stack
 NULL<-head->node1		  [NULL]<-tail->[head] (set tail as head)
 head<-node1->node2		 [tail]<-head->node1
node1<-node2->node3		  head<-node1->node2 
node2<-tail->NULL		  node1<-node2->[NULL]
				bottom of stack

this is equivalent to rotate b
*/

/*
rev rotate b: (put head over)
				top of stack
node2<-tail->NULL		[node3]<-head->[NULL]
node1<-node2->node3		node2<-tail->[head]
 head<-node1->node2		node1<-node2->node3
 NULL<-head->node1		 [NULL]<-node1->node2 (set node1 as head)
				bottom of stack

this is equivalent to rotate a
*/
