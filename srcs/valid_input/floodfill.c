/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/23 18:01:16 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/31 20:48:43 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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

void				floodfill_map(char **map, int *success, int x, int y)
{
	if (*success == 0)
		return ;
	if (!ft_strchr("U0123x", map[x][y]))
	{
		*success = print_error(12);
		return ;
	}
	else if (ft_strchr("U1x", map[x][y]))
		return ;
	if (!edgebound(map, x - 1, y) || !edgebound(map, x + 1, y) ||
			!midbound(map, x, y))
	{
		*success = print_error(11);
		return ;
	}
	map[x][y] = map[x][y] == '2' ? 'U' : 'x';
	floodfill_map(map, success, x + 1, y);
	floodfill_map(map, success, x - 1, y);
	floodfill_map(map, success, x, y + 1);
	floodfill_map(map, success, x, y - 1);
	return ;
}
