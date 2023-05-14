/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:14:18 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/12 22:14:18 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist	*create_stack_a(char **av)
{
	int		i;
	t_dlist	*temp_stack;
	t_dlist	*new_node;

	i = 0;
	temp_stack = NULL;
	new_node = NULL;
	while (av[++i])
	{
		new_node = ft_dlstnew(ft_atoi(av[i]));
		if (!new_node)
			return (NULL);
		ft_dlstadd_back(&temp_stack, new_node);
	}
	return (temp_stack);
}

t_dlist	*ft_dlstnew(int num)
{
	t_dlist	*new_elem;

	new_elem = malloc(sizeof(t_dlist));
	if (!new_elem)
		return (0);
	new_elem-> content = num;
	new_elem-> next = NULL;
	new_elem-> prev = NULL;
	return (new_elem);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last_elem;

	last_elem = ft_dlstlast(*lst);
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_elem->next = new;
	new->prev = last_elem;
	new->next = NULL;
}

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
