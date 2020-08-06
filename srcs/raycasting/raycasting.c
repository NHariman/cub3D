/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 13:51:25 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/06 16:56:05 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void			

void			setup_camray(t_cub *cub, t_camera *cam, unsigned int **buf)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while (x < cub->res_x)
	{
		cam->camerax = 2 * x / (double)cub->res_x - 1;
		calc_camray(cub, cam);
		calc_step_and_sidedist(cam);
		calc_dda(cam, cub);
		calc_camwalldist(cam);
		calc_line(cam, cub->res_y);
		calc_textures(cam, cub, buf, x);
		x++;
	}
}
