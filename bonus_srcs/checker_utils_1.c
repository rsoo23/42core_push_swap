/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:09:26 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/30 11:16:32 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap_bonus(char stk, t_dlist **stk_a, t_dlist **stk_b)
{
	if (stk == 'a')
		swap_a(stk_a);
	else if (stk == 'b')
		swap_b(stk_b);
	else if (stk == 's')
	{
		swap_a(stk_a);
		swap_b(stk_b);
	}
	return ;
}

void	push_bonus(char stk, t_dlist **stk_a, t_dlist **stk_b)
{
	if (stk == 'a')
		push_a(stk_a, stk_b);
	else if (stk == 'b')
		push_b(stk_a, stk_b);
	return ;
}

void	rotate_bonus(char stk, t_dlist **stk_a, t_dlist **stk_b)
{
	if (stk == 'a')
		rotate_a(stk_a);
	else if (stk == 'b')
		rotate_b(stk_b);
	else if (stk == 'r')
	{
		rotate_a(stk_a);
		rotate_b(stk_b);
	}
	return ;
}

void	rev_rotate_bonus(char stk, t_dlist **stk_a, t_dlist **stk_b)
{
	if (stk == 'a')
		rotate_b(stk_a);
	else if (stk == 'b')
		rotate_a(stk_b);
	else if (stk == 'r')
	{
		rotate_a(stk_a);
		rotate_b(stk_b);
	}
	return ;
}
