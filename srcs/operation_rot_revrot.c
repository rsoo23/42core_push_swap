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

/*
rotate a: (put head under)
				top of stk
 NULL<-head->node1		 [NULL]<-node1->node2 (set node1 as head)
 head<-node1->node2		node1<-node2->node3
node1<-node2->node3		node2<-tail->[head]
node2<-tail->NULL		[node3]<-head->[NULL]
				bottom of stk
*/

static void	rotate_a(t_dlist **stk)
{
	t_dlist	*head;
	t_dlist	*tail;

	head = *stk;
	if (head->next == NULL)
		return ;
	tail = ft_dlstlast(*stk);
	tail->next = head;
	head->next->prev = NULL;
	*stk = head->next;
	head->prev = tail;
	head->next = NULL;
}

/*
rotate b: (put tail under)
				top of stk
node2<-tail->NULL		  node1<-node2->[NULL]
node1<-node2->node3		  head<-node1->node2 
 head<-node1->node2		 [tail]<-head->node1
 NULL<-head->node1		  [NULL]<-tail->[head] (set tail as head)
				bottom of stk
*/

static void	rotate_b(t_dlist **stk)
{
	t_dlist	*head;
	t_dlist	*tail;

	head = *stk;
	if ((head)->next == NULL)
		return ;
	tail = ft_dlstlast(*stk);
	head->prev = tail;
	tail->prev->next = NULL;
	tail->next = head;
	tail->prev = NULL;
	*stk = tail;
}

void	rotate(char stk, t_dlist **stk_a, t_dlist **stk_b)
{
	if (stk == 'a')
	{
		rotate_a(stk_a);
		write(1, "ra\n", 3);
	}
	else if (stk == 'b')
	{
		rotate_b(stk_b);
		write(1, "rb\n", 3);
	}
	else if (stk == 'r')
	{
		rotate_a(stk_a);
		rotate_b(stk_b);
		write(1, "rr\n", 3);
	}
	return ;
}

void	rev_rotate(char stk, t_dlist **stk_a, t_dlist **stk_b)
{
	if (stk == 'a')
	{
		rotate_b(stk_a);
		write(1, "rra\n", 4);
	}
	else if (stk == 'b')
	{
		rotate_a(stk_b);
		write(1, "rrb\n", 4);
	}
	else if (stk == 'r')
	{
		rotate_a(stk_a);
		rotate_b(stk_b);
		write(1, "rrr\n", 4);
	}
	return ;
}

/*
rev rotate a: (put tail over)
				top of stk
 NULL<-head->node1		  [NULL]<-tail->[head] (set tail as head)
 head<-node1->node2		 [tail]<-head->node1
node1<-node2->node3		  head<-node1->node2 
node2<-tail->NULL		  node1<-node2->[NULL]
				bottom of stk

this is equivalent to rotate b
*/

/*
rev rotate b: (put head over)
				top of stk
node2<-tail->NULL		[node3]<-head->[NULL]
node1<-node2->node3		node2<-tail->[head]
 head<-node1->node2		node1<-node2->node3
 NULL<-head->node1		 [NULL]<-node1->node2 (set node1 as head)
				bottom of stk

this is equivalent to rotate a
*/
