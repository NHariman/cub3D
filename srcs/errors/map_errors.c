/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_errors.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 17:55:08 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/26 20:09:43 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int			ft_map_len(char **map, int type)
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

static int	check_row(char **map, int i, int j, int *sprite)
{
	if (!ft_strchr(" 012NSWE\n", map[i][j]))
		return (0);
	if (ft_strchr("NSWE", map[i][j]))
	{
		if (*sprite == 1)
		{
			ft_show_map(map);
			return (ft_print_error(16));
		}
		*sprite = 1;
	}
	return (1);
}

int			ft_check_noise(char **map)
{
	int i;
	int j;
	int sprite;

	i = 0;
	j = 0;
	sprite = 0;
	while (map[i][0] != '\0')
	{
		if (map[i][0] == '\n' && i < ft_map_len(map, MAP_HEIGHT))
		{
			ft_print_error(8);
			ft_show_map(map);
			return (0);
		}
		while (map[i][j] != '\0')
		{
			if (!check_row(map, i, j, &sprite))
				return (ft_print_error(12));
			j++;
		}
		j = 0;
		i++;
	}
	return (map[0][0] == '\0' ? ft_print_error(27) : 1);
}
