/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_errors.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 17:55:08 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/24 21:47:46 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int			ft_maplen(char **map)
{
	int i;

	i = 0;
	while (map[i][0] != '\0')
		i++;
	return (i);
}

static int	check_row(char **map, int i, int j, int *sprite)
{
	if (!ft_strchr(" 012NSWE\n", map[i][j]))
		return (0);
	if (ft_strchr("NSWE", map[i][j]))
	{
		if (*sprite == 1)
		{
			show_map(map);
			return (print_error(16));
		}
		*sprite = 1;
	}
	return (1);
}

int			check_noise(char **map)
{
	int i;
	int j;
	int sprite;

	i = 0;
	j = 0;
	sprite = 0;
	while (map[i][0] != '\0')
	{
		if (map[i][0] == '\n' && i < ft_maplen(map))
		{
			print_error(8);
			show_map(map);
			return (0);
		}
		while (map[i][j] != '\0')
		{
			if (!check_row(map, i, j, &sprite))
				return (print_error(12));
			j++;
		}
		j = 0;
		i++;
	}
	return (map[0][0] == '\0' ? print_error(27) : 1);
}
