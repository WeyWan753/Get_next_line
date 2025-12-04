/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:26:58 by wabin-wa          #+#    #+#             */
/*   Updated: 2025/12/04 19:47:38 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	while (*s2 != (unsigned char)c && *s2)
		s2++;
	if (*s2 == (unsigned char)c)
		return ((char *)s2);
	else
		return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	i;
	size_t	j;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	a = ft_strlen(dst);
	b = ft_strlen(src);
	i = 0;
	while (dst[i] && i < size)
		i++;
	j = 0;
	while (src[j] && i + j + 1 < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (a + b);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (s1 == 0 || s2 == 0)
		return (0);
	s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s == 0)
		return (0);
	*s = 0;
	ft_strlcat(s, s1, ft_strlen(s1) + 1);
	ft_strlcat(s, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
	{
		count++;
	}
	return (count);
}

char	*init_text(char *text)
{
	if (text == 0)
	{
		text = malloc(1);
		text[0] = 0;
	}
	return text;
}
