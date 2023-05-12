/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:00:52 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/11 11:00:52 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h> // malloc, free, exit
#include <unistd.h> // read, write
// testing libraries
#include <stdio.h>

typedef struct s_info
{
    int     
}               t_info;

// push_swap.c
int     *ft_push_swap(int *stack_a, int *stack_b);
// operations.c
void	swap(char c, int *stack_a, int *stack_b);
void	push(char c, int *stack_a, int *stack_b);
void	rotate(char c, int *stack_a, int *stack_b);
void	rev_rotate(char c, int *stack_a, int *stack_b);
// input_check.c
int	input_check(int ac, char **av);

#endif