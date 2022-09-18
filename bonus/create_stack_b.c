/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:38:51 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/29 12:19:53 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	create_stack_front(t_stack **a, int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->data = n;
	node->next = *a;
	node->index = -1;
	*a = node;
}

void	create_stack_back(t_stack **a, int n)
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
	node->index = -1;
	lst->next = node;
}
