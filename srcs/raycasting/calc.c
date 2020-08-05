/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 17:53:36 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/05 21:57:07 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void			calc_camray(t_cub *cub, t_camera *cam)
{
	cam->raydirx = cam->dirx + cam->planex * cam->camerax;
	cam->raydiry = cam->diry + cam->planey * cam->camerax;
	cam->ray.deltadistx = fabs(1 / cam->raydirx);
	cam->ray.deltadisty = fabs(1 / cam->raydiry);
	cam->ray.mapx = cub->spawn_x;
	cam->ray.mapy = cub->spawn_y;
	cam->ray.hit = 0;
	cam->ray.side = 0;
}

void			calc_step_and_sidedist(t_camera *cam)
{
	cam->ray.stepx = cam->raydirx < 0 ? -1 : 1;
	cam->ray.sidedistx = cam->raydirx < 0 ?
		(cam->posx - cam->ray.mapx) * cam->ray.deltadistx :
			(cam->ray.mapx + 1.0 - cam->posx) * cam->ray.deltadistx;
	cam->ray.stepy = cam->raydiry < 0 ? -1 : 1;
	cam->ray.sidedisty = cam->raydiry < 0 ?
		(cam->posy - cam->ray.mapy) * cam->ray.deltadisty :
				(cam->ray.mapy + 1.0 - cam->posy) * cam->ray.deltadisty;
}

void			calc_dda(t_camera *cam, t_cub *cub)
{
	while (cam->ray.hit == 0)
	{
		if (cam->ray.sidedistx < cam->ray.sidedisty)
		{
			cam->ray.sidedistx += cam->ray.deltadistx;
			cam->ray.mapx += cam->ray.stepx;
			cam->ray.side = 0;
		}
		else
		{
			cam->ray.sidedisty += cam->ray.deltadisty;
			cam->ray.mapy += cam->ray.stepy;
			cam->ray.side = 1;
		}
		if (cub->map[cub->spawn_y][cub->spawn_x] == '1')
			cam->ray.hit = 1;
	}
}

void			calc_camwalldist(t_camera *cam)
{
	cam->ray.perpwalldist = cam->ray.side == 0 ?
			(cam->ray.mapx - cam->posx +
				(1 - cam->ray.stepx) / 2) / cam->raydirx :
			(cam->ray.mapy - cam->posy +
				(1 - cam->ray.stepy) / 2) / cam->raydiry;
}

void			calc_line(t_camera *cam, int y)
{
	cam->draw.lineheight = y / cam->ray.perpwalldist;
	cam->draw.start = -cam->draw.lineheight / 2 + y / 2;
	if (cam->draw.start < 0)
		cam->draw.start = 0;
	cam->draw.end = cam->draw.lineheight / 2 + y / 2;
	if (cam->draw.end >= y)
		cam->draw.end = y - 1;
}
