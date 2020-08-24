/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 15:45:22 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/03 11:43:20 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void			wasd_s_d(t_struct_m *main, double movesp, double rotsp)
{
	double olddirx;
	double oldplanex;

	if (main->keys.s)
	{
		if (main->place.cubemap[(int)(main->ray.posy)][(int)(main->ray.posx -
		main->ray.dirx * movesp)] != '1')
			main->ray.posx -= main->ray.dirx * movesp;
		if (main->place.cubemap[(int)(main->ray.posy - main->ray.diry *
		movesp)][(int)(main->ray.posx)] != '1')
			main->ray.posy -= main->ray.diry * movesp;
	}
	if (main->keys.d)
	{
		olddirx = main->ray.dirx;
		main->ray.dirx = main->ray.dirx * cos(rotsp) -
		main->ray.diry * sin(rotsp);
		main->ray.diry = olddirx * sin(rotsp) + main->ray.diry * cos(rotsp);
		oldplanex = main->ray.planex;
		main->ray.planex = main->ray.planex * cos(rotsp)
		- main->ray.planey * sin(rotsp);
		main->ray.planey = oldplanex * sin(rotsp) +
		main->ray.planey * cos(rotsp);
	}
}

void			wasd_a(t_struct_m *main, double rotsp)
{
	double olddirx;
	double oldplanex;

	if (main->keys.a)
	{
		olddirx = main->ray.dirx;
		main->ray.dirx = main->ray.dirx * cos(-rotsp) -
		main->ray.diry * sin(-rotsp);
		main->ray.diry = olddirx * sin(-rotsp) + main->ray.diry * cos(-rotsp);
		oldplanex = main->ray.planex;
		main->ray.planex = main->ray.planex * cos(-rotsp) -
		main->ray.planey * sin(-rotsp);
		main->ray.planey = oldplanex * sin(-rotsp) +
		main->ray.planey * cos(-rotsp);
	}
}

void			wasd_r_l(t_struct_m *main, double movesp)
{
	if (main->keys.rig)
	{
		if (main->place.cubemap[(int)(main->ray.posy)][(int)(main->ray.posx
		+ main->ray.planex * movesp)] != '1')
			main->ray.posx += main->ray.planex * movesp;
		if (main->place.cubemap[(int)(main->ray.posy + main->ray.planey *
		movesp)][(int)(main->ray.posx)] != '1')
			main->ray.posy += main->ray.planey * movesp;
	}
	if (main->keys.lef)
	{
		if (main->place.cubemap[(int)(main->ray.posy)][(int)(main->ray.posx -
		main->ray.planex * movesp)] != '1')
			main->ray.posx -= main->ray.planex * movesp;
		if (main->place.cubemap[(int)(main->ray.posy - main->ray.planey *
		movesp)][(int)(main->ray.posx)] != '1')
			main->ray.posy -= main->ray.planey * movesp;
	}
}

void			ft_end_function(t_struct_m *main)
{
	free(main);
	exit(0);
}

int				ft_close(void)
{
	exit(0);
	return (0);
}
