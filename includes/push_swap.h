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

typedef struct s_dlist
{
	int				*content;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_dlist;

// push_swap.c
int		*push_swap(int *stack_a, int *stack_b);
// operations.c
void	swap(char c, int *stack_a, int *stack_b);
void	push(char c, int *stack_a, int *stack_b);
void	rotate(char c, int *stack_a, int *stack_b);
void	rev_rotate(char c, int *stack_a, int *stack_b);
// input_check.c
int		check_all_digits(int ac, char **av);
int		check_num_size(int ac, char **av);
int		lst_check_dup(t_dlist *stack_a);
// utils_1.c
long long int	ft_atoi_ll(const char *str);
// doubly_linked_list_utils.c
t_dlist	*create_stack_a(char **av, t_dlist *stack_a);
t_dlist	*ft_dlstnew(int *content);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
t_dlist	*ft_lstlast(t_dlist *lst);

#endif