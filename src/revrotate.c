/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:15:38 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/28 18:17:08 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_front(t_stack **a, int n, int i)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->data = n;
	node->next = *a;
	node->index = i;
	*a = node;
}

void	revrotate(t_stack **s)
{
	t_stack	*r;
	t_stack	*rf;

	r = *s;
	if (*s && (*s)->next)
	{
		while (r->next->next)
			r = r->next;
		rf = r;
		rf = rf->next;
		create_front(s, rf->data, rf->index);
		free(rf);
		r->next = NULL;
	}
}

void	rra(t_stack **a)
{
	revrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	revrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	revrotate(a);
	revrotate(b);
	write(1, "rrr\n", 4);
}
