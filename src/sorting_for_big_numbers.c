/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_for_big_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:11:53 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/30 16:10:16 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_butterfly(t_stack **a, t_stack **b, int n)
{	
	t_stack	*node;
	int		counter;

	node = *a;
	counter = 0;
	while (node)
	{
		if (node->index <= counter)
		{
			pb(a, b);
			rb(b);
			++counter;
		}
		else if (node->index <= counter + n)
		{
			pb(a, b);
			++counter;
		}
		else
			ra(a);
		node = *a;
	}
}

static int	stack_half(t_stack **b, int length)
{
	int		i;
	int		index;
	t_stack	*node;

	i = 0;
	node = *b;
	index = length;
	while (node->index != index)
	{
		node = node->next;
		++i;
	}
	if (i <= length / 2)
		return (1);
	else
		return (0);
}

void	find_max_data(t_stack **a, t_stack **b, int i)
{
	int		n;
	int		flag;

	flag = 0;
	n = 0;
	--i;
	while (b && *b)
	{
		while ((*b)->index != i)
		{
			if (stack_half(b, i) == 1)
			{	
				rb(b);
			}
			else
			{
				rrb(b);
			}
		}
		pa (a, b);
		--i;
	}
}

void	sorting_for_big_numbers(t_stack **a, t_stack **b, int length)
{
	int	n;

	if (length <= 100)
		n = 15;
	else
		n = 30;
	addressing(a, length);
	sort_butterfly(a, b, n);
	find_max_data(a, b, length);
}
