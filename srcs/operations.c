/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:17:51 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/11 16:17:51 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

NULL <-|1|-> 2
   1 <-|2|-> 3
   2 <-|3|-> 4
       ...


/*
original: 1 2 3 
altered:  2 1 3

swapping:
	store 2nd num in temp

*/

void	swap(char c, int *stack_a, int *stack_b)
{
	if (c == 'a')
	{
		write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		write(1, "sb\n", 3);
	}
	else if (c == 's')
	{
		write(1, "ss\n", 3);
	}
}

void	push(char c, int *stack_a, int *stack_b)
{
	if (c == 'a')
	{
		write(1, "pa\n", 3);
	}
	else if (c == 'b')
	{
		write(1, "pb\n", 3);
	}
}

void	rotate(char c, int *stack_a, int *stack_b)
{
	if (c == 'a')
	{
		write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		write(1, "rb\n", 3);
	}
	else if (c == 'r')
	{
		write(1, "rr\n", 3);
	}
}

void	rev_rotate(char c, int *stack_a, int *stack_b)
{
	if (c == 'a')
	{
		write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		write(1, "rrb\n", 4);
	}
	else if (c == 'r')
	{
		write(1, "rrr\n", 4);
	}
}
