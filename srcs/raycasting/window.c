/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 20:39:14 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/10 23:06:51 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void		set_window_size(t_camera *cam, t_cub *cub)
{
	int sizex;
	int sizey;
	int check;

	check = 0;
	mlx_get_screen_size(cam->mlx.mlx, &sizex, &sizey);
	if (cub->res_x > sizex)
	{
		cub->res_x = sizex;
		check = 1;
	}
	if (cub->res_y > sizey)
	{
		cub->res_y = sizey;
		check = 1;
	}
	if (check)
		ft_printf("Modified screen resolution to fit screen.\n");
}

static int		mlx_exit(void *mlx, void *mlx_win, int error)
{
	mlx_destroy_window(mlx, mlx_win);
	return (error != 0 ? 1 : print_error(error));
}

void			set_window(t_camera *cam, t_cub *cub)
{
	set_window_size(cam, cub);
	cam->mlx.mlx_win =
			mlx_new_window(cam->mlx.mlx, cub->res_x, cub->res_y, "Cub3D");
	if (!cam->mlx.mlx_win)
		exit(mlx_exit(cam->mlx.mlx, cam->mlx.mlx_win, 20));
	cam->img.img = mlx_new_image(cam->mlx.mlx, cub->res_x, cub->res_y);
	cam->img.addr =
		mlx_get_data_addr(cam->img.img, &cam->img.bits_per_pixel,
						&cam->img.line_length, &cam->img.endian);
}
