/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_raycasting.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 23:05:57 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/05 22:45:08 by nhariman      ########   odam.nl         */
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
}

static int		mlx_exit(void *mlx, void *mlx_img, int error)
{
	mlx_destroy_window(mlx, mlx_img);
	return (error != 0 ? 1 : print_error(error));
}

int				ray_time(t_cub *cub)
{
	void		*mlx;
	void		*mlx_img;
	t_camera	cam;
	int			buf[cub->res_y][cub->res_x];

	set_spawnpoint(cub, &cam);
	mlx = mlx_init();
	if (!mlx)
		return (print_error(19));
	if (!get_textures(mlx, cub))
		return (0);
	mlx_img = mlx_new_window(mlx, cub->res_x, cub->res_y, "Cub3D");
	if (!mlx_img)
		return (mlx_exit(mlx, mlx_img, 20));
	while (mlx_loop(mlx))
	{
		setup_camray(cub, &cam, &buf);
	}
}
