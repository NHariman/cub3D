/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 17:51:30 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/17 18:11:51 by nhariman      ########   odam.nl         */
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
