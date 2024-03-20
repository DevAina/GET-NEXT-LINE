/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:29:47 by trarijam          #+#    #+#             */
/*   Updated: 2024/03/20 08:53:10 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

void	read_and_stash(int fd, t_gnl_list *current, ssize_t	*nbytes_read)
{
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	while (ft_read(fd, buf, nbytes_read) != 0)
	{
		buf[*nbytes_read] = '\0';
		if (current->stash)
		{
			tmp = ft_strjoin(current->stash, buf);
			free(current->stash);
			current->stash = tmp;
		}
		else
			current->stash = ft_strdup(buf);
		if (ft_strchr(current->stash, '\n'))
			break ;
	}
	free(buf);
}

void	remove_elem(t_gnl_list **head, int fd)
{
	t_gnl_list	*tmp;
	t_gnl_list	*prev;

	tmp = *head;
	prev = NULL;
	while (tmp && tmp->fd != fd)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return ;
	if (prev)
		prev->next = tmp->next;
	else
		*head = tmp->next;
	free(tmp->stash);
	free(tmp);
}

char	*extract_line_from_stash(char **stash)
{
	char	*line;
	char	*newline_pos;
	size_t	len_line;
	char	*tmp;

	line = NULL;
	newline_pos = ft_strchr(*stash, '\n');
	if (newline_pos)
	{
		len_line = newline_pos - *stash + 2;
		line = (char *)malloc(sizeof(char) * (len_line));
		if (line == NULL)
			return (NULL);
		ft_strlcpy(line, *stash, len_line);
		tmp = ft_strdup(newline_pos + 1);
		free(*stash);
		*stash = tmp;
	}
	else
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	t_gnl_list			*current;
	ssize_t				nbytes_read;
	char				*line;

	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	current = found_node_or_add_in_node(&head, fd);
	if (!current)
		return (NULL);
	nbytes_read = 0;
	read_and_stash(fd, current, &nbytes_read);
	if (nbytes_read == -1 || !current->stash || current->stash[0] == '\0')
	{
		remove_elem(&head, fd);
		return (NULL);
	}
	line = extract_line_from_stash(&current->stash);
	if (line)
		return (line);
	else
	{
		remove_elem(&head, fd);
		return (NULL);
	}
}
