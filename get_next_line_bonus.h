/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trarijam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:39:11 by trarijam          #+#    #+#             */
/*   Updated: 2024/03/05 14:05:36 by trarijam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_gnl_list
{
	int					fd;
	char				*stash;
	struct s_gnl_list	*next;
}				t_gnl_list;

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
t_gnl_list	*found_node_or_add_in_node(t_gnl_list **head, int fd);
ssize_t		ft_read(int fd, char *buf, ssize_t *nbytes_read);
void		read_and_stash(int fd, t_gnl_list *current, ssize_t *nbytes_read);
void		remove_elem(t_gnl_list **head, int fd);
char		*extract_line_from_stash(char **stash);
char		*get_next_line(int fd);

#endif
