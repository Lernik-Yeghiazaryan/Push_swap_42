/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divider_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:36:55 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/30 18:09:14 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_okay(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || (str[i] >= '0'
				&& str[i] <= '9'))
			i++;
		else if (str[i] == '-')
		{
			++i;
			if (str[i] == '-' || !(str[i] >= '0' && str[i] <= '9'))
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int	check_critical_values(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strlen(line[i]) > 11)
			return (0);
		else if (line[i][0] != '-' && ft_strlen(line[i]) > 10)
			return (0);
		else if (line[i][0] != '-' && ft_strlen(line[i]) > 9 &&
		ft_strcmp(line[i], "2147483647") > 0)
			return (0);
		else if (line[i][0] == '-' && ft_strlen(line[i]) > 10 &&
		ft_strcmp(line[i], "-2147483648") > 0)
			return (0);
		++i;
	}
	return (1);
}

int	is_error(char **line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i + 1])
	{
		while (line[i + j + 1])
		{	
			if (ft_strlen(line[i]) == ft_strlen(line[i + j + 1]))
				if (ft_strcmp(line[i], line[i + j + 1]) == 0)
					return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	check_error(char **line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!is_error(line) || !check_critical_values(line))
	{
		write(2, "Error\n", 6);
		return (0);
	}	
	while (line[i])
	{
		if (!is_okay(line[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}	
		i++;
	}
	i = 0;
	return (1);
}

int	*divider(char *str)
{
	int		i;
	int		*arr;
	char	**line;

	i = 0;
	if (!str)
		exit (0);
	line = ft_split(str);
	if (check_error(line) == 0)
	{
		free(str);
		free_line(line);
		exit (0);
	}
	i = -1;
	arr = malloc(count_words(str) * sizeof(int));
	if (!arr)
		return (0);
	while (line[++i])
		arr[i] = ft_atoi(line[i]);
	free_line(line);
	return (arr);
}
