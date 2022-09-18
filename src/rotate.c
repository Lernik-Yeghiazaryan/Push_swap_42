/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:14:12 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/28 18:15:22 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
