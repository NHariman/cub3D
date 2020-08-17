/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 03:21:27 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/17 04:55:29 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		ft_raycasting(t_cub *cub)
{
	int		x;
	//movement
	double	movespeed;
	double	rotspeed;
	double	olddirx;
	double	oldplanex;
	// raycasting starts here
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	sidedistx;
	double	sidedisty;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		colour;

	x = 0;
	//movement
	movespeed = 0.07;
	rotspeed = 0.05;
	if (cub->keys.w == 1)
	{
		if (cub->cpmap[(int)cub->setup.posy]
			[(int)(cub->setup.posx + cub->setup.dirx * movespeed)] != '1')
			cub->setup.posx += cub->setup.dirx * movespeed;
		if (cub->cpmap[(int)(cub->setup.posy + cub->setup.diry * movespeed)]
			[(int)cub->setup.posx] != '1')
			cub->setup.posy += cub->setup.diry * movespeed;
	}
	if (cub->keys.s == 1)
	{
		if (cub->cpmap[(int)cub->setup.posy]
			[(int)(cub->setup.posx - cub->setup.dirx * movespeed)] != '1')
			cub->setup.posx -= cub->setup.dirx * movespeed;
		if (cub->cpmap[(int)(cub->setup.posy - cub->setup.diry * movespeed)]
			[(int)cub->setup.posx] != '1')
			cub->setup.posy -= cub->setup.diry * movespeed;
	}
	if (cub->keys.a == 1)
	{
		if (cub->cpmap[(int)cub->setup.posy]
			[(int)(cub->setup.posx - cub->setup.planex * movespeed)] != '1')
			cub->setup.posx -= cub->setup.planex * movespeed;
		if (cub->cpmap[(int)(cub->setup.posy - cub->setup.planey * movespeed)]
			[(int)cub->setup.posx])
			cub->setup.posy -= cub->setup.planey * movespeed;
	}
	if (cub->keys.d == 1)
	{
		if (cub->cpmap[(int)cub->setup.posy]
			[(int)(cub->setup.posx - cub->setup.planex * movespeed)] != '1')
			cub->setup.posx += cub->setup.planex * movespeed;
		if (cub->cpmap[(int)(cub->setup.posy - cub->setup.planey * movespeed)]
			[(int)cub->setup.posx])
			cub->setup.posy += cub->setup.planey * movespeed;
	}
	if (cub->keys.left == 1)
	{
		olddirx = cub->setup.dirx;
		cub->setup.dirx =
			cub->setup.dirx * cos(rotspeed) - cub->setup.diry * sin(rotspeed);
		cub->setup.diry =
			olddirx * sin(rotspeed) + cub->setup.diry * cos(rotspeed);
		oldplanex = cub->setup.planex;
		cub->setup.planex =
			cub->setup.planex * cos(rotspeed) -
				cub->setup.planey * sin(rotspeed);
		cub->setup.planey =
			oldplanex * sin(rotspeed) + cub->setup.planey * cos(rotspeed);
	}
	if (cub->keys.right == 1)
	{
		olddirx = cub->setup.dirx;
		cub->setup.dirx =
			cub->setup.dirx * cos(-rotspeed) - cub->setup.diry * sin(-rotspeed);
		cub->setup.diry =
			olddirx * sin(-rotspeed) + cub->setup.diry * cos(rotspeed);
		oldplanex = cub->setup.planex;
		cub->setup.planex =
			cub->setup.planex * cos(-rotspeed) -
				cub->setup.planey * sin(-rotspeed);
		cub->setup.planey =
			oldplanex * sin(-rotspeed) + cub->setup.planey * cos(-rotspeed);
	}
	while (x < cub->res_x)
	{
		camerax = 2 * x / (double)cub->res_x - 1;
		raydirx = cub->setup.dirx + cub->setup.planex * camerax;
		raydiry = cub->setup.diry + cub->setup.planey * camerax;
		mapx = (int)cub->setup.posx;
		mapy = (int)cub->setup.posy;
		deltadistx = fabs(1 / raydirx);
		deltadisty = fabs(1 / raydiry);
		hit = 0;
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (cub->setup.posx - mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - cub->setup.posx) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (cub->setup.posy - mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - cub->setup.posy) * deltadisty;
		}
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}
			if (cub->cpmap[mapy][mapx] == '1')
				hit = 1;
		}
		if (side == 0)
			perpwalldist = (mapx - cub->setup.posx + (1 - stepx) / 2) / raydirx;
		else
			perpwalldist = (mapy - cub->setup.posy + (1 - stepy) / 2) / raydiry;
		lineheight = (int)(cub->res_y / perpwalldist);
		drawstart = -lineheight / 2 + cub->res_y / 2;
		if (drawstart < 0)
			drawstart = 0;
		drawend = lineheight / 2 + cub->res_y / 2;
		if (drawend >= cub->res_y)
			drawend = cub->res_y - 1;
		colour = 0;
		while (drawstart < drawend)
		{
			my_mlx_pixel_put(&cub->mlx, x, drawstart, colour);
			drawstart++;
		}
		x++;
	}
}