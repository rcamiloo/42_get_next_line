/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:22:03 by camilo            #+#    #+#             */
/*   Updated: 2020/04/24 22:00:51 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_return_line(char **complete_line, char **result_line)
{
	len = 0;
	while ((*complete_line)[len] != '\n' && *complete_line)
		len++;
	if ((*complete_line)[len] == '\n')
	{
		*result_line = ft_substr(*complete_line, 0, len) ;
		tmp = *complete_line[len] + 1;
		free(complete_line);
		complete_line = tmp;
		return (1);
	}

	tmp = (char *)malloc(sizeof(char) * len + 1);






}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*fds[255];
	size_t			size;
	char			*tmp;

	if(fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	if (fds[fd])
		if (ft_strstr(fds[fd], '\n'))
		{
			return (get_line(fds[fd], *line))
		}
	while (size = read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[size] = '\0';
		if (fds[fd] == NULL)
			fds[fd] = ft_strdup(buf);
		tmp = ft_strjoin(fds[fd], buf);
		free(fds[fd]);
		fds[fd] = tmp;
		if (ft_strstr(buf, '\n'))
			break;
	}
	if (size < 0)
		return (-1);
	return (get_line(fds[fd], *line))
}
