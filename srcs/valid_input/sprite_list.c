/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_list.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 18:52:04 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/18 21:36:41 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void				count_sprites(t_cub *cub)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (cub->cpmap[y][0] != '\0')
	{
		while (cub->cpmap[y][x] != '\0')
		{
			if (cub->cpmap[y][x] == '2')
				cub->sprites++;
			x++;
		}
		x = 0;
		y++;
	}
}

void				floodfill_no(t_cub *cub, int x, int y, int nb)
{
	if (nb < 0)
		return ;
	if (ft_strchr("210", cub->map[x][y]))
		return ;
	if (cub->map[x][y] == 'I')
	{
		while (cub->sp.sprites[nb].y && cub->sp.sprites[nb].x)
			nb--;
		cub->sp.sprites[nb].y = (double)x;
		cub->sp.sprites[nb].x = (double)y;
		nb--;
	}
	cub->map[x][y] = cub->map[x][y] == 'I' ? '2' : '0';
	floodfill_no(cub, x, y + 1, nb);
	floodfill_no(cub, x + 1, y, nb);
	floodfill_no(cub, x - 1, y, nb);
	floodfill_no(cub, x, y - 1, nb);
	return ;
}

void				floodfill_so(t_cub *cub, int x, int y, int nb)
{
	if (nb < 0)
		return ;
	if (ft_strchr("210", cub->map[x][y]))
		return ;
	if (cub->map[x][y] == 'I')
	{
		while (cub->sp.sprites[nb].y && cub->sp.sprites[nb].x)
			nb--;
		cub->sp.sprites[nb].y = (double)x;
		cub->sp.sprites[nb].x = (double)y;
		nb--;
	}
	cub->map[x][y] = cub->map[x][y] == 'I' ? '2' : '0';
	floodfill_so(cub, x, y - 1, nb);
	floodfill_so(cub, x + 1, y, nb);
	floodfill_so(cub, x - 1, y, nb);
	floodfill_so(cub, x, y + 1, nb);
	return ;
}

void				floodfill_ea(t_cub *cub, int x, int y, int nb)
{
	if (nb < 0)
		return ;
	if (ft_strchr("210", cub->map[x][y]))
		return ;
	if (cub->map[x][y] == 'I')
	{
		while (cub->sp.sprites[nb].y && cub->sp.sprites[nb].x)
			nb--;
		cub->sp.sprites[nb].y = (double)x;
		cub->sp.sprites[nb].x = (double)y;
		nb--;
	}
	cub->map[x][y] = cub->map[x][y] == 'I' ? '2' : '0';
	floodfill_ea(cub, x + 1, y, nb);
	floodfill_ea(cub, x, y + 1, nb);
	floodfill_ea(cub, x, y - 1, nb);
	floodfill_ea(cub, x - 1, y, nb);
	return ;
}

void				floodfill_we(t_cub *cub, int x, int y, int nb)
{
	if (nb < 0)
		return ;
	if (ft_strchr("210", cub->map[x][y]))
		return ;
	if (cub->map[x][y] == 'I')
	{
		while (cub->sp.sprites[nb].y && cub->sp.sprites[nb].x)
			nb--;
		cub->sp.sprites[nb].y = (double)x;
		cub->sp.sprites[nb].x = (double)y;
		nb--;
	}
	cub->map[x][y] = cub->map[x][y] == 'I' ? '2' : '0';
	floodfill_we(cub, x - 1, y, nb);
	floodfill_we(cub, x, y + 1, nb);
	floodfill_we(cub, x, y - 1, nb);
	floodfill_we(cub, x + 1, y, nb);
	return ;
}