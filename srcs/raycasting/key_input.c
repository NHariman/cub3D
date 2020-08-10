/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 17:17:30 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/11 00:03:18 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int					exit_program(t_camera *cam)
{
	mlx_destroy_window(cam->mlx.mlx, cam->mlx.mlx_win);
	exit(1);
}

static int			keys(int keycode, t_camera *cam)
{
	if (keycode == W)
		move_vertical(cam, W);
	else if (keycode == A)
		move_horizontal(cam, A);
	else if (keycode == S)
		move_vertical(cam, S);
	else if (keycode == D)
		move_horizontal(cam, D);
	else if (keycode == ESC)
		exit_program(cam);
	else if (keycode == LEFT)
		rotate(cam, LEFT);
	else if (keycode == RIGHT)
		rotate(cam, RIGHT);
	return (0);
}

void				get_key_input(t_camera *cam)
{
	mlx_hook(cam->mlx.mlx_win, 2, 1L << 0, keys, cam);
	mlx_hook(cam->mlx.mlx_win, 17, 0L, exit_program, cam);
}
