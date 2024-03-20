/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:55:30 by trarijam          #+#    #+#             */
/*   Updated: 2024/03/12 14:03:07 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	read_custom(int fd, char *buf, ssize_t *nbytes_read)
{
	*nbytes_read = read(fd, buf, BUFFER_SIZE);
	return (*nbytes_read);
}

void	read_and_stash(int fd, char **stash, ssize_t *nbytes_read)
{
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return ;
	while (read_custom(fd, buf, nbytes_read) > 0)
	{
		buf[*nbytes_read] = '\0';
		if (*stash)
		{
			tmp = ft_strjoin(*stash, buf);
			free(*stash);
			*stash = tmp;
		}
		else
			*stash = ft_strdup(buf);
		if (ft_strchr(*stash, '\n'))
			break ;
	}
	free(buf);
}

void	get_content_line(char *stash, char **line, char **newline_pos)
{
	*newline_pos = ft_strchr(stash, '\n');
	if (*newline_pos == NULL)
		*newline_pos = ft_strchr(stash, '\0');
	if (*newline_pos == NULL)
		return ;
	*line = malloc(sizeof(char) * (*newline_pos - stash + 2));
	if (*line == NULL)
		return ;
	ft_strlcpy(*line, stash, *newline_pos - stash + 2);
}

void	clean_stash(char **stash, char	*newline_pos)
{
	char	*tmp;

	if (*newline_pos == '\n')
	{
		tmp = ft_strdup(newline_pos + 1);
		if (tmp == NULL)
		{
			free(*stash);
			*stash = NULL;
			return ;
		}
	}
	else
	{
		tmp = ft_strdup(newline_pos);
		if (tmp == NULL)
		{
			free(*stash);
			*stash = NULL;
			return ;
		}
	}
	free(*stash);
	*stash = tmp;
}

char	*get_next_line(int fd)
{
	static char	*stash;
	ssize_t		nbytes_read;
	char		*newline_pos;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	newline_pos = NULL;
	line = NULL;
	nbytes_read = 0;
	read_and_stash(fd, &stash, &nbytes_read);
	if (stash == NULL || stash[0] == '\0' || nbytes_read == -1)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	get_content_line(stash, &line, &newline_pos);
	if (line == NULL)
		return (NULL);
	clean_stash(&stash, newline_pos);
	return (line);
}
