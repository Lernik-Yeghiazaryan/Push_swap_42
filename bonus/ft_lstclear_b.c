/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:35:32 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/29 12:20:08 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*node;

	node = *lst;
	while (node)
	{
		*lst = node -> next;
		free(node);
		node = *lst;
	}
}
