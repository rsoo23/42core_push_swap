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

int	free_2D_array(char **arr, int n)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	return (n);
}

// checks if all inputs consists of digits only ('-' sign also included)
int	check_if_all_digits(char **num_arr)
{
	int		i;
	int		j;

	i = -1;
	while (num_arr[++i])
	{
		j = 0;
		while (num_arr[i][j])
		{
			if (j == 0 && num_arr[i][j] == '-')
				j++;
			if (!ft_isdigit(num_arr[i][j]))
				return (0);
			j++;
		}
	}
	return (1);
}

// check whether input number is within the int range
int	check_num_size(char **num_arr)
{
	int		i;
	long	num;

	i = -1;
	num = 0;
	while (num_arr[++i])
	{
		num = ft_atoi_long(num_arr[i]);
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

int	check_digits_create_stk(char *num_str, t_dlist **stk_a)
{
	char	**num_arr;

	num_arr = ft_split(num_str, ' ');
	if (!(*num_arr) || !(**num_arr))
		return (free_2D_array(num_arr, 0));
	if (!check_if_all_digits(num_arr))
		return (free_2D_array(num_arr, 0));
	if (!check_num_size(num_arr))
		return (free_2D_array(num_arr, 0));
	*stk_a = create_stk_a(num_arr);
	if (!lst_check_dup(*stk_a))
		return (free_2D_array(num_arr, 0));
	return (free_2D_array(num_arr, 1));
}


