/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:22:45 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/29 18:21:28 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stack_create(t_stack **a, int *arr, int length)
{
	int	i;

	i = 0;
	while (length > i)
		create_stack_back(a, arr[i++]);
	if (*a == NULL)
	{
		write (1, "Error\n", 6);
		exit (0);
	}
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
	if (!a || !b)
		return (0);
	*a = NULL;
	*b = NULL;
	while (ac > 1 && *++av)
		str = ft_strjoin(str, *av);
	arr = divider(str);
	length = count_words(str);
	free(str);
	if (ac == 1)
		return (0);
	stack_create(a, arr, length);
	gnl(a, b);
	return (0);
}
