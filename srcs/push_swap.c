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

// cc -Wall -Wextra -Werror srcs/push_swap.c srcs/utils_1.c srcs/doubly_linked_list_utils.c 
// srcs/input_check.c libft/ft_atoi.c libft/ft_isdigit.c -fsanitize=address -g3

int main(int ac, char **av)
{
	t_dlist	*stack_a;

	printf("check digit: %d, check size: %d\n", check_all_digits(ac, av), check_num_size(av));
	if (ac > 1 && check_all_digits(ac, av) && check_num_size(av))
	{
		stack_a = create_stack_a(av);
		if (!stack_a)
			return (1);
		if (lst_check_dup(stack_a))
		{
			push_swap(ac, stack_a);
			return (0);
		}
	}
	write(1, "Error\n", 6);
    return (0);
}

void	push_swap(int ac, t_dlist *stack_a)
{
	// while (stack_a)
	// {
	// 	printf("%d\n", stack_a->content);
	// 	stack_a = stack_a-> next;
	// }
	// printf("ac: %d\n", ac);
	if (ac - 1 == 1)
		return ;
	else if (ac - 1 <= 5)
		sort_small(stack_a);
	else if (ac - 1 > 5)
		sort_big(stack_a);
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
