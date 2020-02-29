/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:22:03 by camilo            #+#    #+#             */
/*   Updated: 2020/02/29 02:04:01 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*dest;

	size_s1 = s1 ? ft_strlen(s1) : 0;
	size_s2 = s2 ? ft_strlen(s2) : 0;
	if(!(dest = (char *)malloc(sizeof(char) * (size_s1 + size_s2) + 1)))
		return (NULL);
	if (s1)
		ft_memcpy(dest, s1, size_s1);
	if (s2)
		ft_memcpy(dest + size_s1, s2, size_s2);
	dest[size_s1 + size_s2] = '\0';
	return (dest);
}

size_t	ft_strclen(char *s, int c)
{
	size_t size;

	size = 0;
	while (*s++ != (char)c && *s)
		size++;
	return (size);
}

char	*ft_return_line(char *complete)
{
	size_t	size;
	char	*result;
	char	*tmp1;

	size = ft_strclen(complete, '\n');
	if (!(result = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(result, '\0', size + 1);
	tmp1 = ft_memccpy(result, complete, '\n', size + 1);
	if (size > 0)
		tmp1--;
	*tmp1 = '\0';
	return (result);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*tmp;
	size_t			size;
	size_t			partial_size;

	if (!tmp)
	{
		if (!(tmp = malloc(sizeof(char) * 1)))
			return (-1);
	}
	else
	{
		if (ft_strchr(tmp, '\n'))
		{
			if (!(*line = ft_return_line(tmp)))
				return (-1);
			tmp = tmp + ft_strclen(tmp, '\n') + 1;
			return (1);
		}
	}
	if (!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	size = 1;
	partial_size = 0;
	while (size > 0)
	{
		ft_memset(buf, '\0', BUFFER_SIZE + 1);
		if (!(size = read(fd, buf, BUFFER_SIZE)))
			return (0);
		tmp = ft_strjoin(tmp, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!(*line = ft_return_line(tmp)))
		return (-1);
	tmp = tmp + ft_strclen(tmp, '\n') + 1;
	return (1);
}
