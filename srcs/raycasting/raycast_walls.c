/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_walls.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 03:21:27 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/20 21:57:59 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void		ft_setup(t_cub *cub)
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

void		ft_raycast_walls(t_cub *cub)
{
	int		x;
	int		pov;

	x = 0;
	pov = 0;
	while (x < cub->res_x)
	{
		cub->ray.camerax = 2 * x / (double)cub->res_x - 1;
		ft_setup(cub);
		cub->ray.hit = 0;
		ft_calc_side(cub);
		ft_calc_hit(cub);
		ft_calc_draw(cub);
		pov = ft_calc_pov(cub);
		ft_calc_texxy(cub, pov);
		ft_draw_walls(cub, pov, x);
		cub->sp.zbuffer[x] = cub->draw.perpwalldist;
		x++;
	}
}
