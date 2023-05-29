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

#include "../includes/push_swap.h"

// checks if all inputs consists of digits only ('-' sign also included)
int	check_all_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && av[i][0] == '-')
				j++;
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
	}
	return (1);
}

// check whether input number is within the int range
int	check_num_size(char **av)
{
	int		av_count;
	long	num;

	av_count = 0;
	num = 0;
	while (av[++av_count])
	{
		num = ft_atoi_long(av[av_count]);
		if (num > 2147483647 || num < -2147483648)
			return (0);
	}
	return (1);
}

int	lst_check_dup(t_dlist *stk_a)
{
	t_dlist	*current;
	t_dlist	*runner;

	current = stk_a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->content == runner->content)
				return (0);
			runner = runner-> next;
		}
		current = current->next;
	}
	return (1);
}
