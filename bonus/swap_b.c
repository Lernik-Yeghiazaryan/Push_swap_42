/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:04:02 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/29 12:40:09 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	sb(t_stack **b)
{
	swap_stack(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
}
