/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   space_cubemap.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 11:49:54 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/01 13:25:14 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static int			ft_substr_save(char *map, t_struct_m *main, int y)
{
	size_t	i;

	if (!map)
		return (1);
	main->place.cubemap[y] = NULL;
	main->cubecopy[y] = NULL;
	main->place.cubemap[y] = (char *)malloc((main->ray.xx + 1) * sizeof(char));
	main->cubecopy[y] = (char *)malloc((main->ray.xx + 1) * sizeof(char));
	if (!main->place.cubemap[y] || !main->cubecopy[y])
		return (1);
	ft_fill_empty_string(main, y);
	i = 0;
	while (map[i])
	{
		main->place.cubemap[y][i] = (char)map[i];
		main->cubecopy[y][i] = (char)map[i];
		i++;
	}
	return (0);
}

static int			ft_print_map_read(t_struct_m *main, char *map,
int count, int fd)
{
	int		y;
	int		yy;
	int		yyy;

	y = main->ray.yyy;
	yy = main->ray.yy;
	yyy = 0;
	while (count > 0)
	{
		count = get_next_line(fd, &map);
		if (y != 0)
			y--;
		else if (yy != 0)
		{
			yy--;
			if (ft_substr_save(map, main, yyy) == 1)
				return (-2);
			yyy++;
		}
		free(map);
	}
	return (0);
}

static int			ft_print_map(t_struct_m *main)
{
	int		count;
	int		fd;
	char	*map;

	count = 1;
	map = NULL;
	fd = open(main->map, O_RDONLY);
	if (fd < 0)
	{
		main->place.error = 24;
		ft_error(main);
	}
	if (ft_print_map_read(main, map, count, fd) == -2)
		return (1);
	return (0);
}

void				space_cubemap(t_struct_m *main)
{
	main->place.cubemap = (char**)malloc(sizeof(char*) * (main->ray.yy));
	main->cubecopy = (char**)malloc(sizeof(char*) * (main->ray.yy));
	if (!main->place.cubemap || !main->cubecopy)
	{
		main->place.error = 13;
		ft_error(main);
	}
	if (ft_print_map(main) == 1)
	{
		main->place.error = 13;
		ft_error(main);
	}
}
