/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 15:33:16 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/25 21:15:05 by nhariman      ########   odam.nl         */
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
** if ONLY a '\n' (map[i][0]) is found after the map ended,
** that counts as an error as only ' ' 012 are valid map characters.
** ONLY THE MAP THE PLAYER AS ACCESS TO HAS TO BE CLOSED.
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
				if (x == 0)
					return (print_error(30));
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

static void			get_sprite_locations(t_cub *cub)
{
	if (cub->spawn_pos == 'N')
		floodfill_no(cub, cub->spawn_x, cub->spawn_y, cub->sprites - 1);
	else if (cub->spawn_pos == 'S')
		floodfill_so(cub, cub->spawn_x, cub->spawn_y, cub->sprites - 1);
	else if (cub->spawn_pos == 'W')
		floodfill_we(cub, cub->spawn_x, cub->spawn_y, cub->sprites - 1);
	else if (cub->spawn_pos == 'E')
		floodfill_ea(cub, cub->spawn_x, cub->spawn_y, cub->sprites - 1);
}

int			map_len(char **map, int type)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	tmp = 0;
	if (type == MAP_HEIGHT)
	{
		while (map[i][0] != '\0')
			i++;
	}
	else if (type == MAP_WIDTH)
	{
		while (map[i][0] != '\0')
		{
			tmp = ft_strlen(map[i]);
			if (tmp > j)
				j = tmp;
			i++;
		}
	}
	return (type == MAP_HEIGHT ? i : j);
}

static void			find_sprites(t_cub *cub)
{
	count_sprites(cub);
	if (cub->sprites > 0)
	{
		cub->sp.sprites = ft_calloc(cub->sprites, sizeof(t_sp_lst));
		get_sprite_locations(cub);
	}
}

int					valid_map(t_cub *cub)
{
	int success;

	success = 1;
	if (map_len(cub->map, MAP_HEIGHT) > 1200 ||
		map_len(cub->map, MAP_WIDTH) > 1200)
		return (print_error(29));
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
	find_sprites(cub);
	cub->map[cub->spawn_x][cub->spawn_y] = cub->spawn_pos;
	return (1);
}
