/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 14:09:41 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/03 11:54:49 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void			check_map_symbol(t_struct_m *main, char *map)
{
	if (ft_strnstr_map(map, "R ", ft_strlen(map)) == 1)
		ft_read_r(main, map);
	else if (ft_strnstr_map(map, "SO ", ft_strlen(map)) == 1)
		ft_read_so(main, map);
	else if (ft_strnstr_map(map, "S ", ft_strlen(map)) == 1)
		ft_read_s(main, map);
	else if (ft_strnstr_map(map, "NO ", ft_strlen(map)) == 1)
		ft_read_no(main, map);
	else if (ft_strnstr_map(map, "EA ", ft_strlen(map)) == 1)
		ft_read_ea(main, map);
	else if (ft_strnstr_map(map, "WE ", ft_strlen(map)) == 1)
		ft_read_we(main, map);
	else if (ft_strnstr_map(map, "F ", ft_strlen(map)) == 1)
		ft_read_f(main, map);
	else if (ft_strnstr_map(map, "C ", ft_strlen(map)) == 1)
		ft_read_c(main, map);
	else if (map[0] == '\0')
		map[0] = '\0';
	else
	{
		main->place.error = 49;
		ft_error(main);
	}
}

static int		ft_check_empty_line_check(char *map)
{
	int		i;

	i = 0;
	while (map[i] == ' ')
		i++;
	if (map[i] != '\0')
		return (0);
	else
		return (1);
}

int				ft_read_map_where(t_struct_m *main, char *map)
{
	if (ft_get_info(main, map) == 2)
	{
		return (2);
	}
	return (0);
}

static int		ft_read_mapp(t_struct_m *main, char *map, int count, int fd)
{
	while (count > 0)
	{
		count = get_next_line(fd, &map);
		if (count < 0)
		{
			main->place.error = 24;
			ft_error(main);
			free(map);
			return (2);
		}
		if (ft_clutter(main, map) == 2)
			;
		if (ft_check_for_map(map) == 1)
			main->ii = 1;
		if (main->ii != 1)
		{
			main->ray.yyy++;
			if (ft_check_empty_line_check(map) != 1
			&& ft_read_map_where(main, map) == 2)
				main->i = 2;
		}
		free(map);
	}
	return (0);
}

int				ft_read_map(t_struct_m *main)
{
	int		count;
	int		fd;
	char	*map;

	main->i = 0;
	main->ii = 0;
	count = 1;
	main->ray.yyy = 0;
	map = NULL;
	fd = open(main->map, O_RDONLY);
	if (ft_error_map(main, fd) < 0)
		return (2);
	if (ft_read_mapp(main, map, count, fd) == 2)
		return (2);
	if (main->i == 2)
		return (2);
	return (0);
}
