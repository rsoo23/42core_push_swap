/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:38:16 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/30 15:39:33 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atoi_long(const char *str)
{
	int		i;
	long	sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	return (sign * number);
}

int	is_stk_sorted(t_dlist *stk)
{
	while (stk->next)
	{
		if (stk->content > stk->next->content)
			return (0);
		stk = stk->next;
	}
	return (1);
}

int	is_index_sorted(t_dlist *stk)
{
	int	index;

	index = 1;
	while (stk)
	{
		if (stk->index != index)
			return (0);
		stk = stk->next;
		index++;
	}
	return (1);
}

void	free_stk(t_dlist **stk)
{
	t_dlist	*temp;

	if (!stk || !(*stk))
		return ;
	while (*stk)
	{
		temp = (*stk)->next;
		free(*stk);
		*stk = temp;
	}
	*stk = NULL;
}

void	init_info(t_info *info, int size_a)
{
	info->size_a = size_a;
	info->size_b = 0;
	info->input_size = size_a;
	info->pos = 0;
	info->search = 1;
	info->top_pos = 0;
	info->bot_pos = 1;
	info->part_size = size_a;
	info->upper_lim = 0;
	info->lower_lim = 0;
	info->pivot = 0;
	info->midpoint = 0;
	info->rem_midpoint = size_a / 4;
	info->original_size_b = 0;
}
