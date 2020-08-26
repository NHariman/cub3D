/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_structure.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/21 20:08:14 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/26 18:25:28 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		ft_create_img(t_cub *cub)
{
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, cub->res_x, cub->res_y);
	if (!cub->mlx.img)
		exit(ft_print_error(20));
	cub->mlx.img_addr = mlx_get_data_addr(cub->mlx.img,
		&cub->mlx.img_bits_per_pixel, &cub->mlx.line_length, &cub->mlx.endian);
}

void		ft_render_frame(t_cub *cub)
{
	ft_colour_background(cub);
	ft_raycast_walls(cub);
	if (cub->sprites > 0)
		ft_raycast_sprites(cub);
	mlx_put_image_to_window(cub->mlx.mlx,
			cub->mlx.win, cub->mlx.img, 0, 0);
}
