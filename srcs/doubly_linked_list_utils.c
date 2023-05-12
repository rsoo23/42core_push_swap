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

#include "push_swap.h"

t_dlist	*create_stack_a(char **av, t_dlist *stack_a)
{
	int		i;
	t_dlist	new_node;

	i = 0;
	stack_a = ft_dlstnew(ft_atoi(av[++i]));
	if (!stack_a)
		return (NULL);
	while (av[++i])
	{
		new_node = ft_dlstnew(ft_atoi(av[i]));
		if (!new_node)
			return (NULL);
		ft_dlstadd_back(&stack_a, new_node);
		free(new_node);
	}
	return (stack_a);
}

t_dlist	*ft_dlstnew(int *content)
{
	t_dlist	*new_elem;

	new_elem = malloc(sizeof(t_dlist));
	if (!new_elem)
		return (0);
	new_elem -> content = content;
	new_elem -> next = NULL;
	new_elem -> prev = NULL;
	return (new_elem);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist last_elem;

	last_elem = ft_lstlast(*lst);
	last_elem-> next = new;
	new-> prev = last_elem;
	new-> next = NULL;
}

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	new-> next = *lst;
	new-> prev = NULL;
	*lst = new;
}

t_dlist	*ft_lstlast(t_dlist *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
