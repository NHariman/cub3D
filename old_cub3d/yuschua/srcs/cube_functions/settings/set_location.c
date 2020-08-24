/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_location.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/03 11:43:30 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int		set_location_w(t_struct_m *main, int r)
{
	r = 1;
	main->ray.diry = 0.0;
	main->ray.dirx = -1;
	main->ray.planex = 0.0;
	main->ray.planey = -0.66;
	return (r);
}

static int		set_location_n(t_struct_m *main, int r)
{
	r = 1;
	main->ray.diry = -1;
	main->ray.dirx = 0.0;
	main->ray.planex = 0.66;
	main->ray.planey = 0.0;
	return (r);
}

static int		set_location_s(t_struct_m *main, int r)
{
	r = 1;
	main->ray.diry = 1.0;
	main->ray.dirx = 0.0;
	main->ray.planex = -0.66;
	main->ray.planey = 0.0;
	return (r);
}

static int		set_location_e(t_struct_m *main, int y, int x, int r)
{
	if (main->place.cubemap[y][x] == 'E')
	{
		r = 1;
		main->ray.diry = 0.0;
		main->ray.dirx = 1.0;
		main->ray.planex = 0.0;
		main->ray.planey = 0.66;
	}
	else if (main->place.cubemap[y][x] == 'W')
		r = set_location_w(main, r);
	else if (main->place.cubemap[y][x] == 'S')
		r = set_location_s(main, r);
	else if (main->place.cubemap[y][x] == 'N')
		r = set_location_n(main, r);
	return (r);
}

void			set_location(t_struct_m *main)
{
	int		r;
	int		y;
	int		x;

	r = 0;
	y = 0;
	x = 0;
	while (r != 1)
	{
		while (main->place.cubemap[y][x] != '\0' && r != 1)
		{
			r = set_location_e(main, y, x, r);
			x++;
		}
		if (r == 1)
			break ;
		x = 0;
		y++;
	}
	main->ray.posy = y;
	main->ray.posx = x;
	main->ray.posy += 0.5;
	main->ray.posx -= 0.5;
}
