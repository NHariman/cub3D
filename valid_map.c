/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 15:33:16 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/25 00:19:48 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
** map must ONLY contain ' ', 1, 2, or ONE of N, S, E, W.
** a valid map is a map that starts and ends with all 1 and ' '
** and all 0s, NSWE and 2s are completely blocked off from spaces,
** including diagonally.
** the function should be called at the first hint of a 1, indicating
** the start of a map.
** aka. the first time this function is called,
** map[0] should only contain 1 and ' '
** after that the function should check if the middle bits are correct.
** example:
**        xxx
**        x0x
**        xxx
** if a 0 touches a space in any of the x positions the map is invalid.
** a map ends when another row of only 1s and spaces is found.
** the function should know the map is over and still scan the field to
** check for ' ' and 1s as those are still valid even after a map ends.
** if only ' ' and '\n' are found that also means the map has ended,
** if characters are found after that's fine too lol.
** WARNING: ONLY THE MAP THE PLAYER AS ACCESS TO HAS TO BE CLOSED. AKA. FLOODFILL
** STARTING FROM SPAWN POINT!!
*/

static int		find_spawnpoint(t_cub *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (cub->map[x][0] != '\0')
	{
		while (cub->map[x][y] != '\0')
		{
			if (ft_strchr("NSWE", cub->map[x][y]))
			{
				cub->sprite_x = x;
				cub->sprite_y = y;
				return (1);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int		edgebound(char **map, int i, int j)
{
	return (ft_strchr("0123", map[i][j - 1]) && ft_strchr("0123", map[i][j]) &&
			ft_strchr("0123", map[i][j + 1]) ? 1 : 0);
}

int		midbound(char **map, int i, int j)
{
	return (ft_strchr("0123", map[i][j - 1]) &&
			ft_strchr("0123", map[i][j + 1]) ? 1 : 0);
}

int				floodfill_map(char **map, int x, int y)
{
	if (!ft_strchr("0123", map[x][y]))
	{
		ft_printf("ok\n");
		return (print_error(10));
	}
	else if (map[x][y] == '1')
		return (1);
	else if (!edgebound(map, x - 1, y) || !edgebound(map, x + 1, y) ||
			!midbound(map, x, y))
		return (print_error(11));
	else if (ft_strchr("023", map[x][y]))
	{
		if (!floodfill_map(map, x, y + 1))
			return (0);
		if (!floodfill_map(map, x, y - 1))
			return (0);
		if (!floodfill_map(map, x + 1, y))
			return (0);
		if (!floodfill_map(map, x - 1, y))
			return (0);
		return (1);
	}
	return (0);
}

int				valid_map(t_cub *cub)
{
	int k;

	k = 0;
	if (!find_spawnpoint(cub))
		return (print_error(9));
	cub->map[cub->sprite_x][cub->sprite_y] = '3';
	if (!floodfill_map(cub->map, cub->sprite_x, cub->sprite_y))
		return (print_error(10));
	return (1);
}
