/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:22:03 by camilo            #+#    #+#             */
/*   Updated: 2020/04/25 03:43:41 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	return ((*s == (char)c) ? (char *)s : NULL);
}

int		get_line(char **complete_line, char **result_line)
{
	char	*tmp;
	int		len;

	len = 0;
	if (*complete_line == NULL)
	{
		*result_line = ft_strdup("");
		return (0);
	}
	while ((*complete_line)[len] != '\n' && (*complete_line)[len])
		len++;
	*result_line = ft_substr(*complete_line, 0, len);
	if ((*complete_line)[len] == '\n')
	{
		tmp = ft_strdup(&(*complete_line)[len + 1]);
		free(*complete_line);
		*complete_line = tmp;
		return (1);
	}
	else
	{
		free(*complete_line);
		*complete_line = NULL;
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*fds[255];
	int				size;
	char			*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	if (fds[fd] && ft_strchr(fds[fd], '\n'))
		return (get_line(&fds[fd], line));
	tmp = NULL;
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		if (fds[fd] == NULL)
			fds[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(fds[fd], buf);
			free(fds[fd]);
			fds[fd] = tmp;
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return ((size < 0) ? (-1) : get_line(&fds[fd], line));
}
