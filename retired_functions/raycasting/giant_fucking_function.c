/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   giant_fucking_function.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/15 21:09:28 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/15 23:19:57 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void        giant_fucking_function(t_camera *cam)
{
	int x;

	x = 0;
	//setup_camray
	while (x < cam->cub->res_x)
	{
		cam->camerax = 2 * x / (double)cam->cub->res_x - 1;
		//calc_camray
		cam->raydirx = cam->dirx + cam->planex * cam->camerax;
		cam->raydiry = cam->diry + cam->planey * cam->camerax;
		cam->ray.mapx = cam->cub->spawn_y;
		cam->ray.mapy = cam->cub->spawn_x;
		cam->ray.hit = 0;
		cam->ray.deltadistx = fabs(1 / cam->raydirx);
		cam->ray.deltadisty = fabs(1 / cam->raydiry);
		//calc_step_and_sidedist
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
		//calc_dda(cam);
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
		//calc_camwalldist(cam);
		if (cam->ray.side == 0)
		{
			cam->ray.perpwalldist = (cam->ray.mapx - cam->posx + (1 - cam->ray.stepx) / 2) / cam->raydirx;
		}
		else
			cam->ray.perpwalldist = (cam->ray.mapy - cam->posy + (1 - cam->ray.stepy) / 2) / cam->raydiry;
		//calc_line(cam, cam->cub->res_y);
		cam->draw.lineheight = cam->cub->res_y / cam->ray.perpwalldist;
		cam->draw.start = (-cam->draw.lineheight / 2 + (cam->cub->res_y / 2));
		if (cam->draw.start < 0)
			cam->draw.start = 0;
		cam->draw.end = (cam->draw.lineheight / 2 + (cam->cub->res_y / 2));
		if (cam->draw.end >= cam->cub->res_y)
			cam->draw.end = cam->cub->res_y - 1;
		//calc_textures(cam, x);
		if (cam->ray.side == 0)
			cam->wall.wallx = cam->posy + cam->ray.perpwalldist * cam->raydiry;
		else
			cam->wall.wallx = cam->posx + cam->ray.perpwalldist * cam->raydirx;
		cam->wall.wallx -= floor(cam->wall.wallx);
		//calc_texty
		while (cam->draw.start < cam->draw.end)
		{
			ft_printf("lol");
			//my_mlx_pixel_put(&cam->mlx.img, x, cam->draw.start, 14443600);
			cam->draw.start++;
		}
		//add zbuffer later for sprite management
		x++;
	}
}
