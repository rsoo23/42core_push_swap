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
int		move_check_execute(t_dlist **stk_a, t_dlist **stk_b);
int		check_valid_action(char *move);
char	**init_valid_actions(void);
void	execute_action(t_dlist **stk_a, t_dlist **stk_b, int i);
// checker_utils_1.c
int     free_v_actions(char **v_actions, int n);
void	rev_rotate_bonus(char stk, t_dlist **stk_a, t_dlist **stk_b);
void	rotate_bonus(char stk, t_dlist **stk_a, t_dlist **stk_b);
void	push_bonus(char stk, t_dlist **stk_a, t_dlist **stk_b);
void	swap_bonus(char stk, t_dlist **stk_a, t_dlist **stk_b);

#endif
