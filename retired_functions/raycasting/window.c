/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 20:39:14 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/13 22:29:43 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void			set_window_size(t_camera *cam)
{
	int sizex;
	int sizey;
	int check;

	check = 0;
	mlx_get_screen_size(cam->mlx.mlx, &sizex, &sizey);
	if (cam->cub->res_x > sizex)
	{
		cam->cub->res_x = sizex;
		check = 1;
	}
	if (cam->cub->res_y > sizey)
	{
		cam->cub->res_y = sizey;
		check = 1;
	}
	if (check)
		ft_printf("Modified screen resolution to fit screen.\n");
}

int			mlx_exit(void *mlx, void *mlx_win, int error)
{
	mlx_destroy_window(mlx, mlx_win);
	return (error != 0 ? 1 : print_error(error));
}

void			set_img(t_camera *cam)
{
	cam->mlx.img.texture =
		mlx_new_image(cam->mlx.mlx, cam->cub->res_x, cam->cub->res_y);
	if (!cam->mlx.img.texture)
		exit(print_error(20));
	cam->mlx.img.addr = mlx_get_data_addr(cam->mlx.img.texture,
		&cam->mlx.img.bits_per_pixel, &cam->mlx.img.line_length,
			&cam->mlx.img.endian);
}
