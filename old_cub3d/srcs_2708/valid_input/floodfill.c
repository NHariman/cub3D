/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/23 18:01:16 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/26 18:35:56 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int			edgebound(char **map, int i, int j)
{
	if (i == 0 || i == (ft_map_len(map, MAP_HEIGHT) - 1))
	{
		return (map[i][j] == '1' &&
				map[i][j + 1] == '1' &&
				map[i][j - 1] == '1' ? 1 : 0);
	}
	else
		return (!ft_strchr(" \n", map[i][j - 1]) &&
				!ft_strchr(" \n", map[i][j]) &&
				!ft_strchr(" \n", map[i][j + 1]) ? 1 : 0);
}

static int			midbound(char **map, int i, int j)
{
	return (!ft_strchr(" \n", map[i][j - 1]) &&
			!ft_strchr(" \n", map[i][j + 1]) ? 1 : 0);
}

void				ft_floodfill_map(char **map, int *success, int x, int y)
{
	if (*success == 0)
		return ;
	if (!ft_strchr("I0123x", map[x][y]))
	{
		*success = ft_print_error(12);
		return ;
	}
	else if (ft_strchr("I1x", map[x][y]))
		return ;
	if (!edgebound(map, x - 1, y) || !edgebound(map, x + 1, y) ||
			!midbound(map, x, y))
	{
		*success = ft_print_error(11);
		return ;
	}
	map[x][y] = map[x][y] == '2' ? 'I' : 'x';
	ft_floodfill_map(map, success, x + 1, y);
	ft_floodfill_map(map, success, x - 1, y);
	ft_floodfill_map(map, success, x, y + 1);
	ft_floodfill_map(map, success, x, y - 1);
	return ;
}
