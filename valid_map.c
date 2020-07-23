/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 15:33:16 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/23 02:16:37 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

static int		edgebound(char **map, int i, int j)
{
	ft_printf("1: %i\n2: %i\n3: %i\n", map[i][j - 1], map[i][j], map[i][j + 1]);
	if (map[i][j - 1] == ' ' || map[i][j] == ' ' ||
	map[i][j + 1] == ' ')
		return (0);
	return (1);
}

static int		midbound(char **map, int i, int j)
{
	return (map[i][j - 1] != ' ' && map[i][j + 1] != ' ' ? 1 : 0);
}

static int		valid_middle(char **map, int i, t_check *check)
{
	int start;
	int end;

	start = 0;
	end = ft_strlen(map[i]) - 2;
	while (map[i][start] == ' ')
		start++;
	while (map[i][end] == ' ')
		end--;
	if (map[i][start] != '1' || map[i][end] != '1')
		return (0);
	while (map[i][start] != '\0')
	{
		if (map[i][start] == 0 || map[i][start] == 2)
			if (!edgebound(map, i + 1, start) && !midbound(map, i, start) &&
			!edgebound(map, i - 1, start))
				return (0);
		if (ft_strchr("NSWE", map[i][start]) && !check->sprite_pos)
			check->sprite_pos = 1;
		else if (ft_strchr("NSWE", map[i][start]) && check->sprite_pos)
			return (0);
		start++;
	}
	return (1);
}

int		valid_map(char **map, int maplen, t_check *check)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i][0] != '\0')
	{
		if (map[i][0] == '\n')
			return (0);
		if (i == 0 || i == maplen - 1)
		{
			if (!valid_edge(map[i]))
				return (0);
		}
		else
		{
			if (!valid_middle(map, i, check))
				return (0);
		}
		i++;
	}
	return (1);
}
