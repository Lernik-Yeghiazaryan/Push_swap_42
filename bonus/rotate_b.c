/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:14:12 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/29 12:40:23 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	create_back(t_stack **a, int n, int i)
{
	t_stack	*lst;
	t_stack	*node;

	if (!((*a)))
	{
		create_stack_front(a, n);
		return ;
	}
	node = malloc(sizeof(t_stack));
	node->data = n;
	lst = *a;
	while (lst->next)
		lst = lst->next;
	node->next = NULL;
	node->index = i;
	lst->next = node;
}

void	rotate(t_stack **s)
{
	t_stack	*lst;

	if (*s && (*s)->next)
	{
		lst = *s;
		*s = (*s)->next;
		create_back(s, lst->data, lst->index);
		free(lst);
	}
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
