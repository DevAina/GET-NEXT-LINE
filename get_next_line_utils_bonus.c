/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:58:07 by trarijam          #+#    #+#             */
/*   Updated: 2024/03/05 14:58:18 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;

	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (dstsize == 0)
		return (len_src);
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

char	*ft_strdup(const char *src)
{
	char	*strdup;
	size_t	lensrc;

	lensrc = 0;
	while (src[lensrc] != '\0')
		lensrc++;
	strdup = (char *)malloc(lensrc + 1);
	if (strdup == NULL)
		return (NULL);
	ft_strlcpy(strdup, src, lensrc + 1);
	return (strdup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = 0;
	while (s1[len_s1] != '\0')
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2] != '\0')
		len_s2++;
	strjoin = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (strjoin == NULL)
		return (NULL);
	ft_strlcpy(strjoin, s1, len_s1 + 1);
	ft_strlcpy(strjoin + len_s1, s2, len_s2 + 1);
	return (strjoin);
}

t_gnl_list	*found_node_or_add_in_node(t_gnl_list **head, int fd)
{
	t_gnl_list	*tmp;
	t_gnl_list	*new_elem;

	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new_elem = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (new_elem)
	{
		new_elem->fd = fd;
		new_elem->stash = NULL;
		new_elem->next = *head;
		*head = new_elem;
		return (new_elem);
	}
	return (NULL);
}

ssize_t	ft_read(int fd, char *buf, ssize_t *nbytes_read)
{
	*nbytes_read = read(fd, buf, BUFFER_SIZE);
	return (*nbytes_read);
}
