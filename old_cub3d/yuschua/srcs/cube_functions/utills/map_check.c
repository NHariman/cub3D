/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 11:53:18 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/27 19:51:14 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int			if_empty(int x, int y, t_struct_m *main)
{
	if (y < 0 || x < 0)
		return (0);
	else if (main->cubecopy[y][x] == ' ')
	{
		main->place.error = 18;
		ft_error(main);
		return (0);
	}
	return (1);
}

int			ft_check_empty(int x, int y, t_struct_m *main)
{
	if (if_empty(x - 1, y, main) == 0)
		return (0);
	if (if_empty(x + 1, y, main) == 0)
		return (0);
	if (if_empty(x, y + 1, main) == 0)
		return (0);
	if (if_empty(x, y - 1, main) == 0)
		return (0);
	if (if_empty(x + 1, y + 1, main) == 0)
		return (0);
	if (if_empty(x - 1, y - 1, main) == 0)
		return (0);
	if (if_empty(x - 1, y + 1, main) == 0)
		return (0);
	if (if_empty(x + 1, y - 1, main) == 0)
		return (0);
	return (0);
}

void		flood_fill(int x, int y, t_struct_m *main)
{
	if (x < 0 || y < 0 || y == main->ray.yy ||
	x == main->ray.xx)
	{
		main->place.error = 15;
		return ;
	}
	if (main->cubecopy[y][x] == '1')
		return ;
	if (main->cubecopy[y][x] != '0' &&
	main->cubecopy[y][x] != '2')
		return ;
	main->cubecopy[y][x] = 'X';
	flood_fill(x + 1, y, main);
	flood_fill(x, y + 1, main);
	flood_fill(x - 1, y, main);
	flood_fill(x, y - 1, main);
	flood_fill(x + 1, y + 1, main);
	flood_fill(x - 1, y - 1, main);
	flood_fill(x + 1, y - 1, main);
	flood_fill(x - 1, y + 1, main);
}
