/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 13:26:33 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/03 12:06:49 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int				ft_push_key(int keycode, t_struct_m *main)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(main->vars.mlx, main->vars.win);
		ft_end_function(main);
	}
	if (keycode == W_KEY && main->keys.s != 1)
		main->keys.w = 1;
	if (keycode == S_KEY && main->keys.w != 1)
		main->keys.s = 1;
	if (keycode == A_KEY && main->keys.d != 1)
		main->keys.lef = 1;
	if (keycode == D_KEY && main->keys.a != 1)
		main->keys.rig = 1;
	if (keycode == LEF_KEY && main->keys.rig != 1)
		main->keys.a = 1;
	if (keycode == RIG_KEY && main->keys.lef != 1)
		main->keys.d = 1;
	if (keycode == DOW_KEY && main->keys.up != 1)
		main->keys.dow = 1;
	if (keycode == UP_KEY && main->keys.dow != 1)
		main->keys.up = 1;
	return (0);
}

int				ft_release_key(int keycode, t_struct_m *main)
{
	if (keycode == W_KEY)
		main->keys.w = 0;
	if (keycode == S_KEY)
		main->keys.s = 0;
	if (keycode == A_KEY)
		main->keys.lef = 0;
	if (keycode == D_KEY)
		main->keys.rig = 0;
	if (keycode == LEF_KEY)
		main->keys.a = 0;
	if (keycode == RIG_KEY)
		main->keys.d = 0;
	if (keycode == UP_KEY)
		main->keys.up = 0;
	if (keycode == DOW_KEY)
		main->keys.dow = 0;
	return (0);
}

int				wasd_2(t_struct_m *main)
{
	double movesp;
	double rotsp;

	movesp = 0.07;
	rotsp = 0.05;
	if (main->keys.w)
	{
		if (main->place.cubemap[(int)(main->ray.posy)][(int)(main->ray.posx
		+ main->ray.dirx * movesp)] != '1')
			main->ray.posx += main->ray.dirx * movesp;
		if (main->place.cubemap[(int)(main->ray.posy + main->ray.diry
		* movesp)][(int)(main->ray.posx)] != '1')
			main->ray.posy += main->ray.diry * movesp;
	}
	wasd_s_d(main, movesp, rotsp);
	wasd_a(main, rotsp);
	wasd_r_l(main, movesp);
	return (0);
}
