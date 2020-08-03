/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 15:33:16 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/03 21:15:26 by nhariman      ########   odam.nl         */
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
** if characters are found after they are considered improper maps.
** WARNING: ONLY THE MAP THE PLAYER AS ACCESS TO HAS TO BE CLOSED. AKA. FLOODFILL
** STARTING FROM SPAWN POINT!!
*/

static int		valid_edge(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_strchr(" 1\n", str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void		find_outerbounds(t_map *v_map, char *str)
{
	v_map->start = 0;
	v_map->end = ft_strlen(str) - 2;
	while (str[v_map->start] == ' ')
		v_map->start++;
	while (str[v_map->end] == ' ')
		v_map->end--;
}

static int		valid_middle(char **map, int i, t_check *check)
{
	t_map v_map;

	find_outerbounds(&v_map, map[i]);
	ft_printf("check: check: %i\n", check->sprite_pos);
	check->sprite_pos = 0;
	if (map[i][v_map.start] != '1' || map[i][v_map.end] != '1')
		return (0);
	while (map[i][v_map.start] != '\0')
	{
		if (!ft_strchr(" 102NSWE\n", map[i][v_map.start]))
			return (0);
		else if (ft_strchr("02NSWE", map[i][v_map.start]))
		{
			if (ft_strchr("NSWE", map[i][v_map.start]) && check->sprite_pos)
				return (0);
			else if (!valid_neighbors(map, i, v_map.start, &check->sprite_pos))
				return (0);
		}
		v_map.start = v_map.start + 1;
	}
	return (1);
}

int				valid_leftovers(char **map, int i)
{
	int j;

	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j] == ' ')
			j++;
		if (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '\n')
			return (0);
		else if (map[i][j] == '1')
		{
			if (!is_connected(map, i, j))
				return (0);
		}
		j++;
	}
	return (1);
}

int				valid_map(char **map, t_check *check)
{
	int		i;
	int		map_end;

	i = 1;
	map_end = 0;
	if (!valid_edge(map[0]))
		return (0);
	while (map[i][0] != '\0')
	{
		if (valid_edge(map[i]) && !map_end)
			map_end = 1;
		else if (map_end == 0)
		{
			if (!valid_middle(map, i, check))
				return (0);
		}
		else
		{
			if (!valid_leftovers(map, i))
				return (0);
		}
		i++;
	}
	return (1);
}
