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

# include "../libft/libft.h"
// testing libraries
# include <stdio.h>

typedef struct s_dlist
{
	int				content;
	int				index;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct s_info
{
	int	size_a;
	int	size_b;
	int	input_size;
	int	pos;
	int	search;
	int	top_pos;
	int	bot_pos;
	int	part_size;
	int	upper_lim;
	int	lower_lim;
	int	pivot;
	int	midpoint;
	int	rem_midpoint;
	int	original_size_b;
}	t_info;

// push_swap.c
void	push_swap(int stack_size, t_dlist **stack_a, t_dlist **stack_b);
// input_check.c
int		check_all_digits(int ac, char **av);
int		check_num_size(char **av);
int		lst_check_dup(t_dlist *stack_a);

// operation_swap.c
void	swap(char stack, t_dlist **stack_a, t_dlist **stack_b);
// operation_push.c
void	push(char stack, t_dlist **stack_a, t_dlist **stack_b);
// operation_rot_revrot.c
void	rotate(char stack, t_dlist **stack_a, t_dlist **stack_b);
void	rev_rotate(char stack, t_dlist **stack_a, t_dlist **stack_b);

// sort_small.c
void	sort_small(t_dlist **stack_a, t_dlist **stack_b);
// sort_medium.c
void	sort_medium(t_dlist **stack_a, t_dlist **stack_b, int stack_size);
void	find_num_rot_medium(t_dlist **stack_a, t_dlist **stack_b, t_info *info);
void	assign_index(t_dlist **stack, int stack_size);
int		find_largest_num(t_dlist *stack);
// sort_big.c
void	sort_big(t_dlist **stack_a, t_dlist **stack_b, int size_a, t_info *info);
void	push_a_insertion(t_dlist **stack_a, t_dlist **stack_b, t_info *info);
void	push_a_sequence(t_dlist **stack_a, t_dlist **stack_b, t_info *info);
void	exp_half_sort_a(t_dlist **stack_a, t_dlist **stack_b, t_info *info);
void	exp_half_sort_rem(t_dlist **stack_a, t_dlist **stack_b, t_info *info);

// utils_1.c
long	ft_atoi_long(const char *str);
int		is_stack_sorted(t_dlist *stack);
void	init_info(t_info *info, int size_a);
void	free_stack(t_dlist **stack);
int		is_index_sorted(t_dlist *stack);
// utils_2.c
void	opt_rot(char stack, t_info *info, t_dlist **stack_a,  t_dlist **stack_b);
void	opt_rot_top_bot(char s, t_dlist **stack_a, t_dlist **stack_b, t_info *info);
void	rotate_best_num(t_dlist **stack_a, t_dlist **stack_b, t_info *info);
void	find_top_bottom_index_rem(t_dlist *stack_a, t_info *info);
void	find_top_bottom_index(t_dlist *stack_a, t_info *info);
// doubly_linked_list_utils.c
t_dlist	*create_stack_a(char **av);
t_dlist	*ft_dlstnew(int num);
t_dlist	*ft_dlstlast(t_dlist *lst);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);

#endif