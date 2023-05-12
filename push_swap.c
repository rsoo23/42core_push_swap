/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:03:25 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/11 11:03:25 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int *stack_a;
	int	*stack_b;
	int av_count;
	int	i;
	
	av_count = 0;
	if (ac > 1 && input_check(ac, av))
	{
		stack_a = malloc(ac * sizeof(int));
		stack_b = malloc(ac * sizeof(int));
		if (!stack_a || !stack_b)
			return (NULL);
		while (++av_count < ac)
			stack_a[av_count] = ft_atoi(av[av_count]);
		// av_count = 0;
		// while (++av_count < ac)
		// 	printf("%d\n", stack_a[av_count]);
		ft_push_swap(stack_a, stack_b);
		return (0);
	}
	write(1, "Error\n", 6);
    return (0);
}

int	*ft_push_swap(int *stack_a, int *stack_b)
{

	free(stack_b);
	return (stack_a)
}
