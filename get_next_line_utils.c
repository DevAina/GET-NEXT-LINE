/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 08:37:48 by trarijam          #+#    #+#             */
/*   Updated: 2024/03/05 14:38:53 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	len_src;

	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (dst_size == 0)
		return (len_src);
	i = 0;
	while (src[i] != '\0' && i < dst_size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_strjoin;
	char	*strjoin;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = 0;
	while (s1[len_s1] != '\0')
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2] != '\0')
		len_s2++;
	len_strjoin = len_s1 + len_s2 + 1;
	strjoin = (char *)(malloc(len_strjoin * (sizeof(char))));
	if (strjoin == NULL)
		return (NULL);
	ft_strlcpy(strjoin, s1, len_s1 + 1);
	ft_strlcpy(strjoin + len_s1, s2, len_s2 + 1);
	return (strjoin);
}

char	*ft_strdup(const char *src)
{
	int		len_src;
	char	*strdup;

	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	strdup = (char *)malloc(sizeof(char) * (len_src + 1));
	if (strdup == NULL)
		return (NULL);
	ft_strlcpy(strdup, src, len_src + 1);
	return (strdup);
}

char	*ft_strchr(const char *src, int c)
{
	size_t	i;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == c)
			return ((char *)&src[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&src[i]);
	return (NULL);
}
