/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:22:03 by camilo            #+#    #+#             */
/*   Updated: 2020/02/27 23:47:53 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*dest;

	size_s1 = 0;
	size_s2 = 0;
	if (s1)
		size_s1 = strlen(s1);
	if (s2)
		size_s2 = strlen(s2);
	dest = (char *)malloc(sizeof(char) * (size_s1 + size_s2) + 1);
	if (dest == NULL)
		return (NULL);
	if (s1)
		memcpy(dest, s1, size_s1);
	if (s2)
		memcpy(dest + size_s1, s2, size_s2);
	dest[size_s1 + size_s2] = '\0';
	return (dest);
}


size_t ft_strclen(char *s, int c)
{
	size_t size;

	size = 0;
	while (*s++ != (char)c)
		size++;
	return size;
}

int	get_next_line(int fd, char **line)
{
	char	*buf;
	static char	*tmp;
	char	*tmp1;
	size_t	size;
	size_t	partial_size;
	char *partial;

	if(!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (!tmp)
	{
		if(!(tmp = malloc(sizeof(char) * 1)))
			return (-1);
		tmp[0] = '\0';
	}
	size = 1;
	partial_size = 0;
	while (size > 0)
	{
		memset(buf, '\0', BUFFER_SIZE + 1);
		size = read(fd, buf, BUFFER_SIZE);
		tmp = ft_strjoin(tmp, buf);
		partial_size = partial_size + BUFFER_SIZE;
		if (strchr(buf, '\n'))
			break;
	}
		printf("temp1: %zu\n", partial_size);
	if(!(partial = (char *)malloc(sizeof(char) * partial_size)))
		return (-1);
	printf("tempAAA");
	memset(partial, '\0', partial_size);
	tmp1 = memccpy(partial, tmp, '\n', partial_size);
	tmp1--;
	if (size != 0)
	{
		*tmp1 = '\0';
		tmp = tmp + ft_strclen(tmp, '\n') + 1;
		printf("temp2: %s\n", tmp);
	}
	else
	{
		free(tmp);
	}
	*line = partial;
	return size;
}


int		main(void)
{
	int	fd;
	char **line;
	int size;

	line = malloc(sizeof(char*) * 10);
	// OPEN THE FILE
    fd = open("teste.txt", O_RDONLY);
    if (fd < 0) {
        printf("\033[1;31mCould not open file\n");
        return 1;
    }
	else
	{
		printf("file opened, fd = %d\n", fd);
		size = 1;
		while (size > 0)
		{
			size = get_next_line(fd, &line[0]);
			if (!size)
				break;
			printf("size = %d\n", size);
			printf("line = %s\n", line[0]);
		}
	}
	return (0);
}
