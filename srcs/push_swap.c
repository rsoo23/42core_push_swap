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

int	main(int ac, char **av)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac - 1 >= 1)
	{
		if (check_all_digits(ac, av) && check_num_size(av))
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
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
}

void	push_swap(int stack_size, t_dlist **stack_a, t_dlist **stack_b)
{
	t_info	*info;
	
	info = malloc(sizeof(t_info));
	init_info(info, stack_size);
	if (is_stack_sorted(*stack_a))
		return ;
	else if (stack_size == 2)
		swap('a', stack_a, stack_b);
	else if (stack_size == 3)
		sort_small(stack_a, stack_b);
	else if (stack_size <= 20)
		sort_medium(stack_a, stack_b, stack_size);
	else
		sort_big(stack_a, stack_b, stack_size, info);
	free(info);
}
