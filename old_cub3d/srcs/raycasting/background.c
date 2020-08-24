/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   background.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 03:15:16 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/17 03:16:03 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		ft_colour_background(t_cub *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < cub->res_y / 2)
	{
		while (x < cub->res_x)
		{
			my_mlx_pixel_put(&cub->mlx, x, y, cub->cling);
			x++;
		}
		x = 0;
		y++;
	}
	while (y < cub->res_y)
	{
		while (x < cub->res_x)
		{
			my_mlx_pixel_put(&cub->mlx, x, y, cub->floor);
			x++;
		}
		x = 0;
		y++;
	}
}
