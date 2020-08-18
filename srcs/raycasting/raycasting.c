/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 03:21:27 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/19 00:53:33 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	ft_setup(t_cub *cub)
{
	cub->ray.raydirx =
		cub->set.dirx + cub->set.planex * cub->ray.camerax;
	cub->ray.raydiry =
		cub->set.diry + cub->set.planey * cub->ray.camerax;
	cub->ray.mapx = (int)cub->set.posx;
	cub->ray.mapy = (int)cub->set.posy;
	cub->ray.deltadistx = fabs(1 / cub->ray.raydirx);
	cub->ray.deltadisty = fabs(1 / cub->ray.raydiry);
}

void			get_sprites(t_cub *cub)
{
	cub->sp.zbuffer = ft_calloc(cub->res_x, sizeof(double));
	cub->sp.sp_order = ft_calloc(cub->sprites, sizeof(int));
	cub->sp.sp_dist = ft_calloc(cub->sprites, sizeof(double));
}

/*
** sort sprites:
** the bigger the distance, the more it must be put forward
*/

static void	sortsprites(t_cub *cub)
{
	double		tmp_dist;
	int			tmp_order;
	int			i;

	tmp_dist = 0;
	tmp_order = 0;
	i = 0;
	while (i < cub->sprites)
	{
		if (cub->sp.sp_dist[i] < cub->sp.sp_dist[i + 1])
		{
			tmp_dist = cub->sp.sp_dist[i];
			tmp_order = cub->sp.sp_order[i];
			cub->sp.sp_dist[i] = cub->sp.sp_dist[i + 1];
			cub->sp.sp_order[i] = cub->sp.sp_order[i + 1];
			cub->sp.sp_dist[i + 1] = tmp_dist;
			cub->sp.sp_order[i + 1] = tmp_order;
			i = 0;
		}
		i++;
	}
}

void		ft_raycasting(t_cub *cub)
{
	int		x;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		colour;

	x = 0;
	ft_movement(cub);
	get_sprites(cub);
	while (x < cub->res_x)
	{
		cub->ray.camerax = 2 * x / (double)cub->res_x - 1;
		ft_setup(cub);
		cub->ray.hit = 0;
		ft_calc_side(cub);
		while (cub->ray.hit == 0)
		{
			if (cub->side.sidedistx < cub->side.sidedisty)
			{
				cub->side.sidedistx += cub->ray.deltadistx;
				cub->ray.mapx += cub->side.stepx;
				cub->side.side = 0;
			}
			else
			{
				cub->side.sidedisty += cub->ray.deltadisty;
				cub->ray.mapy += cub->side.stepy;
				cub->side.side = 1;
			}
			if (cub->cpmap[cub->ray.mapy][cub->ray.mapx] == '1')
				cub->ray.hit = 1;
		}
		if (cub->side.side == 0)
			perpwalldist = (cub->ray.mapx - cub->set.posx + (1 - cub->side.stepx) / 2) / cub->ray.raydirx;
		else
			perpwalldist = (cub->ray.mapy - cub->set.posy + (1 - cub->side.stepy) / 2) / cub->ray.raydiry;
		lineheight = (int)(cub->res_y / perpwalldist);
		drawstart = -lineheight / 2 + cub->res_y / 2;
		if (drawstart < 0)
			drawstart = 0;
		drawend = lineheight / 2 + cub->res_y / 2;
		if (drawend >= cub->res_y)
			drawend = cub->res_y - 1;
		int pov;
		if (cub->side.side == 0)
		{
			if (cub->set.posx < cub->ray.mapx)
				pov = SO;
			else
				pov = NO;
		}
		else
		{
			if (cub->set.posy < cub->ray.mapy)
				pov = WE;
			else
				pov = EA;
		}
		double wallx;
		if (cub->side.side == 0)
			wallx = cub->set.posy + perpwalldist * cub->ray.raydiry;
		else
			wallx = cub->set.posx + perpwalldist * cub->ray.raydirx;
		wallx -= floor(wallx);
		int texx;
		texx = (int)(wallx * (double)cub->text[pov].width);
		if (cub->side.side == 0 && cub->ray.raydirx > 0)
			texx = cub->text[pov].width;
		if (cub->side.side == 1 && cub->ray.raydiry < 0)
			texx = cub->text[pov].width;
		double d_step;
		d_step = 1.0 * cub->text[pov].height / lineheight;
		double texpos;
		texpos = (drawstart - cub->res_y / 2 + lineheight / 2) * d_step;
		while (drawstart < drawend)
		{
			int texy;
			texy = (int)texpos & (cub->text[pov].height - 1);
			texpos += d_step;
			colour = cub->text[pov].addr[cub->text[pov].width * texy + texx];
			if (cub->side.side == 1)
				colour = (colour >> 1) & 8355711;
			my_mlx_pixel_put(&cub->mlx, x, drawstart, colour);
			drawstart++;
		}
		cub->sp.zbuffer[x] = perpwalldist;
		x++;
	}
	// this is where sprite stuff starts
	int i;

	i = 0;
	while (i < cub->sprites)
	{
		cub->sp.sp_order[i] = i;
		cub->sp.sp_dist[i] = (pow(cub->set.posx - cub->sp.sprites[i].x, 2) + pow(cub->set.posy - cub->sp.sprites[i].y, 2));
	}
	sortsprites(cub);
	i = 0;
	while (i < cub->sprites)
	{
		cub->sp.spritex = cub->sp.sprites[cub->sp.sp_order[i]].x - cub->set.posx;
		cub->sp.spritey = cub->sp.sprites[cub->sp.sp_order[i]].y - cub->set.posy;
		cub->sp.invdet = 1.0 / (cub->set.planex * cub->set.diry - cub->set.dirx * cub->sp.spritey);
		cub->sp.transformx = cub->sp.invdet * (cub->set.diry * cub->sp.spritex - cub->set.dirx * cub->sp.spritey);
		cub->sp.transformy = cub->sp.invdet * (-cub->set.planey * cub->sp.spritex - cub->set.planex * cub->sp.spritey);
		cub->sp.spritescreenx = (int)(cub->res_x / 2) * (1 + cub->sp.transformx / cub->sp.transformy);
		cub->sp.spriteheight = fabs((int)cub->res_y / (cub->sp.transformy));
		cub->sp.drawstarty = -cub->sp.spriteheight / 2 + cub->res_y / 2;
		if (cub->sp.drawstarty < 0)
			cub->sp.drawstarty = 0;
		cub->sp.drawendy = cub->sp.spriteheight / 2 + cub->res_y / 2;
		if (cub->sp.drawendy >= cub->res_y)
			cub->sp.drawendy = cub->res_y - 1;
		cub->sp.spritewidth = fabs((int)cub->res_y / (cub->sp.transformy));
		cub->sp.drawstartx = -(cub->sp.spritewidth) / 2 + cub->sp.spritescreenx;
		if (cub->sp.drawstartx < 0)
			cub->sp.drawstartx = 0;
		cub->sp.drawendx = cub->sp.spritewidth / 2 + cub->sp.spritescreenx;
		if (cub->sp.drawendx >= cub->res_x)
			cub->sp.drawendx = cub->res_x - 1;
		int stripe;

		stripe = 0;
		while(stripe < cub->sp.drawendx)
		{
			cub->sp.texx = (int)(256 * (stripe - (-cub->sp.spritewidth / 2 + cub->sp.spritescreenx)) * cub->text[SP].width / cub->sp.spritewidth) / 256;
			if (cub->sp.transformy > 0 && stripe > 0 && stripe < cub->res_x && cub->sp.transformy < cub->sp.zbuffer[stripe])
			{
				int y;

				y = cub->sp.drawstarty;
				while (y < cub->sp.drawendy)
				{
					int d;

					d = (y) * 256 - cub->res_y * 128 + cub->sp.spriteheight * 128;
					cub->sp.texy = ((d * cub->text[SP].height) / cub->sp.spriteheight) / 256;
					cub->sp.colour = cub->text[SP].addr[cub->text[SP].width * cub->sp.texy + cub->sp.texx];
					if ((cub->sp.colour & 0x00FFFFFF) != 0)
						my_mlx_pixel_put(&cub->mlx, y, stripe, cub->sp.colour);
					y++;
				}
			}
			stripe++;
		}
	}
}
