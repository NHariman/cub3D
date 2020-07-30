/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/08 22:17:28 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/30 22:52:48 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

static char				*gnl_strjoin(char *s1, char *s2)
{
	char		*strduo;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	strduo = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!strduo)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && i < ft_strlen(s1))
	{
		strduo[i] = s1[i];
		i++;
	}
	while (s2 && j < ft_strlen(s2))
	{
		strduo[i + j] = s2[j];
		j++;
	}
	strduo[i + j] = '\0';
	free(s1);
	return (strduo);
}

static char				*read_line(t_gnl gnl)
{
	char		buf[1000 + 1];
	char		*tmp;

	gnl.bytes_read = 1;
	while (gnl.bytes_read > 0)
	{
		gnl.bytes_read = read(gnl.fd, buf, 1000);
		if (gnl.bytes_read < 0)
			return (NULL);
		buf[gnl.bytes_read] = '\0';
		if (!gnl.line_read)
			gnl.line_read = ft_strdup(buf);
		else
		{
			tmp = gnl_strjoin(gnl.line_read, buf);
			gnl.line_read = (!tmp ? NULL : ft_strdup(tmp));
			free(tmp);
		}
		if (!gnl.line_read)
			return (NULL);
	}
	return (gnl.line_read);
}

static int				fill_line(t_gnl gnl, char **line)
{
	*line = ft_strdup(gnl.line_read);
	if (!*line)
		return (-1);
	return (0);
}

int						get_next_line(int fd, char **line)
{
	t_gnl			gnl;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	gnl.line_read = NULL;
	gnl.fd = fd;
	*line = gnl.line_read;
	gnl.line_read = read_line(gnl);
	if (!gnl.line_read)
		return (-1);
	ret = fill_line(gnl, line);
	free(gnl.line_read);
	return (ret);
}
