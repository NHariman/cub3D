/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 15:33:16 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/26 00:00:52 by nhariman      ########   odam.nl         */
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

static int			find_spawnpoint(t_cub *cub, int *success)
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
				cub->sprite_pos = cub->map[x][y];
				cub->map[cub->sprite_x][cub->sprite_y] = '3';
				floodfill_map(cub->map, success, cub->sprite_x, cub->sprite_y);
				if (*success == 1)
					return (1);
				*success = 1;
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (print_error(10));
}

int					edgebound(char **map, int i, int j)
{
	return (!ft_strchr(" ", map[i][j - 1]) &&
			!ft_strchr(" ", map[i][j]) &&
			!ft_strchr(" ", map[i][j + 1]) ? 1 : 0);
}

int					midbound(char **map, int i, int j)
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

int					valid_map(t_cub *cub)
{
	int success;

	success = 1;
	if (!find_spawnpoint(cub, &success))
		return (print_error(9));
	return (1);
}
