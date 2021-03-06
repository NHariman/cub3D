/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/10 19:21:03 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/14 02:09:41 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void				move_vertical(t_camera *cam, int type)
{
	if (type == W)
	{
		if (cam->cub->map[(int)(cam->posx + cam->dirx * cam->movespeed)]
				[(int)cam->posy] != '1')
			cam->posx += cam->dirx * cam->movespeed;
		if (cam->cub->map[(int)(cam->posx)]
				[(int)(cam->posy + cam->diry * cam->movespeed)] != '1')
			cam->posy += cam->diry * cam->movespeed;
		ft_printf("W");
	}
	else if (type == S)
	{
		if (cam->cub->map[(int)(cam->posx - cam->dirx * cam->movespeed)]
				[(int)cam->posy] != '1')
			cam->posx -= cam->dirx * cam->movespeed;
		if (cam->cub->map[(int)(cam->posx)]
				[(int)(cam->posy - cam->diry * cam->movespeed)] != '1')
			cam->posy -= cam->diry * cam->movespeed;
		ft_printf("S");
	}
}

void				move_horizontal(t_camera *cam, int type)
{
	if (type == A)
	{
		if (cam->cub->map[(int)(cam->posx)]
				[(int)(cam->posy - cam->diry * cam->movespeed)] != '1')
			cam->posy -= cam->diry * cam->movespeed;
		ft_printf("A");
	}
	else if (type == D)
	{
		if (cam->cub->map[(int)(cam->posx)]
				[(int)(cam->posy + cam->diry * cam->movespeed)] != '1')
			cam->posy += cam->diry * cam->movespeed;
		ft_printf("D");
	}
}

void				rotate(t_camera *cam, int type)
{
	cam->olddirx = cam->dirx;
	cam->dirx = cam->dirx * cos(type == LEFT ?
		-cam->rotspeed : cam->rotspeed) - cam->diry * sin(type == LEFT ?
			-cam->rotspeed : cam->rotspeed);
	cam->diry = cam->olddirx * sin(type == LEFT ?
		-cam->rotspeed : cam->rotspeed) + cam->diry * cos(type == LEFT ?
			-cam->rotspeed : cam->rotspeed);
	cam->oldplanex = cam->planex;
	cam->planex = cam->planex * cos(type == LEFT ?
		-cam->rotspeed : cam->rotspeed) - cam->planey * sin(type == LEFT ?
			-cam->rotspeed : cam->rotspeed);
	cam->planey = cam->oldplanex * sin(type == LEFT ?
		-cam->rotspeed : cam->rotspeed) - cam->planey * cos(type == LEFT ?
			-cam->rotspeed : cam->rotspeed);
	if (type == LEFT)
		ft_printf("\nLEFT\n");
	if (type == RIGHT)
		ft_printf("\nRIGHT\n");
}

void			ft_movement(t_camera *cam)
{
	cam->movespeed = 0.07;
	cam->rotspeed = 0.05;
	if (cam->keys.w)
		move_vertical(cam, W);
	if (cam->keys.s)
		move_vertical(cam, S);
	if (cam->keys.d)
		move_horizontal(cam, D);
	if (cam->keys.a)
		move_horizontal(cam, A);
	if (cam->keys.left)
		rotate(cam, LEFT);
	if (cam->keys.right)
		rotate(cam, RIGHT);
}
