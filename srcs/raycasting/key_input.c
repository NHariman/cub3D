/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/16 21:48:53 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/17 04:05:10 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int			exit_program(t_cub *cub)
{
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	exit(0);
}

static int			press_keys(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		exit_program(cub);
	if (keycode == W && cub->keys.s != 1)
		cub->keys.w = 1;
	if (keycode == A && cub->keys.d != 1)
		cub->keys.a = 1;
	if (keycode == S && cub->keys.w != 1)
		cub->keys.s = 1;
	if (keycode == D && cub->keys.a != 1)
		cub->keys.d = 1;
	if (keycode == LEFT && cub->keys.right != 1)
		cub->keys.left = 1;
	if (keycode == RIGHT && cub->keys.left != 1)
		cub->keys.right = 1;
	return (0);
}

static int			release_keys(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->keys.w = 0;
	if (keycode == A)
		cub->keys.a = 0;
	if (keycode == S)
		cub->keys.s = 0;
	if (keycode == D)
		cub->keys.d = 0;
	if (keycode == LEFT)
		cub->keys.left = 0;
	if (keycode == RIGHT)
		cub->keys.right = 0;
	return (0);
}

void				get_key_input(t_cub *cub)
{
	mlx_hook(cub->mlx.win, 2, 1L << 0, press_keys, cub);
	mlx_hook(cub->mlx.win, 3, 1L << 1, release_keys, cub);
	mlx_hook(cub->mlx.win, 17, 1L << 0, exit_program, cub);
}
