/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/16 17:38:42 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/17 04:52:20 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	get_window_size(void *mlx, t_cub *cub)
{
	int x;
	int y;
	int check;

	check = 0;
	mlx_get_screen_size(mlx, &x, &y);
	if (cub->res_x > x)
	{
		cub->res_x = x;
		check = 1;
	}
	if (cub->res_y > y)
	{
		cub->res_y = y;
		check = 1;
	}
	if (check)
		ft_printf("Modified screen resolution to fit screen.\n");
}

static void	create_img(t_cub *cub)
{
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, cub->res_x, cub->res_y);
	if (!cub->mlx.img)
		exit(print_error(20));
	cub->mlx.img_addr = mlx_get_data_addr(cub->mlx.img,
		&cub->mlx.img_bits_per_pixel, &cub->mlx.line_length, &cub->mlx.endian);
}

static int	render_next_frame(t_cub *cub)
{
	ft_colour_background(cub);
	ft_raycasting(cub);
	mlx_put_image_to_window(cub->mlx.mlx,
		cub->mlx.win, cub->mlx.img, 0, 0);
	mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
	create_img(cub);
	return (1);
}

static void	ft_set_start_values(t_cub *cub)
{
	cub->setup.posx = cub->spawn_y;
	cub->setup.posy = cub->spawn_x;
	cub->setup.planex = 0;
	cub->setup.planey = 0.66;
	cub->setup.dirx = -1;
	cub->setup.diry = 0;
}

void		start_mlx(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	if (!cub->mlx.mlx)
		exit(print_error(19));
	get_window_size(cub->mlx.mlx, cub);
	cub->mlx.win =
		mlx_new_window(cub->mlx.mlx, cub->res_x, cub->res_y, "Cub3D");
	if (!cub->mlx.win)
		exit(print_error(20));
	create_img(cub);
	get_key_input(cub);
	ft_set_start_values(cub);
	mlx_loop_hook(cub->mlx.mlx, render_next_frame, cub);
	mlx_loop(cub->mlx.mlx);
}
