/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezkoro <tbezkoro@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:40:36 by tbezkoro          #+#    #+#             */
/*   Updated: 2022/11/24 15:55:12 by tbezkoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buf[BUFFER_SIZE];
	char		*line;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buf[fd] = read_buf(fd, buf[fd]);
	if (!buf[fd])
		return (0);
	line = get_line(buf[fd]);
	buf[fd] = cut_buf(buf[fd]);
	return (line);
}

char	*read_buf(int fd, char *buf)
{
	char	*tmp;
	int		i;

	if (!buf)
		buf = ft_calloc(1, sizeof(char));
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (0);
	i = 1;
	while (i > 0 && found_new_line(buf) == 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[i] = 0;
		buf = ft_strjoin(buf, tmp);
	}
	free(tmp);
	return (buf);
}

int	found_new_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*cut_buf(char *buf)
{
	char	*newbuf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == 0)
	{
		free(buf);
		return (NULL);
	}
	newbuf = ft_calloc(ft_strlen(buf) - i + 1, sizeof(char));
	i++;
	while (buf[i] != '\0')
	{
		newbuf[j++] = buf[i++];
	}
	free(buf);
	return (newbuf);
}

char	*get_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line [i++] = '\n';
	return (line);
}
