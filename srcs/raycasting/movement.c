/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/10 19:21:03 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/10 22:16:24 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void				move_vertical(t_camera *cam, int type)
{
	if (type == W)
	{
		if (cam->map[(int)(cam->posx + cam->dirx * cam->movespeed)]
				[(int)cam->posy] != '1')
			cam->posx += cam->dirx * cam->movespeed;
		if (cam->map[(int)(cam->posx)]
				[(int)(cam->posy + cam->diry * cam->movespeed)] != '1')
			cam->posy += cam->diry * cam->movespeed;
	}
	else if (type == S)
	{
		if (cam->map[(int)(cam->posx - cam->dirx * cam->movespeed)]
				[(int)cam->posy] != '1')
			cam->posx -= cam->dirx * cam->movespeed;
		if (cam->map[(int)(cam->posx)]
				[(int)(cam->posy - cam->diry * cam->movespeed)] != '1')
			cam->posy -= cam->diry * cam->movespeed;
	}
}

void				move_horizontal(t_camera *cam, int type)
{
	if (type == A)
	{
		if (cam->map[(int)(cam->posx)]
				[(int)(cam->posy - cam->diry * cam->movespeed)] != '1')
			cam->posy -= cam->diry * cam->movespeed;
	}
	else if (type == D)
	{
		if (cam->map[(int)(cam->posx)]
				[(int)(cam->posy + cam->diry * cam->movespeed)] != '1')
			cam->posy += cam->diry * cam->movespeed;
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
}
