/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_map.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 14:08:37 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/20 09:52:34 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

int				get_size_map(t_struct_m *main, char *map)
{
	int		x;

	x = 0;
	if (ft_map_line(main, map) == 1)
	{
		main->place.error = 48;
		ft_error(main);
		return (1);
	}
	x = ft_map_line_get_x(map);
	if (x > main->ray.xx)
		main->ray.xx = x;
	return (0);
}

static int		ft_size_store_map_readd(t_struct_m *main, char *map)
{
	if ((ft_check_for_map(map) == 1 && main->ray.eh > 0) || (map[0] == '\0'))
	{
		main->place.error = 47;
		ft_error(main);
		return (-2);
	}
	main->ray.yy++;
	if (get_size_map(main, map) == 1)
	{
		free(map);
		return (-2);
	}
	return (0);
}

static int		ft_size_store_map_read(t_struct_m *main, char *map,
int fd, int count)
{
	int		y;

	y = main->ray.yyy;
	while (count > 0)
	{
		count = get_next_line(fd, &map);
		if (y != 0)
			y--;
		else
		{
			if (ft_size_store_map_readd(main, map) == -2)
				return (-2);
		}
		free(map);
	}
	return (0);
}

int				ft_size_store_map(t_struct_m *main)
{
	int		fd;
	char	*map;

	main->ray.eh = 0;
	map = NULL;
	fd = open(main->map, O_RDONLY);
	if (fd < 0)
	{
		main->place.error = 24;
		ft_error(main);
	}
	if (ft_size_store_map_read(main, map, fd, 1) == -2)
		return (1);
	if (main->ray.yy <= 0 || main->place.mapp <= 0)
	{
		ft_putstr("error\nno map or no position");
		return (1);
	}
	space_cubemap(main);
	return (0);
}
