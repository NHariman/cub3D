/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_texture.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/03 11:42:51 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void			ft_step_raycasting(t_struct_m *main)
{
	if (main->ray.raydirx < 0)
	{
		main->ray.stepx = -1;
		main->ray.sidedistx = (main->ray.posx - main->ray.mapx)
		* main->ray.deltadistx;
	}
	else
	{
		main->ray.stepx = 1;
		main->ray.sidedistx = (main->ray.mapx + 1.0 - main->ray.posx)
		* main->ray.deltadistx;
	}
	if (main->ray.raydiry < 0)
	{
		main->ray.stepy = -1;
		main->ray.sidedisty = (main->ray.posy - main->ray.mapy)
		* main->ray.deltadisty;
	}
	else
	{
		main->ray.stepy = 1;
		main->ray.sidedisty = (main->ray.mapy + 1.0 - main->ray.posy)
		* main->ray.deltadisty;
	}
}

static void			ft_location(t_struct_m *main)
{
	main->ray.camerax = 2 * main->ray.x / (double)main->place.s_width - 1;
	main->ray.raydirx = main->ray.dirx + main->ray.planex * main->ray.camerax;
	main->ray.raydiry = main->ray.diry + main->ray.planey * main->ray.camerax;
	main->ray.mapx = (int)main->ray.posx;
	main->ray.mapy = (int)main->ray.posy;
	main->ray.hit = 0;
	main->ray.deltadistx = fabs(1 / main->ray.raydirx);
	main->ray.deltadisty = fabs(1 / main->ray.raydiry);
}

static void			ft_raycasting_hit(t_struct_m *main)
{
	while (main->ray.hit == 0)
	{
		if (main->ray.sidedistx < main->ray.sidedisty)
		{
			main->ray.sidedistx += main->ray.deltadistx;
			main->ray.mapx += main->ray.stepx;
			main->ray.side = 0;
		}
		else
		{
			main->ray.sidedisty += main->ray.deltadisty;
			main->ray.mapy += main->ray.stepy;
			main->ray.side = 1;
		}
		if (main->place.cubemap[main->ray.mapy][main->ray.mapx] == '1')
			main->ray.hit = 1;
	}
	if (main->ray.side == 0)
		main->ray.perpwalldist = ((main->ray.mapx - main->ray.posx + (1 -
		main->ray.stepx) / 2) / main->ray.raydirx);
	else
		main->ray.perpwalldist = ((main->ray.mapy - main->ray.posy + (1 -
		main->ray.stepy) / 2) / main->ray.raydiry);
}

int					ft_raycasting(t_struct_m *main)
{
	main->ray.x = 0;
	while (main->ray.x < main->place.s_width)
	{
		ft_location(main);
		ft_step_raycasting(main);
		ft_raycasting_hit(main);
		main->ray.lineheight = (int)(main->place.s_height /
		main->ray.perpwalldist);
		main->ray.drawstart = (-main->ray.lineheight / 2 +
		(main->place.s_height / 2));
		if (main->ray.drawstart < 0)
			main->ray.drawstart = 0;
		main->ray.drawend = (main->ray.lineheight / 2 +
		(main->place.s_height / 2));
		if (main->ray.drawend >= main->place.s_height)
			main->ray.drawend = main->place.s_height - 1;
		verline_structure(main);
		main->zbuffer[main->ray.x] = main->ray.perpwalldist;
		main->ray.x++;
	}
	return (0);
}
