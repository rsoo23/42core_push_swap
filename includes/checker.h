/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:06:35 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/19 12:06:35 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
// checker.c
int		move_check_execute(t_dlist **stk_a, t_dlist **stk_b, char **av);
// checker_utils_1.c
int		check_all_digits_bonus(int ac, char **av);
int		check_num_size_bonus(char **av);
int		check_valid_action_exec(t_dlist **stk_a, t_dlist **stk_b, char **a_lst);
// checker_utils_2.c
t_dlist	*create_stk_a_bonus(char **av);
void	rev_rotate_bonus(char stk, t_dlist **stk_a, t_dlist **stk_b);
void	rotate_bonus(char stk, t_dlist **stk_a, t_dlist **stk_b);
void	push_bonus(char stk, t_dlist **stk_a, t_dlist **stk_b);
void	swap_bonus(char stk, t_dlist **stk_a, t_dlist **stk_b);

#endif
