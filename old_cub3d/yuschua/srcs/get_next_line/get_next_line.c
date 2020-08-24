/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/04/22 11:41:50 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int				find_newline(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char				*read_line(t_gnl gnl)
{
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	gnl.bytes_read = 1;
	while (gnl.bytes_read > 0)
	{
		gnl.bytes_read = read(gnl.fd, buf, BUFFER_SIZE);
		if (gnl.bytes_read < 0)
			return (NULL);
		buf[gnl.bytes_read] = '\0';
		if (!gnl.line_read)
			gnl.line_read = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(gnl.line_read, buf);
			gnl.line_read = (!tmp ? NULL : ft_strdup(tmp));
			free(tmp);
		}
		if (!gnl.line_read)
			return (NULL);
		if (find_newline(buf) > -1)
			break ;
	}
	return (gnl.line_read);
}

static int				fill_line(t_gnl gnl, char **line)
{
	int		newline;
	size_t	remainder;

	newline = find_newline(gnl.line_read);
	remainder = 0;
	if (newline != -1)
	{
		if (newline != 0)
			*line = ft_substr(gnl.line_read, 0, newline);
		else
			*line = ft_strdup("");
		remainder = 1;
	}
	else
		*line = ft_strdup(gnl.line_read);
	if (!*line)
		return (-1);
	return (newline != -1 && remainder ? 1 : 0);
}

static char				*fill_leftover(char *str)
{
	int		newline;
	char	*leftover;

	newline = find_newline(str);
	if (newline != -1)
	{
		leftover = ft_substr(str, newline + 1, ft_strlen(str) - newline - 1);
		if (!leftover)
			return (NULL);
	}
	else
		return (NULL);
	return (leftover);
}

int						get_next_line(int fd, char **line)
{
	static char		*leftover;
	t_gnl			gnl;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	gnl.line_read = NULL;
	gnl.fd = fd;
	*line = gnl.line_read;
	if (leftover)
	{
		gnl.line_read = ft_strdup(leftover);
		free(leftover);
		leftover = NULL;
	}
	if (find_newline(gnl.line_read) == -1)
		gnl.line_read = read_line(gnl);
	if (!gnl.line_read)
		return (-1);
	ret = fill_line(gnl, line);
	gnl.newline = find_newline(gnl.line_read);
	if (gnl.newline != -1)
		leftover = fill_leftover(gnl.line_read);
	free(gnl.line_read);
	return ((gnl.newline != -1 && !leftover) ? -1 : ret);
}
