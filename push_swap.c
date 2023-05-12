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
	int av_count;
	int	i;
	
	av_count = 0;
	if (ac > 1)
	{
		while (++av_count < ac)
			stack_a[av_count] = ft_atoi(av[av_count]);
		// av_count = 0;
		// while (++av_count < ac)
		// printf("%d\n", stack_a[av_count]);
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

/*
Process:

main
	1. input the numbers
	2. check if the number is valid (check all digits | check size (modified atoi)| check duplicate)
	3. if it is create a head / node for stack a, else error (lstnew | lstaddback)
	4. repeat 2-3 until all arguments are accepted 

	5. pass stack a into push

ft_push_swap
	6. initialise stack b (lstnew)
	7. if stack a size <= 5 --> small sort, else big sort
	8. 
