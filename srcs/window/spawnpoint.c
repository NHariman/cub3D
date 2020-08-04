/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spawnpoint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 13:51:25 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/04 15:11:14 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		set_spawnpoint(t_cub *cub)
{
	cub->cam.posx = (double)cub->spawn_x;
	cub->cam.posy = (double)cub->spawn_y;
	cub->cam.dirx = -1;
	cub->cam.diry = 0;
	cub->cam.raydirx = 0;
	cub->cam.raydiry = 0;
	cub->cam.planex = 0;
	cub->cam.planey = 0.66;
	cub->cam.time = 0;
	cub->cam.prev_time = 0;
	cub->cam.camerax = 0;
}

void		calc_camray(t_cub *cub)
{
	int i;

	while (i < cub->res_x)
}
