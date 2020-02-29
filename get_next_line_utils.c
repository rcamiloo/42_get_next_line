/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:56:55 by marvin            #+#    #+#             */
/*   Updated: 2020/02/29 01:50:00 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = b;
	while (i < len)
		tmp[i++] = (unsigned char)c;
	return (b);
}

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*temp_d;
	unsigned char	*temp_s;

	temp_d = (unsigned char *)dst;
	temp_s = (unsigned char *)src;
	if ((!dst) && (!src) && n)
		return (dst);
	else
	{
		while (n > 0 && *temp_s != (unsigned char)c)
		{
			*temp_d++ = *temp_s++;
			n--;
		}
		if (n)
		{
			*temp_d++ = *temp_s++;
			return (temp_d);
		}
		return (NULL);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	return ((*s == (char)c) ? (char *)s : NULL);
}
