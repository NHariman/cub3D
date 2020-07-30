/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 22:17:25 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/30 22:52:53 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

/*
** in this function it's not important if
** the file is valid yet.
** The only thing that this function should do
** is create a 2D array of the file
*/

static int		count_newline(const char *str)
{
	int	i;
	int n;

	i = 0;
	n = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

char			**create_array(char *str, int len)
{
	int		i;
	int		j;
	int		start;
	char	**arr;

	i = 0;
	j = 0;
	start = 0;
	arr = (char **)malloc(sizeof(char *) * (len + 1));
	while (str[j] != '\0')
	{
		if (str[j] == '\n')
		{
			arr[i] = ft_substr(str, start, 1 + j - start);
			if (!arr[i] || arr[i] == NULL)
				return (NULL);
			start = j + 1;
			i++;
		}
		j++;
	}
	arr[i] = ft_substr(str, start, 1 + j - start);
	arr[len] = ft_strdup("\0");
	return (arr);
}

int				file_parser(t_cub *cub)
{
	int		fd;

	fd = open(cub->path, O_RDONLY);
	if (get_next_line(fd, &cub->file) == -1)
		return (print_error(18));
	cub->filesize = count_newline(cub->file);
	cub->filearr = create_array(cub->file, cub->filesize);
	if (cub->filearr == NULL)
		return (print_error(17));
	return (1);
}
