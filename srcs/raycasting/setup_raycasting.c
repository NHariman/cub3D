/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_raycasting.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 23:05:57 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/15 21:41:02 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void		set_spawnpoint(t_cub *cub, t_camera *cam)
{
	cam->posx = (double)cub->spawn_y;
	cam->posy = (double)cub->spawn_x;
	cam->dirx = -1;
	cam->diry = 0;
	cam->raydirx = 0;
	cam->raydiry = 0;
	cam->planex = 0;
	cam->planey = 0.66;
	cam->time = 0;
	cam->prev_time = 0;
	cam->camerax = 0;
	cam->cub = cub;
}

static int		render_next_frame(t_camera *cam)
{
	//ft_movement(cam);
	ft_background(cam);
	giant_fucking_function(cam);
	//setup_camray(cam);
	mlx_put_image_to_window(cam->mlx.mlx,
		cam->mlx.mlx_win, cam->mlx.img.texture, 0, 0);
	mlx_destroy_image(cam->mlx.mlx, cam->mlx.img.texture);
	set_img(cam);
	return (0);
}

int				ray_time(t_cub *cub)
{
	t_camera				*cam;

	cam = ft_calloc(1, sizeof(t_camera));
	set_spawnpoint(cub, cam);
	cam->mlx.mlx = mlx_init();
	if (!cam->mlx.mlx)
		exit(print_error(19));
	set_window_size(cam);
	cam->mlx.mlx_win =
		mlx_new_window(cam->mlx.mlx, cam->cub->res_x, cam->cub->res_y, "Cub3D");
	if (!cam->mlx.mlx_win)
		exit(mlx_exit(cam->mlx.mlx, cam->mlx.mlx_win, 20));
	set_img(cam);
	// if (!get_textures(&cam))
	// 	exit(1);
	get_key_input(cam);
	mlx_loop_hook(cam->mlx.mlx, render_next_frame, cam);
	mlx_loop(cam->mlx.mlx);
	return (1);
}
