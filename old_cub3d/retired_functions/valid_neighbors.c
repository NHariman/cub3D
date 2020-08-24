/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_neighbors.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/23 18:01:16 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/03 21:08:59 by nhariman      ########   odam.nl         */
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
		ft_printf("wtf is going on here:\n1: %c\n2: %c\n3: %c\n", map[i][j - 1], map[i][j], map[i][j + 1]);
		if (map[i][j - 1] == '1' || map[i][j] == '1' ||
			map[i][j + 1] == '1')
			return (1);
	}
	return (0);
}

int		midbound(char **map, int i, int j, int type)
{
	if (type == 1)
		return (map[i][j - 1] != ' ' && map[i][j + 1] != ' ' ? 1 : 0);
	else
		return (map[i][j - 1] == '1' || map[i][j + 1] == '1' ? 1 : 0);
}

int		valid_neighbors(char **map, int x, int y, t_check *check)
{
	int top;
	int mid;
	int low;

	if (ft_strchr("NSWE", map[x][y]))
	{
		if (check->spawn_pos == 0)
			check->spawn_pos = 1;
		else
			return (0);
	}
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
	mid = midbound(map, x, y, 2);
	low = edgebound(map, x + 1, y, 2);
	ft_printf("top: %i\nmid: %i\nlow: %i\n", top, mid, low);
	if (top || mid || low)
		return (1);
	return (0);
}
