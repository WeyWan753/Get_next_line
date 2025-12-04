/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabin-wa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:27:06 by wabin-wa          #+#    #+#             */
/*   Updated: 2025/12/04 20:57:56 by wabin-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_strjoin_free(char *text, char *buff)
{
	char	*str;

	str = ft_strjoin(text, buff);
	free(text);
	return (str);
}

char	*read_first_line(char *text, int fd)
{
	char	*buff;
	int		bytes_read;

	text = init_text(text);
	buff = malloc(BUFFER_SIZE + 1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (ft_strchr(text, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(text);
			free(buff);
			return (0);
		}
		buff[bytes_read] = 0;
		text = ft_strjoin_free(text, buff);
	}
	free(buff);
	return (text);
}

char	*get_line(char *text)
{
	int		i;
	char	*output_text;

	if (text[0] == 0)
		return (0);
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	output_text = malloc(i + 2);
	output_text[0] = 0;
	ft_strlcat(output_text, text, i + 2);
	return (output_text);
}

char	*clean_line(char *text)
{
	char	*cleaned_line;
	int		i;

	if (text[0] == 0)
	{
		free(text);
		return (0);
	}
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == 0)
	{
		free(text);
		return (0);
	}
	cleaned_line = malloc(ft_strlen(text) - i + 1);
	cleaned_line[0] = 0;
	ft_strlcat(cleaned_line, text + i + 1, ft_strlen(text) - i + 1);
	free(text);
	return (cleaned_line);
}

char	*get_next_line(int fd)
{
	static char	*text[MAX_FD];
	char		*output_text;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (0);
	text[fd] = read_first_line(text[fd], fd);
	if (text[fd] == 0)
		return (0);
	output_text = get_line(text[fd]);
	text[fd] = clean_line(text[fd]);
	return (output_text);
}
/*
int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *str;

	while ((str = get_next_line(fd)))
	{
		printf("%s",str);
		free(str);
	}

}
*/
