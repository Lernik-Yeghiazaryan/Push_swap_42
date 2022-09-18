/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addressing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:38:11 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/30 11:07:18 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addressing(t_stack **a, int length)
{
	t_stack	*cycle;
	t_stack	*min_node;
	int		i;

	min_node = *a;
	cycle = (*a)->next;
	i = 0;
	while (i < length)
	{
		while (cycle)
		{
			if (cycle->index == -1 && min_node->data > cycle->data)
				min_node = cycle;
			cycle = cycle->next;
		}
		min_node->index = i;
		++i;
		cycle = *a;
		min_node = *a;
		while (i < length && min_node->index != -1)
			min_node = min_node->next;
	}
}
