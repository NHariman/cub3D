/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/16 17:38:42 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/20 22:24:19 by nhariman      ########   odam.nl         */
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
		ft_printf("Modified window resolution to fit screen.\n");
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
	if (cub->keys.confirm_press == 0)
		return (0);
	ft_movement(cub);
	if (cub->mlx.img)
	{
		cub->mlx.old_img = cub->mlx.img;
		cub->mlx.img = NULL;
		mlx_put_image_to_window(cub->mlx.mlx,
			cub->mlx.win, cub->mlx.old_img, 0, 0);
	}
	create_img(cub);
	ft_colour_background(cub);
	ft_raycast_walls(cub);
	ft_raycast_sprites(cub);
	mlx_put_image_to_window(cub->mlx.mlx,
			cub->mlx.win, cub->mlx.img, 0, 0);
	if (cub->mlx.old_img)
	{
		mlx_destroy_image(cub->mlx.mlx, cub->mlx.old_img);
		cub->mlx.old_img = NULL;
	}
	return (0);
}

static void	ft_set_start_values(t_cub *cub)
{
	cub->set.posx = (double)cub->spawn_y + 0.5;
	cub->set.posy = (double)cub->spawn_x - 0.5;
	cub->set.planex = 0;
	cub->set.planey = 0.66;
	cub->set.dirx = -1;
	cub->set.diry = 0;
	setup_sp(cub);
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
	if (!set_textures(cub))
		exit(1);
	ft_set_start_values(cub);
	ft_movement(cub);
	ft_colour_background(cub);
	ft_raycast_walls(cub);
	ft_raycast_sprites(cub);
	mlx_put_image_to_window(cub->mlx.mlx,
			cub->mlx.win, cub->mlx.img, 0, 0);
	get_key_input(cub);
	mlx_loop_hook(cub->mlx.mlx, render_next_frame, cub);
	mlx_loop(cub->mlx.mlx);
}
