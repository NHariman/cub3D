/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functions_pfour.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 18:50:30 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/20 11:37:35 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int				ft_map_line_get_x(char *map)
{
	int		x;

	x = 0;
	while (map[x])
		x++;
	return (x);
}

int				ft_map_line(t_struct_m *main, char *map)
{
	int		x;

	x = 0;
	while (map[x])
	{
		if (map[x] == 'N' || map[x] == 'S' || map[x] == 'E' || map[x] == 'W')
			main->place.mapp++;
		if (main->place.mapp > 1)
			return (1);
		x++;
	}
	return (0);
}

void			ft_fill_empty_string(t_struct_m *main, int y)
{
	int		x;

	x = 0;
	while (x <= main->ray.xx)
	{
		main->place.cubemap[y][x] = ' ';
		main->cubecopy[y][x] = ' ';
		x++;
	}
	main->place.cubemap[y][main->ray.xx] = '\0';
	main->cubecopy[y][main->ray.xx] = '\0';
}

int				ft_strncmp_map(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!(*needle))
		return (0);
	i = 0;
	i = ft_strlen(haystack);
	i = i - 6;
	j = 0;
	while (j <= 6)
	{
		if (haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		else
			return (1);
	}
	return (0);
}

int				error_r(t_struct_m *main, int y)
{
	if (y == 2)
	{
		main->place.error = 3;
		ft_error(main);
		return (-2);
	}
	return (0);
}
