/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 17:17:30 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/15 20:50:05 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int					exit_program(t_camera *cam)
{
	mlx_destroy_window(cam->mlx.mlx, cam->mlx.mlx_win);
	exit(1);
}

static int			press_keys(int keycode, t_camera *cam)
{
	if (keycode == ESC)
		exit_program(cam);
	if (keycode == W && cam->keys.s != 1)
		cam->keys.w = 1;
	if (keycode == A && cam->keys.d != 1)
		cam->keys.a = 1;
	if (keycode == S && cam->keys.w != 1)
		cam->keys.s = 1;
	if (keycode == D && cam->keys.a != 1)
		cam->keys.d = 1;
	if (keycode == LEFT && cam->keys.right != 1)
		cam->keys.left = 1;
	if (keycode == RIGHT && cam->keys.left != 1)
		cam->keys.right = 1;
	ft_printf("hello\n");
	return (0);
}

static int			release_keys(int keycode, t_camera *cam)
{
	if (keycode == W)
		cam->keys.w = 0;
	if (keycode == A)
		cam->keys.a = 0;
	if (keycode == S)
		cam->keys.s = 0;
	if (keycode == D)
		cam->keys.d = 0;
	if (keycode == LEFT)
		cam->keys.left = 0;
	if (keycode == RIGHT)
		cam->keys.right = 0;
	ft_printf("world\n");
	return (0);
}

void				get_key_input(t_camera *cam)
{
	mlx_hook(cam->mlx.mlx_win, 2, 1L << 0, press_keys, cam);
	mlx_hook(cam->mlx.mlx_win, 3, 1L << 1, release_keys, cam);
	mlx_hook(cam->mlx.mlx_win, 17, 1L << 0, exit_program, cam);
}
