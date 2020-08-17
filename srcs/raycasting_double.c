/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_double.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 03:21:27 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/17 20:04:31 by nhariman      ########   odam.nl         */
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
		// int pov;
		// if (cub->side.side == 0)
		// {
		// 	if (cub->set.posx < cub->ray.mapx)
		// 		pov = SO;
		// 	else
		// 		pov = NO;
		// }
		// else
		// {
		// 	if (cub->set.posy < cub->ray.mapy)
		// 		pov = WE;
		// 	else
		// 		pov = EA;
		// }
		// double wallx;
		// if (cub->side.side == 0)
		// 	wallx = cub->set.posy + perpwalldist * cub->ray.raydiry;
		// else
		// 	wallx = cub->set.posx + perpwalldist * cub->ray.raydirx;
		// wallx -= floor(wallx);
		// int texx;
		// texx = (int)(wallx * (double)cub->text[pov]->width);
		// if (cub->side.side == 0 && cub->ray.raydirx > 0)
		// 	texx = cub->text[pov]->width;
		// if (cub->side.side == 1 && cub->ray.raydiry < 0)
		// 	texx = cub->text[pov]->width;
		// double d_step;
		// d_step = 1.0 * cub->text[pov]->height / lineheight;
		// double texpos = (drawstart - cub->res_y / 2 + lineheight / 2) * d_step;
		
		while (drawstart < drawend)
		{
			// int texy;
			// texy = (int)texpos & (cub->text[pov]->height - 1);
			// texpos += d_step;
			colour = 0;//*(int *)cub->text[pov]->addr[cub->text[pov]->height * texy + texx];
			// if (cub->side.side == 1)
			// 	colour = (colour >> 1) & 8355711;
			my_mlx_pixel_put(&cub->mlx, x, drawstart, colour);
			drawstart++;
		}
		x++;
	}
}
