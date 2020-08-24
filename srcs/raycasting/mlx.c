/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/16 17:38:42 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/24 22:01:15 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		ft_set_start_values(t_cub *cub)
{
	cub->set.posx = (double)cub->spawn_x + 0.5;
	cub->set.posy = (double)cub->spawn_y + 0.5;
	ft_set_cam_pov(cub);
	setup_sp(cub);
}

static void	ft_get_window_size(void *mlx, t_cub *cub)
{
	int x;
	int y;
	int check;

	check = 0;
	mlx_get_screen_size(mlx, &x, &y);
	if (cub->res_x > x || cub->res_x < 150)
	{
		cub->res_x = cub->res_x < 150 ? 150 : x;
		check = 1;
	}
	if (cub->res_y > y || cub->res_y < 150)
	{
		cub->res_y = cub->res_y < 150 ? 150 : y;
		check = 1;
	}
	if (check)
		ft_printf("Modified window resolution to fit screen.\n");
}

static int	render_next_frame(t_cub *cub)
{
	get_key_input(cub);
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
	ft_create_img(cub);
	ft_render_frame(cub);
	if (cub->mlx.old_img)
	{
		mlx_destroy_image(cub->mlx.mlx, cub->mlx.old_img);
		cub->mlx.old_img = NULL;
	}
	return (0);
}

void		start_mlx(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	if (!cub->mlx.mlx)
		exit(print_error(19));
	ft_get_window_size(cub->mlx.mlx, cub);
	cub->mlx.win =
		mlx_new_window(cub->mlx.mlx, cub->res_x, cub->res_y, "Cub3D");
	if (!cub->mlx.win)
		exit(print_error(20));
	ft_create_img(cub);
	if (!set_textures(cub))
		exit(1);
	ft_set_start_values(cub);
	ft_render_frame(cub);
	mlx_loop_hook(cub->mlx.mlx, render_next_frame, cub);
	mlx_loop(cub->mlx.mlx);
}
