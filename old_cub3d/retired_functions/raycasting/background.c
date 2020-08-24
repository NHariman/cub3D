/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   background.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/15 18:48:35 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/15 20:34:01 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

//make two while loops, one with floor colour, one with ceiling colour.
void        ft_background(t_camera *cam)
{
	int colour;
	int x;
	int y;

	colour = 14443520;
	x = 0;
	y = 0;
	while (y < cam->cub->res_y)
	{
		while (x < cam->cub->res_x)
		{
			my_mlx_pixel_put(&cam->mlx.img, x, y, colour);
			x++;
		}
		x = 0;
		y++;
	}
}
