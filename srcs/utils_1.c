/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:38:16 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/24 17:15:31 by rsoo             ###   ########.fr       */
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

int	is_stack_sorted(t_dlist *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_stack(t_dlist **stack)
{
	t_dlist	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
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
	info->pivot = 0;
	info->midpoint = 0;
}
