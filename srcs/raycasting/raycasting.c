/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 13:51:25 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/15 21:33:45 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			setup_camray(t_camera *cam)
{
	int x;

	x = 0;
	while (x < cam->cub->res_x)
	{
		cam->camerax = 2 * x / (double)cam->cub->res_x - 1;
		calc_camray(cam);
		calc_step_and_sidedist(cam);
		calc_dda(cam);
		calc_camwalldist(cam);
		calc_line(cam, cam->cub->res_y);
		calc_textures(cam, x);
		//add zbuffer later for sprite management
		x++;
	}
}
