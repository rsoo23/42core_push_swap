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

#include "../includes/push_swap.h"

// cc -Wall -Wextra -Werror srcs/*.c libft/ft_atoi.c libft/ft_isdigit.c 
// -fsanitize=address -g3

int	main(int ac, char **av)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac - 1 >= 1 && check_all_digits(ac, av) && check_num_size(av))
	{
		stack_a = create_stack_a(av);
		if (lst_check_dup(stack_a))
		{
			push_swap(ac - 1, &stack_a, &stack_b);
			free_stack(&stack_a);
			free_stack(&stack_b);
			return (0);
		}
	}
	write(2, "Error\n", 6);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

void	push_swap(int arr_size, t_dlist **stack_a, t_dlist **stack_b)
{
	if (is_stack_sorted(*stack_a))
		return ;
	else if (arr_size == 2)
		swap('a', stack_a, stack_b);
	else if (arr_size == 3)
		sort_small(stack_a, stack_b);
	else if (arr_size <= 15)
		sort_medium(stack_a, stack_b, arr_size);
	else
		sort_big(stack_a, stack_b, arr_size);
	// int i = 0;
	// while (*stack_a)
	// {
	// 	i++;
	// 	printf("%d:%d\n", i, (*stack_a)->index);
	// 	*stack_a = (*stack_a)->next;
	// }
	return ;
}

/*
Process:

main
	1. input the numbers
	2. check if the number is valid (check all digits | check size (modified atoi))
	3. create stack
	4. check for duplicates

	5. pass stack a into push_swap

push_swap
	6. if stack a size <= 5 --> small sort, else big sort
*/
