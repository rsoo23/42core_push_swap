/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:28:02 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/30 11:28:02 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_dlist	*stk_a;
	t_dlist	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (ac == 2)
	{
		if (check_digits_create_stk(av[1], &stk_a))
		{
			push_swap(ft_dlstsize(stk_a), &stk_a, &stk_b);
			free_stk(&stk_a);
			free_stk(&stk_b);
			return (0);
		}
		write(2, "Error\n", 6);
	}
	free_stk(&stk_a);
	free_stk(&stk_b);
}
