/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 15:33:16 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/17 22:41:48 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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

static void			fill_spawn_pos(t_cub *cub, int y, int x)
{
	cub->spawn_x = x;
	cub->spawn_y = y;
	cub->spawn_pos = cub->map[x][y];
	cub->map[cub->spawn_x][cub->spawn_y] = '3';
}

static int			find_spawnpoint(t_cub *cub)
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
				fill_spawn_pos(cub, y, x);
				return (1);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (print_error(10));
}

void				count_sprites(t_cub *cub)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (cub->cpmap[y][0] != '\0')
	{
		while (cub->cpmap[y][x] != '\0')
		{
			if (cub->cpmap[y][x] == '2')
				cub->sprites++;
			x++;
		}
		x = 0;
		y++;
	}
}

int					valid_map(t_cub *cub)
{
	int success;

	success = 1;
	if (!check_noise(cub->map))
		return (0);
	if (!find_spawnpoint(cub))
		return (print_error(9));
	floodfill_map(cub->map, &success, cub->spawn_x, cub->spawn_y);
	if (success == 0)
	{
		show_map(cub->map);
		return (0);
	}
	count_sprites(cub);
	cub->map[cub->spawn_x][cub->spawn_y] = cub->spawn_pos;
	return (1);
}
