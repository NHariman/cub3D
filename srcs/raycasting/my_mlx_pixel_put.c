/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_mlx_pixel_put.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 03:50:46 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/17 03:51:01 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void			my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr +
	(y * data->line_length + x * (data->img_bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
