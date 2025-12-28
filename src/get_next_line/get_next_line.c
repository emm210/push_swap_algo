/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:41:29 by iait-mou          #+#    #+#             */
/*   Updated: 2025/12/28 21:41:42 by iait-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*extract_line(char *s)
{
	int		i;
	char	*line;

	if (!s || !s[0])
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = ft_substr(s, 0, i);
	return (line);
}

static char	*left_over(char *s)
{
	int		i;
	char	*new_s;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i] || s[i + 1] == '\0')
		return (NULL);
	new_s = ft_strdup(&s[i + 1]);
	return (new_s);
}

static char	*handle_empty(char **s)
{
	if (!(*s) || (*s)[0] == '\0')
	{
		free(*s);
		*s = NULL;
		return (NULL);
	}
	return (*s);
}

static char	*read_append(int fd, char *s)
{
	char	*buf;
	char	*temp;
	int		n;

	n = 0;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(s, '\n'))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buf[n] = '\0';
		temp = s;
		s = ft_strjoin(s, buf);
		free(temp);
	}
	free(buf);
	if (n < 0)
	{
		free(s);
		return (NULL);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s)
		s = ft_strdup("");
	s = read_append(fd, s);
	if (!s)
		return (NULL);
	s = handle_empty(&s);
	if (!s)
		return (NULL);
	line = extract_line(s);
	temp = s;
	s = left_over(s);
	free(temp);
	return (line);
}
