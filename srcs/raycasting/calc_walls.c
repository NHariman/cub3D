/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_walls.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 17:51:30 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/21 17:41:22 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		ft_calc_side(t_cub *cub)
{
	if (cub->ray.raydirx < 0)
	{
		cub->side.stepx = -1;
		cub->side.sidedistx =
			(cub->set.posx - cub->ray.mapx) * cub->ray.deltadistx;
	}
	else
	{
		cub->side.stepx = 1;
		cub->side.sidedistx =
			(cub->ray.mapx + 1.0 - cub->set.posx) * cub->ray.deltadistx;
	}
	if (cub->ray.raydiry < 0)
	{
		cub->side.stepy = -1;
		cub->side.sidedisty =
			(cub->set.posy - cub->ray.mapy) * cub->ray.deltadisty;
	}
	else
	{
		cub->side.stepy = 1;
		cub->side.sidedisty =
			(cub->ray.mapy + 1.0 - cub->set.posy) * cub->ray.deltadisty;
	}
}

void		ft_calc_hit(t_cub *cub)
{
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
}

int			ft_calc_pov(t_cub *cub)
{
	if (cub->side.side == 0)
	{
		if (cub->set.posx < cub->ray.mapx)
			return (NO);
		else
			return (WE);
	}
	else
	{
		if (cub->set.posy < cub->ray.mapy)
			return (EA);
		else
			return (SO);
	}
}

void		ft_calc_draw(t_cub *cub)
{
	if (cub->side.side == 0)
		cub->draw.perpwalldist = (cub->ray.mapx - cub->set.posx +
			(1 - cub->side.stepx) / 2) / cub->ray.raydirx;
	else
		cub->draw.perpwalldist = (cub->ray.mapy - cub->set.posy +
			(1 - cub->side.stepy) / 2) / cub->ray.raydiry;
	cub->draw.lineheight = (int)(cub->res_y / cub->draw.perpwalldist);
	cub->draw.drawstart = -cub->draw.lineheight / 2 + cub->res_y / 2;
	if (cub->draw.drawstart < 0)
		cub->draw.drawstart = 0;
	cub->draw.drawend = cub->draw.lineheight / 2 + cub->res_y / 2;
	if (cub->draw.drawend >= cub->res_y)
		cub->draw.drawend = cub->res_y - 1;
}

void		ft_calc_texxy(t_cub *cub, int pov)
{
	if (cub->side.side == 0)
	{
		cub->texxy.wallx = cub->set.posy + cub->draw.perpwalldist *
						cub->ray.raydiry;
	}
	else
	{
		cub->texxy.wallx = cub->set.posx + cub->draw.perpwalldist *
								cub->ray.raydirx;
	}
	cub->texxy.wallx -= floor(cub->texxy.wallx);
	cub->texxy.texx = (int)(cub->texxy.wallx * (double)cub->text[pov].width);
	if (cub->side.side == 0 && cub->ray.raydirx > 0)
		cub->texxy.texx = cub->text[pov].width - cub->texxy.texx - 1;
	if (cub->side.side == 1 && cub->ray.raydiry < 0)
		cub->texxy.texx = cub->text[pov].width - cub->texxy.texx - 1;
	cub->texxy.step = 1.0 * cub->text[pov].height / cub->draw.lineheight;
	cub->texxy.texpos =
		(cub->draw.drawstart - cub->res_y / 2 + cub->draw.lineheight / 2) *
			cub->texxy.step;
}
