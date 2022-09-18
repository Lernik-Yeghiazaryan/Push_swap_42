/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:32:10 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/29 12:20:27 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print(t_stack **a, t_stack **b)
{
	t_stack	*cur1;
	t_stack	*cur2;

	cur1 = *a;
	cur2 = *b;
	while (cur1 || cur2)
	{
		if (cur1)
		{
			printf("%d", cur1 -> data);
			cur1 = cur1 -> next;
		}
		printf("  ");
		if (cur2)
		{
			printf(" %d", cur2 -> data);
			cur2 = cur2 -> next;
		}
		printf("\n");
	}
	printf("_   _\na   b\n");
}
