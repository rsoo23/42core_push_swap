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

#include "../libft/libft.h"
#include <stdlib.h> // malloc, free, exit
#include <unistd.h> // read, write
// testing libraries
#include <stdio.h>

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

// push_swap.c
void	push_swap(int arr_size, t_dlist **stack_a, t_dlist **stack_b);
// input_check.c
int		check_all_digits(int ac, char **av);
int		check_num_size(char **av);
int		lst_check_dup(t_dlist *stack_a);

// operation_push_and_swap.c
void	push(char stack_char, t_dlist **stack_a, t_dlist **stack_b);
void	swap(char stack_char, t_dlist **stack_a, t_dlist **stack_b);
// operation_rot_and_revrot.c
void	rotate(char stack_char, t_dlist **stack_a, t_dlist **stack_b);
void	rev_rotate(char stack_char, t_dlist **stack_a, t_dlist **stack_b);

// utils_1.c
long long int	ft_atoi_ll(const char *str);
int				is_stack_sorted(t_dlist *stack);
void			free_stack(t_dlist **stack);
// doubly_linked_list_utils.c
t_dlist	*create_stack_a(char **av);
t_dlist	*ft_dlstnew(int num);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
t_dlist	*ft_dlstlast(t_dlist *lst);

#endif