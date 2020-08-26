/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_spawnpoint.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/21 20:39:00 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/21 20:57:12 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		ft_set_cam_pov(t_cub *cub)
{
	if (cub->spawn_pos == 'N' || cub->spawn_pos == 'S')
	{
		cub->set.planex = cub->spawn_pos == 'N' ? 0 : 0;
		cub->set.planey = cub->spawn_pos == 'N' ? 0.66 : -0.66;
		cub->set.dirx = cub->spawn_pos == 'N' ? -1 : 1;
		cub->set.diry = cub->spawn_pos == 'N' ? 0 : 0;
	}
	else if (cub->spawn_pos == 'W' || cub->spawn_pos == 'E')
	{
		cub->set.planex = cub->spawn_pos == 'W' ? -0.66 : 0.66;
		cub->set.planey = cub->spawn_pos == 'W' ? 0 : 0;
		cub->set.dirx = cub->spawn_pos == 'W' ? 0 : 0;
		cub->set.diry = cub->spawn_pos == 'W' ? -1 : 1;
	}
}
