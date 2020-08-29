/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_list.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 18:52:04 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/26 18:36:29 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void				ft_count_sprites(t_cub *cub)
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

void				ft_floodfill_no(t_cub *cub, int x, int y, int nb)
{
	if (nb < 0)
		return ;
	if (ft_strchr("1XO", cub->map[x][y]))
		return ;
	if (cub->map[x][y] == 'I')
	{
		while (cub->sp.sprites[nb].y && cub->sp.sprites[nb].x)
			nb--;
		cub->sp.sprites[nb].y = (double)y + 0.5;
		cub->sp.sprites[nb].x = (double)x + 0.5;
		nb--;
	}
	cub->map[x][y] = cub->map[x][y] == 'I' ? 'X' : 'O';
	ft_floodfill_no(cub, x, y + 1, nb);
	ft_floodfill_no(cub, x + 1, y, nb);
	ft_floodfill_no(cub, x - 1, y, nb);
	ft_floodfill_no(cub, x, y - 1, nb);
	return ;
}

void				ft_floodfill_so(t_cub *cub, int x, int y, int nb)
{
	if (nb < 0)
		return ;
	if (ft_strchr("1XO", cub->map[x][y]))
		return ;
	if (cub->map[x][y] == 'I')
	{
		while (cub->sp.sprites[nb].y && cub->sp.sprites[nb].x)
			nb--;
		cub->sp.sprites[nb].y = (double)y + 0.5;
		cub->sp.sprites[nb].x = (double)x + 0.5;
		nb--;
	}
	cub->map[x][y] = cub->map[x][y] == 'I' ? 'X' : 'O';
	ft_floodfill_so(cub, x, y - 1, nb);
	ft_floodfill_so(cub, x + 1, y, nb);
	ft_floodfill_so(cub, x - 1, y, nb);
	ft_floodfill_so(cub, x, y + 1, nb);
	return ;
}

void				ft_floodfill_ea(t_cub *cub, int x, int y, int nb)
{
	if (nb < 0)
		return ;
	if (ft_strchr("1XO", cub->map[x][y]))
		return ;
	if (cub->map[x][y] == 'I')
	{
		while (cub->sp.sprites[nb].y && cub->sp.sprites[nb].x)
			nb--;
		cub->sp.sprites[nb].y = (double)y + 0.5;
		cub->sp.sprites[nb].x = (double)x + 0.5;
		nb--;
	}
	cub->map[x][y] = cub->map[x][y] == 'I' ? 'X' : 'O';
	ft_floodfill_ea(cub, x + 1, y, nb);
	ft_floodfill_ea(cub, x, y + 1, nb);
	ft_floodfill_ea(cub, x, y - 1, nb);
	ft_floodfill_ea(cub, x - 1, y, nb);
	return ;
}

void				ft_floodfill_we(t_cub *cub, int x, int y, int nb)
{
	if (nb < 0)
		return ;
	if (ft_strchr("1XO", cub->map[x][y]))
		return ;
	if (cub->map[x][y] == 'I')
	{
		while (cub->sp.sprites[nb].y && cub->sp.sprites[nb].x)
			nb--;
		cub->sp.sprites[nb].y = (double)y + 0.5;
		cub->sp.sprites[nb].x = (double)x + 0.5;
		nb--;
	}
	cub->map[x][y] = cub->map[x][y] == 'I' ? 'X' : 'O';
	ft_floodfill_we(cub, x - 1, y, nb);
	ft_floodfill_we(cub, x, y + 1, nb);
	ft_floodfill_we(cub, x, y - 1, nb);
	ft_floodfill_we(cub, x + 1, y, nb);
	return ;
}
