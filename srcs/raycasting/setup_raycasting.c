/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_raycasting.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 23:05:57 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/11 00:03:27 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void		set_spawnpoint(t_cub *cub, t_camera *cam)
{
	cam->posx = (double)cub->spawn_x;
	cam->posy = (double)cub->spawn_y;
	cam->dirx = -1;
	cam->diry = 0;
	cam->raydirx = 0;
	cam->raydiry = 0;
	cam->planex = 0;
	cam->planey = 0.66;
	cam->time = 0;
	cam->prev_time = 0;
	cam->camerax = 0;
	cam->map = cub->map;
}

static void		get_speedmod(t_camera *cam)
{
	cam->movespeed = cam->frametime * 5.0;
	cam->rotspeed = cam->frametime * 3.0;
}

int				ray_time(t_cub *cub)
{
	t_camera				cam;

	set_spawnpoint(cub, &cam);
	cam.mlx.mlx = mlx_init();
	if (!cam.mlx.mlx)
		exit(print_error(19));
	if (!get_textures(cam.mlx.mlx, cub))
		exit(1);
	set_window(&cam, cub);
	while (mlx_loop(cam.mlx.mlx))
	{
		setup_camray(cub, &cam);
		mlx_put_image_to_window(cam.mlx.mlx, cam.mlx.mlx_win,
								cam.img.img, 0, 0);
		mlx_destroy_image(cam.mlx.mlx, cam.img.img);
		get_speedmod(&cam);
		get_key_input(&cam);
	}
	return (1);
}
