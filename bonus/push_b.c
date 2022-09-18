/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:29:34 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/29 12:40:39 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	create_front(t_stack **a, int n, int i)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->data = n;
	node->next = *a;
	node->index = i;
	*a = node;
}

void	push(t_stack **stack1, t_stack **stack2)
{
	int		val;
	int		i;
	t_stack	*node;

	val = (*stack1)->data;
	i = (*stack1)->index;
	create_front(stack2, val, i);
	node = *stack1;
	*stack1 = (*stack1)->next;
	free(node);
}

void	pa(t_stack **stack2, t_stack **stack1)
{
	push(stack1, stack2);
}

void	pb(t_stack **stack1, t_stack **stack2)
{
	push(stack1, stack2);
}
