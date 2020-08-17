/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 16:41:21 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/17 17:16:12 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void			ft_move_vertical(t_cub *cub)
{
	double	movespeed;

	movespeed = 0.07;
	if (cub->keys.w == 1)
	{
		if (cub->cpmap[(int)cub->set.posy]
			[(int)(cub->set.posx + cub->set.dirx * movespeed)] != '1')
			cub->set.posx += cub->set.dirx * movespeed;
		if (cub->cpmap[(int)(cub->set.posy + cub->set.diry * movespeed)]
			[(int)cub->set.posx] != '1')
			cub->set.posy += cub->set.diry * movespeed;
	}
	if (cub->keys.s == 1)
	{
		if (cub->cpmap[(int)cub->set.posy]
			[(int)(cub->set.posx - cub->set.dirx * movespeed)] != '1')
			cub->set.posx -= cub->set.dirx * movespeed;
		if (cub->cpmap[(int)(cub->set.posy - cub->set.diry * movespeed)]
			[(int)cub->set.posx] != '1')
			cub->set.posy -= cub->set.diry * movespeed;
	}
}

static void			ft_move_horizontal(t_cub *cub)
{
	double	movespeed;

	movespeed = 0.07;
	if (cub->keys.a == 1)
	{
		if (cub->cpmap[(int)cub->set.posy]
			[(int)(cub->set.posx - cub->set.planex * movespeed)] != '1')
			cub->set.posx -= cub->set.planex * movespeed;
		if (cub->cpmap[(int)(cub->set.posy - cub->set.planey * movespeed)]
			[(int)cub->set.posx] != '1')
			cub->set.posy -= cub->set.planey * movespeed;
	}
	if (cub->keys.d == 1)
	{
		if (cub->cpmap[(int)cub->set.posy]
			[(int)(cub->set.posx + cub->set.planex * movespeed)] != '1')
			cub->set.posx += cub->set.planex * movespeed;
		if (cub->cpmap[(int)(cub->set.posy + cub->set.planey * movespeed)]
			[(int)cub->set.posx] != '1')
			cub->set.posy += cub->set.planey * movespeed;
	}
}

static void			ft_left(t_cub *cub)
{
	double	rotspeed;
	double	olddirx;
	double	oldplanex;

	rotspeed = 0.05;
	olddirx = cub->set.dirx;
	oldplanex = cub->set.planex;
	cub->set.dirx =
			cub->set.dirx * cos(rotspeed) - cub->set.diry * sin(rotspeed);
	cub->set.diry =
			olddirx * sin(rotspeed) + cub->set.diry * cos(rotspeed);
	cub->set.planex =
			cub->set.planex * cos(rotspeed) -
				cub->set.planey * sin(rotspeed);
	cub->set.planey =
			oldplanex * sin(rotspeed) + cub->set.planey * cos(rotspeed);
}

static void			ft_right(t_cub *cub)
{
	double	rotspeed;
	double	olddirx;
	double	oldplanex;

	rotspeed = 0.05;
	olddirx = cub->set.dirx;
	oldplanex = cub->set.planex;
	cub->set.dirx =
			cub->set.dirx * cos(-rotspeed) - cub->set.diry * sin(-rotspeed);
	cub->set.diry =
			olddirx * sin(-rotspeed) + cub->set.diry * cos(-rotspeed);
	cub->set.planex =
			cub->set.planex * cos(-rotspeed) -
				cub->set.planey * sin(-rotspeed);
	cub->set.planey =
			oldplanex * sin(-rotspeed) + cub->set.planey * cos(-rotspeed);
}

void				ft_movement(t_cub *cub)
{
	ft_move_vertical(cub);
	ft_move_horizontal(cub);
	if (cub->keys.left == 1)
		ft_left(cub);
	if (cub->keys.right == 1)
		ft_right(cub);
}
