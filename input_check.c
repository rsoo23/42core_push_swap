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

int	input_check(int ac, char **av)
{
	if (!ft_check_all_digits(ac, av))
		return (0);
	// if (!ft_check_num_size(ac, av))
	// 	return (0);
	// if (!ft_check_num_dup(ac, av))
	// 	return (0);
	return (1);
}

static int ft_check_all_digits(int ac, char **av)
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

// static int ft_check_num_size(int ac, char **av)
// {

// }

// static int ft_check_num_dup(int ac, char **av)
// {

// }
