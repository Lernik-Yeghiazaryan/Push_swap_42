/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:04:02 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/28 18:04:31 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **s)
{
	int	lst;

	if (!*s || !((*s)->next))
		return ;
	lst = (*s)->data;
	(*s)->data = (*s)->next->data;
	(*s)->next->data = lst;
}

void	sa(t_stack **a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap_stack(b);
	write(1, "sa\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
}
