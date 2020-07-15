/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 22:17:25 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/15 22:39:23 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
** in this function it's not important if
** the file is valid yet.
** The only thing that this function should do
** is create a 2D array of the file
*/

// create a function that elongates the 2D cubfile format.
// like strjoin in 2D.
// make a free function that frees for ** and * strings

// void	free_array(char **arr)
// {
// 	int	len;

// 	len = ft_arrlen(arr);
// 	while (len > 0)
// 	{
// 		free(arr[len + 1]);
// 		len--;
// 	}
// 	free(arr);
// 	arr = NULL;
// }

static int	count_newline(char *str)
{
	int	i;
	int n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	n++;
	return (n);
}

static int	create_array(char *str, int len, t_cub *cub)
{
	int i;
	int	j;
	int start;
	int end;

	i = 0;
	j = 0;
	start = 0;
	end = 0;
	cub->map = (char **)malloc(sizeof(char *) * (len + 1));
	while (str[j] != '\0')
	{
		if (str[j] == '\n')
		{
			cub->map[i] = ft_substr(str, start, j - start);
			if (!cub->map[i] || cub->map[i] == NULL)
				return (-1);
			start = j + 1;
			i++;
		}
		j++;
	}
	cub->map[i] = ft_substr(str, start, j - start);
	cub->map[len] = NULL;
	return (1);
}

int		map_parser(t_cub *cub)
{
	int		fd;

	fd = open(cub->path, O_RDONLY);
	if (get_next_line(fd, &cub->file) == -1)
		return (-1);
	cub->filesize = count_newline(cub->file);
	create_array(cub->file, cub->filesize, cub);
	return (1);
}
