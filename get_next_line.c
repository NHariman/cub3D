/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/08 22:17:28 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/10 20:45:42 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int		find_newline(char *str)
{
	int		i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char		*read_line(t_gnl *gnl)
{
	char	*tmp;

	gnl->bytes_read = 1;
	while (gnl->bytes_read > 0)
	{
		gnl->bytes_read = read(gnl->fd, gnl->buf, 1000);
		if (gnl->bytes_read < 0)
			return (NULL);
		gnl->buf[1000] = '\0';
		if (!gnl->line_read)
			gnl->line_read = ft_strdup(gnl->buf);
		else
		{
			tmp = ft_strjoin(gnl->line_read, gnl->buf);
			gnl->line_read = !tmp ? NULL : ft_strdup(tmp);
			free(tmp);
		}
		if (!gnl->line_read)
			return (NULL);
		if (find_newline(gnl->buf) > -1)
			break ;
	}
	return (gnl->line_read);
}

static int		fill_line(t_gnl *gnl, t_cub *cub)
{
	int		newline;
	size_t	remainder;

	newline = find_newline(gnl->line_read);
	remainder = 0;
	if (newline != -1)
	{
		if (newline != 0)
			cub->cubfile[cub->filesize] =
					ft_substr(gnl->line_read, 0, newline);
		else
			cub->cubfile[cub->filesize] = ft_strdup("");
		remainder = 1;
	}
	else
		cub->cubfile[cub->filesize] = ft_strdup(gnl->line_read);
	if (!cub->cubfile[cub->filesize])
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

int				get_next_line(t_cub *cub)
{
	static char		*leftover;
	t_gnl			gnl;
	int				ret;

	gnl.line_read = NULL;
	gnl.fd = open(cub->cubpath, O_RDONLY);
	cub->cubfile[cub->filesize] = gnl.line_read;
	if (leftover)
	{
		gnl.line_read = ft_strdup(leftover);
		free(leftover);
		leftover = NULL;
	}
	if (find_newline(gnl.line_read) == -1)
		gnl.line_read = read_line(&gnl);
	if (!gnl.line_read)
		return (-1);
	ret = fill_line(&gnl, cub);
	gnl.newline = find_newline(gnl.line_read);
	if (gnl.newline != -1)
		leftover = fill_leftover(gnl.line_read);
	free(gnl.line_read);
	return ((gnl.newline != -1 && !leftover) ? -1 : ret);
}
