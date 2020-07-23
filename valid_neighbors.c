/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_neighbors.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/23 18:01:16 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/23 22:36:14 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		edgebound(char **map, int i, int j, int type)
{
	if (type == 1)
		return (map[i][j - 1] != ' ' && map[i][j] != ' ' &&
			map[i][j + 1] != ' ' ? 1 : 0);
	else
	{
		if (map[i][j - 1] == '1' || map[i][j] == '1' ||
			map[i][j + 1] == '1')
			return (0);
	}
	return (1);
}

int		midbound(char **map, int i, int j, int type)
{
	if (type == 1)
		return (map[i][j - 1] != ' ' && map[i][j + 1] != ' ' ? 1 : 0);
	else
		return (map[i][j - 1] == '1' || map[i][j + 1] == '1' ? 1 : 0);
}

int		valid_neighbors(char **map, int x, int y, int *check)
{
	int top;
	int mid;
	int low;
	if (ft_strchr("NSWE", map[x][y]))
		*check = 1;
	top = edgebound(map, x - 1, y, 1);
	mid = midbound(map, x, y, 1);
	low = edgebound(map, x + 1, y, 1);
	if (top && mid && low)
		return (1);
	return (0);
}

int		is_connected(char **map, int x, int y)
{
	int top;
	int mid;
	int low;

	top = edgebound(map, x - 1, y, 2);
	mid = midbound(map, x, y, 1);
	low = edgebound(map, x + 1, y, 2);
	if (top || mid || low)
		return (1);
	return (0);
}
