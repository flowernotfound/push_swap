/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:48:15 by hiroaki           #+#    #+#             */
/*   Updated: 2024/11/11 00:21:24 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

char	*handle_read(int fd, char *buffer, char *line, int *r)
{
	char	*temp;

	while (*r > 0)
	{
		*r = read(fd, buffer, 1);
		if (*r == -1)
			return (NULL);
		if (*r > 0)
		{
			buffer[*r] = '\0';
			temp = ft_strjoin(line, buffer);
			if (!temp)
				return (NULL);
			line = temp;
			if (buffer[0] == '\n')
				break ;
		}
	}
	return (line);
}

char	*readbuf(int fd, char *line)
{
	int		r;
	char	*buffer;
	char	*result;

	r = 1;
	buffer = malloc(sizeof(char) * (1 + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	result = handle_read(fd, buffer, line, &r);
	if (!result)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*line2;

	line2 = NULL;
	if (fd < 0)
		return (NULL);
	line = readbuf(fd, line2);
	return (line);
}
