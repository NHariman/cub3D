/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utills_five.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 18:50:30 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/20 09:54:16 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int			ft_error_map(t_struct_m *main, int fd)
{
	fd = open(main->map, O_RDONLY);
	if (fd < 0)
	{
		main->place.error = 24;
		ft_error(main);
		return (-2);
	}
	return (fd);
}

void		read_map_bmp(t_struct_m *main)
{
	if (ft_size_store_map(main) == 1)
	{
		ft_putstr("error\nsize store error");
		ft_end_function(main);
	}
	check_value(main);
	check_screen_bmp(main);
	set_location(main);
	spritesnumb(main);
	if (check_fill(main) == 1)
	{
		ft_putstr("error\nerror in check_fill");
		ft_end_function(main);
	}
	printmap(main);
	if (main->place.error_n == 0)
	{
		ft_putstr("error\nerror after map print");
		ft_end_function(main);
	}
}

void		check_screen_bmp(t_struct_m *main)
{
	if (main->place.s_height > 16384)
		main->place.s_height = 16384;
	if (main->place.s_width > 16384)
		main->place.s_width = 16384;
	if (main->place.s_height <= 0 || main->place.s_width <= 0)
	{
		main->place.error = 53;
		ft_error(main);
		ft_end_function(main);
	}
}

int			ft_strnstr_cub(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!(*needle))
		return (0);
	i = 0;
	i = ft_strlen(haystack);
	i = i - 4;
	j = 0;
	while (j <= 4)
	{
		if (haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		else
		{
			ft_putstr("error\nmust have .cub at the end");
			return (1);
		}
	}
	return (0);
}

void		check_screen(t_struct_m *main)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx_get_screen_size(main->vars.mlx, &x, &y);
	if (main->place.s_width > x)
		main->place.s_width = x;
	if (main->place.s_height > y)
		main->place.s_height = y;
	if (main->place.s_height <= 0 || main->place.s_width <= 0)
	{
		main->place.error = 53;
		ft_error(main);
		ft_end_function(main);
	}
}
