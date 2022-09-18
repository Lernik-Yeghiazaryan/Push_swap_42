/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2345.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:13:22 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/30 16:09:17 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_sum(t_stack *a)
{
	int	a1;
	int	a2;
	int	a3;
	int	a4;
	int	a5;

	a1 = a->data;
	a2 = a->next->data;
	a3 = a->next->next->data;
	a4 = a->next->next->next->data;
	a5 = a->next->next->next->next->data;
	if (a2 < a1 && a2 < a3 && a2 < a4 && a2 < a5)
		return (2);
	else if (a3 < a1 && a3 < a2 && a3 < a4 && a3 < a5)
		return (3);
	else if (a4 < a1 && a4 < a2 && a4 < a3 && a4 < a5)
		return (4);
	else if (a5 < a1 && a5 < a2 && a5 < a3 && a5 < a4)
		return (5);
	else
		return (1);
}

static void	sorting_for_3(t_stack **a)
{
	int	i;
	int	j;
	int	k;

	i = (*a)->data;
	j = (*a)->next->data;
	k = (*a)->next->next->data;
	if (i > j && i < k)
		sa(a);
	else if (i < j && i > k)
		rra(a);
	else if (i < j && j > k)
	{
		sa(a);
		ra(a);
	}
	else if (i > j && j > k)
	{
		sa(a);
		rra(a);
	}
	else
		ra(a);
}

static void	sorting_for_4(t_stack **a, t_stack **b)
{
	int	a1;
	int	a2;
	int	a3;
	int	a4;

	a1 = (*a)->data;
	a2 = (*a)->next->data;
	a3 = (*a)->next->next->data;
	a4 = (*a)->next->next->next->data;
	if (a2 < a1 && a2 < a3 && a2 < a4)
		sa(a);
	else if (a3 < a1 && a3 < a2 && a3 < a4)
	{
		ra(a);
		sa(a);
	}
	else if (a4 < a1 && a4 < a2 && a4 < a3)
		rra(a);
	if (check_sort(*a))
		return ;
	pb(a, b);
	sorting_for_3(a);
	pa(a, b);
}

static void	sorting_for_5(t_stack **a, t_stack **b)
{
	if (min_sum(*a) == 2)
		sa(a);
	else if (min_sum(*a) == 3)
	{
		ra(a);
		sa(a);
	}
	else if (min_sum(*a) == 4)
	{
		rra(a);
		rra(a);
	}
	else if (min_sum(*a) == 5)
		rra(a);
	if (check_sort(*a))
		return ;
	pb(a, b);
	sorting_for_4(a, b);
	pa(a, b);
}

void	sorting_2345(t_stack **a, t_stack **b, int count)
{
	(void)b;
	if (count == 2)
		sa(a);
	else if (count == 3)
		sorting_for_3(a);
	else if (count == 4)
		sorting_for_4(a, b);
	else if (count == 5)
		sorting_for_5(a, b);
}
