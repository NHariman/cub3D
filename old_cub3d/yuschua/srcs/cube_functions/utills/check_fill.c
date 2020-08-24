/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 11:13:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/27 19:50:28 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int		check_fill_bottom(t_struct_m *main)
{
	int	x;
	int	y;

	y = main->ray.yy;
	y--;
	x = 0;
	while (main->cubecopy[y][x])
	{
		if (main->cubecopy[y][x] == 'X')
		{
			main->place.error = 15;
			ft_error(main);
			return (1);
		}
		x++;
	}
	return (0);
}

static int		check_fill_top(t_struct_m *main)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (main->cubecopy[0][x])
	{
		if (main->cubecopy[0][x] == 'X')
		{
			main->place.error = 15;
			ft_error(main);
			return (1);
		}
		x++;
	}
	return (0);
}

static	int		check_fill_left(t_struct_m *main)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < main->ray.yy)
	{
		if (main->cubecopy[y][x] == 'X')
		{
			main->place.error = 16;
			ft_error(main);
			return (1);
		}
		y++;
	}
	return (0);
}

static int		check_fill_right(t_struct_m *main)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	x = (ft_strlen(main->cubecopy[y]) - 1);
	while (y < main->ray.yy)
	{
		if (main->cubecopy[y][x] == 'X')
		{
			main->place.error = 17;
			ft_error(main);
			return (1);
		}
		y++;
	}
	return (0);
}

int				check_fill(t_struct_m *main)
{
	int	x;
	int	y;

	x = (int)(main->ray.posx);
	y = (int)(main->ray.posy);
	main->cubecopy[y][x] = '0';
	flood_fill(x, y, main);
	x = 0;
	if (check_fill_right(main) == 1 || check_fill_left(main) == 1
	|| check_fill_top(main) == 1 || check_fill_bottom(main) == 1)
		x = 1;
	if (check_valid_x(main) == 1)
		x = 1;
	return (x);
}
