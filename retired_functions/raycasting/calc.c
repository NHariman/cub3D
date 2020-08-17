/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 17:53:36 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/15 20:19:58 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void			calc_camray(t_camera *cam)
{
	cam->raydirx = cam->dirx + cam->planex * cam->camerax;
	cam->raydiry = cam->diry + cam->planey * cam->camerax;
	cam->ray.mapx = cam->cub->spawn_y;
	cam->ray.mapy = cam->cub->spawn_x;
	cam->ray.hit = 0;
	cam->ray.deltadistx = fabs(1 / cam->raydirx);
	cam->ray.deltadisty = fabs(1 / cam->raydiry);
	//cam->ray.side = 0;
}

	// cam->ray.stepx = cam->raydirx < 0 ? -1 : 1;
	// cam->ray.sidedistx = cam->raydirx < 0 ?
	// 	(cam->posx - cam->ray.mapx) * cam->ray.deltadistx :
	// 		(cam->ray.mapx + 1.0 - cam->posx) * cam->ray.deltadistx;
	// cam->ray.stepy = cam->raydiry < 0 ? -1 : 1;
	// cam->ray.sidedisty = cam->raydiry < 0 ?
	// 	(cam->posy - cam->ray.mapy) * cam->ray.deltadisty :
	// 			(cam->ray.mapy + 1.0 - cam->posy) * cam->ray.deltadisty;

void			calc_step_and_sidedist(t_camera *cam)
{
	if (cam->raydirx < 0)
	{
		cam->ray.stepx = -1;
		cam->ray.sidedistx = (cam->posx - cam->ray.mapx) * cam->ray.deltadistx;
	}
	else
	{
		cam->ray.stepx = 1;
		cam->ray.sidedistx = (cam->ray.mapx + 1.0 - cam->posx) * cam->ray.deltadistx;
	}
	if (cam->raydiry < 0)
	{
		cam->ray.stepy = -1;
		cam->ray.sidedisty = (cam->posy - cam->ray.mapy) * cam->ray.deltadisty;
	}
	else
	{
		cam->ray.stepy = 1;
		cam->ray.sidedisty = (cam->ray.mapy + 1.0 - cam->posy) * cam->ray.deltadisty;
	}
}

void			calc_dda(t_camera *cam)
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
		if (cam->cub->map[cam->cub->spawn_x][cam->cub->spawn_y] == '1')
			cam->ray.hit = 1;
	}
}

	// cam->ray.perpwalldist = cam->ray.side == 0 ?
	// 		(cam->ray.mapx - cam->posx +
	// 			(1 - cam->ray.stepx) / 2) / cam->raydirx :
	// 		(cam->ray.mapy - cam->posy +
	// 			(1 - cam->ray.stepy) / 2) / cam->raydiry;
void			calc_camwalldist(t_camera *cam)
{
	if (cam->ray.side == 0)
	{
		cam->ray.perpwalldist = (cam->ray.mapx - cam->posx + (1 - cam->ray.stepx) / 2) / cam->raydirx;
	}
	else
		cam->ray.perpwalldist = (cam->ray.mapy - cam->posy + (1 - cam->ray.stepy) / 2) / cam->raydiry;
}

void			calc_line(t_camera *cam, int y)
{
	cam->draw.lineheight = y / cam->ray.perpwalldist;
	cam->draw.start = (-cam->draw.lineheight / 2 + (y / 2));
	if (cam->draw.start < 0)
		cam->draw.start = 0;
	cam->draw.end = (cam->draw.lineheight / 2 + (y / 2));
	if (cam->draw.end >= y)
		cam->draw.end = y - 1;
}
