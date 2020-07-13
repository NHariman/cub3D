/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 22:17:25 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/14 00:46:44 by nhariman      ########   odam.nl         */
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

int		ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_array(char **arr)
{
	int	len;

	len = ft_arrlen(arr);
	while (len > 0)
	{
		free(arr[len + 1]);
		len--;
	}
	free(arr);
	arr = NULL;
}

void	cubfile_elongator(t_cub *cub)
{
	char	**tmp;
	int		arrlen;
	int		i;

	arrlen = ft_arrlen(cub->cubfile) + 1;
	i = 0;
	tmp = (char **)malloc((arrlen + 1) * sizeof(char *));
	while (i < arrlen)
	{
		tmp[i] = ft_strdup(cub->cubfile[i]);
		i++;
	}
	free_array(cub->cubfile);
	cub->cubfile = tmp;
	free_array(tmp);
}

int		map_parser(t_cub *cub)
{
	int		i;

	cub->filesize = 0;
	i = 1;
	while (i == 1)
	{
		i = get_next_line(cub);
		if (i == 1 && cub->cubfile)
			cubfile_elongator(cub);
		else if (i == -1)
		{
			free_array(cub->cubfile);
			empty_cub(cub);
			return (-1);
		}
	}
	return (1);
}
