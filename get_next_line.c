/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:22:03 by camilo            #+#    #+#             */
/*   Updated: 2020/02/27 12:55:34 by camilo           ###   ########.fr       */
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
	free(s1);
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
	char	*tmp;
	char	*tmp1;
	size_t	size;
	size_t	partial_size;
	static char *partial;

	if(!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if(!(tmp = malloc(sizeof(char) * 100)))
		return (-1);
	memset(buf, '\0', 100);
	size = 1;
	partial_size = 0;
	printf("aqui 1\n");
	while (size > 0)
	{
		memset(buf, '\0', BUFFER_SIZE + 1);
		size = read(fd, buf, BUFFER_SIZE);
		tmp = ft_strjoin(tmp, buf);
		partial_size = partial_size + BUFFER_SIZE;
	printf("aqui %zu\n", partial_size);
		if (strchr(buf, '\n'))
			break;
	}
	printf("aqui saida 1\n");
	printf("partial %s\n", tmp);
	if(!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	tmp1 = memccpy(partial, tmp, '\n', partial_size);
	tmp1--;
	*tmp1 = '\0';
	printf("partial %s\n", tmp);
	line = &partial;
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
		size = get_next_line(fd, &line[0]);
		printf("size = %d\n", size);
		printf("line = %s\n", line[0]);

		

	}
	return (0);
}
