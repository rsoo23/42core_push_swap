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
	int *num_arr;
	int av_count;
	int	i;
	
	av_count = 0;
	if (ac > 1 && input_check(ac, av))
	{
		num_arr = malloc(ac * sizeof(int));
		while (++av_count < ac)
			num_arr[av_count] = ft_atoi(av[av_count]);
		// av_count = 0;
		// while (++av_count < ac)
		// 	printf("%d\n", num_arr[av_count]);
		ft_push_swap(num_arr);
		return (0);
	}
	write(1, "Error\n", 6);
    return (0);
}

int	*ft_push_swap(int *sa)
{
	int *sb;

	free(sb);
	return (sa)
}
