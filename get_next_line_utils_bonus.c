/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:22:03 by camilo            #+#    #+#             */
/*   Updated: 2020/04/24 22:48:02 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *dest;

	if (s == NULL)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	len = (start < ft_strlen(s)) ? len : 0;
	ft_memcpy(dest, s + start, len);
	dest[len] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*dest;

	dest = NULL;
	size = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, size);
	dest[size] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_d;
	unsigned char	*temp_s;

	temp_d = (unsigned char *)dst;
	temp_s = (unsigned char *)src;
	if ((!dst) && (!src) && n)
		return (dst);
	else
		while (n--)
			*temp_d++ = *temp_s++;
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (*s)
	{
		s++;
		size++;
	}
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*dest;

	size_s1 = 0;
	size_s2 = 0;
	if (s1)
		size_s1 = ft_strlen(s1);
	if (s2)
		size_s2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (size_s1 + size_s2) + 1);
	if (dest == NULL)
		return (NULL);
	if (s1)
		ft_memcpy(dest, s1, size_s1);
	if (s2)
		ft_memcpy(dest + size_s1, s2, size_s2);
	dest[size_s1 + size_s2] = '\0';
	return (dest);
}
