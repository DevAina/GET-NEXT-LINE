/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:34:03 by trarijam          #+#    #+#             */
/*   Updated: 2024/03/05 15:10:45 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

ssize_t		read_custom(int fd, char *buuf, ssize_t *nbytes_read);
void		read_and_stash(int fd, char **stash, ssize_t *nbytes_read);
void		get_content_line(char *stash, char **line, char **newline_pos);
void		clean_stash(char **stash, char *newline_pos);
char		*get_next_line(int fd);
size_t		ft_strlcpy(char *dst, const char *src, size_t dst_size);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *src, int c);
char		*ft_strdup(const char *src);

#endif
