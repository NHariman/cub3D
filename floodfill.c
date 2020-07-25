/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_neighbors.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/23 18:01:16 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/26 00:01:53 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int			edgebound(char **map, int i, int j)
{
	return (!ft_strchr(" ", map[i][j - 1]) &&
			!ft_strchr(" ", map[i][j]) &&
			!ft_strchr(" ", map[i][j + 1]) ? 1 : 0);
}

static int			midbound(char **map, int i, int j)
{
	return (!ft_strchr(" ", map[i][j - 1]) &&
			!ft_strchr(" ", map[i][j + 1]) ? 1 : 0);
}

void				floodfill_map(char **map, int *start, int x, int y)
{
	if (*start == 0)
		return ;
	if (!ft_strchr("0123xy", map[x][y]))
	{
		*start = print_error(12);
		return ;
	}
	else if (ft_strchr("1xy", map[x][y]))
		return ;
	if (!edgebound(map, x - 1, y) || !edgebound(map, x + 1, y) ||
			!midbound(map, x, y))
	{
		*start = 0;
		return ;
	}
	map[x][y] = map[x][y] == '2' ? 'y' : 'x';
	floodfill_map(map, start, x + 1, y);
	floodfill_map(map, start, x - 1, y);
	floodfill_map(map, start, x, y + 1);
	floodfill_map(map, start, x, y - 1);
	return ;
}
