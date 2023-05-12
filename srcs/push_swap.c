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
	t_dlist	*stack_a;

	if (ac > 1 && check_all_digits(ac, av) && check_num_size(ac, av))
	{
		stack_a = create_stack_a(av, stack_a);
		if (!stack_a)
			return (0);
		if (lst_check_dup(stack_a))
		{
			push_swap(ac, stack_a);
			free(stack_a);
			return (0);
		}
		free(stack_a);
	}
	write(1, "Error\n", 6);
    return (0);
}

int	push_swap(int *stack_a)
{
	free(stack_b);
	return (stack_a)
}

/*
Process:

main
	1. input the numbers
	2. check if the number is valid (check all digits | check size (modified atoi))
		- valid: is num the first num?
			- yes: create head
			- no: check if duplicates exist
				- yes: error
				- no: lstaddback
	3. repeat 2 until all arguments are converted into the linked list

	4. pass stack a into push_swap

ft_push_swap
	6. initialise stack b (lstnew)
	7. if stack a size <= 5 --> small sort, else big sort
*/
