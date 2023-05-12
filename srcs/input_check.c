/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:36:53 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/11 14:36:53 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if all inputs consists of digits only ('-' sign also included)
int check_all_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][0] == '-')
				j++;		
			if (!ft_isdigit(av[i][j]))
				return (0);
		}
	}
	return (1);
}

// check whether input number is within the int range
int check_num_size(int ac, char **av)
{
	int				av_count;
	long long int	num;

	av_count = 0;
	num = 0;
	while (av[++av_count])
	{
		num = ft_atoi_ll(av[av_count]);
		if (num > 2147483647 || num < -2147483648)
			return (0);
	}
	return (1);
}

int	lst_check_dup(t_dlist *stack_a)
{
	int	current_num;

	while (stack_a->next)
	{
		current_num = stack_a->content;
		while (stack_a->next)
		{
			stack_a = stack_a->next;
			if (current_num == stack_a->content)
				return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}
