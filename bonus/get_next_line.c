/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <leyeghia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:30:11 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/29 12:31:08 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *line)
{
	char	buff[BUFFER_SIZE + 1];
	int		br;

	br = 1;
	while (br)
	{
		br = read(fd, buff, BUFFER_SIZE);
		if (br == -1)
			return (0);
		buff[br] = '\0';
		line = ft_strjoin_g(line, buff);
		if (ft_strchr(buff, '\n') || !br)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*ret_line;
	char		*free_line;
	long		len;

	line = get_line(fd, line);
	if (!line)
		return (0);
	len = ft_strlen_g(line) - ft_strlen_g(ft_strchr(line, '\n')) + 1;
	ret_line = ft_substr(line, 0, len);
	free_line = line;
	line = ft_substr(line, len, ft_strlen_g(line) - len);
	free(free_line);
	return (ret_line);
}
