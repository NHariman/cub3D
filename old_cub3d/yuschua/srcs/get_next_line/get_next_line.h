/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/01 13:57:16 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10000
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_gnl
{
	int			bytes_read;
	int			fd;
	char		*line_read;
	int			newline;
}				t_gnl;

char			*ft_substr(char const *s, int start, size_t len);
int				ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2);
int				get_next_line(int fd, char **line);

#endif
