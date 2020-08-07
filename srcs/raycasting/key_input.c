/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 17:17:30 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/07 21:45:27 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int			exit_program(t_camera *cam)
{
	mlx_destroy_window(cam->mlx.mlx, cam->mlx.mlx_win);
	exit(1);
}

static int			keys(int keycode, t_camera *cam)
{
	if (keycode == W)
		move_up(cam);
	else if (keycode == A)
		move_left(cam);
	else if (keycode == S)
		move_down(cam);
	else if (keycode == D)
		move_right(cam);
	else if (keycode == ESC)
		exit_program(cam);
	else if (keycode == LEFT)
		pan_left(cam);
	else if (keycode == RIGHT)
		pan_right(cam);
	return (0);
}

void				get_key_input(t_camera *cam, t_cub *cub)
{
	mlx_hook(cam->mlx.mlx_win, 2, 1L << 0, keys, cam);
	mlx_hook(cam->mlx.mlx_win, 17, 0L, exit_program, cam);
}
