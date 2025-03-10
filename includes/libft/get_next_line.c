/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:50:28 by lfabel            #+#    #+#             */
/*   Updated: 2025/01/23 11:54:19 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*pos;
	char		*line;
	size_t		len;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (buffer_check(buf));
	while (1)
	{
		if (*buf == '\0')
		{
			len = read(fd, buf, BUFFER_SIZE);
			if (len <= 0)
				return (freigabe(line));
			buf[len] = '\0';
		}
		pos = ft_strchr_gnl(buf, '\n');
		if (pos)
			return (position(pos, line, buf));
		if (*buf != '\0')
			line = zwei(line, buf);
	}
}

char	*position(char *pos, char *line, char *buf)
{
	char	*tmp;
	size_t	len;

	tmp = ft_strnjoin_gnl(line, buf, (ft_strle(buf) - ft_strle(pos)) + 1);
	line = ft_strndup_gnl(tmp, ft_strle(tmp));
	if (tmp)
	{
		free (tmp);
		tmp = NULL;
	}
	if (!line)
		return (NULL);
	len = ft_strle(pos + 1);
	ft_memmove_gnl(buf, pos + 1, len + 1);
	return (line);
}

char	*zwei(char *line, char *buf)
{
	char	*tmp;

	if (line)
	{
		tmp = ft_strnjoin_gnl(line, buf, ft_strle(buf));
		line = tmp;
	}
	else if (!line)
		line = ft_strndup_gnl(buf, ft_strle(buf));
	*buf = '\0';
	if (!line)
		return (NULL);
	return (line);
}

char	*freigabe(char *line)
{
	if (line)
		return (line);
	return (NULL);
}

char	*buffer_check(char *buf)
{
	*buf = '\0';
	return (NULL);
}
