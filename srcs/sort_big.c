/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:09:35 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/13 15:09:35 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_index(t_dlist **stack, int arr_size)
{
	int		largest_num;
	t_dlist	*head;

	while (arr_size >= 1)
	{
		head = *stack;
		largest_num = find_largest_num(head);
		printf("arr_size:%d, largest_num:%d\n", arr_size, largest_num);
		while (head)
		{
			if (head->content == largest_num && head->index == 0)
			{
				head->index = arr_size;
				break ;
			}
			head = head->next;
		}
		arr_size--;
	}
}

void	sort_big(t_dlist **stack_a, int arr_size)
{
	assign_index(stack_a, arr_size);
}
