/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:19:18 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/30 20:12:36 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_creat_and_sorting(t_stack **a, t_stack **b, int *arr, int length)
{
	int	i;

	i = 0;
	while (length > i)
		create_stack_back(a, arr[i++]);
	if (*a == NULL)
		exit (0);
	if (length >= 2 && length < 6)
		sorting_2345(a, b, length);
	else
		sorting_for_big_numbers(a, b, length);
}

int	main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;
	int		length;
	int		*arr;
	char	*str;

	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	*a = NULL;
	*b = NULL;
	while (ac > 1 && *++av)
		str = ft_strjoin(str, *av);
	arr = divider(str);
	length = count_words(str);
	free(str);
	if (ac == 1 || is_sorted(arr, length))
		return (0);
	stack_creat_and_sorting(a, b, arr, length);
	free(b);
	ft_lstclear(a);
	return (0);
}
