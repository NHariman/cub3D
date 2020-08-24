/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functions_ptwo.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 18:42:02 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/11 10:47:57 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void			get_spritenumber(t_struct_m *main, int y, int x)
{
	while (y < main->ray.yy)
	{
		while (main->place.cubemap[y][x])
		{
			if (main->place.cubemap[y][x] == '2')
			{
				main->numsprites++;
			}
			x++;
		}
		y++;
		x = 0;
	}
	main->sprites = ft_calloc(main->numsprites, sizeof(t_sprites));
	main->zbuffer = ft_calloc(main->place.s_width, sizeof(double));
	main->spritedistance = ft_calloc(main->numsprites, sizeof(double));
	main->spriteorder = ft_calloc(main->numsprites, sizeof(int));
}

void			spritesnumb(t_struct_m *main)
{
	int	y;
	int	x;
	int	numsprites;

	y = 0;
	x = 0;
	numsprites = 0;
	get_spritenumber(main, y, x);
	while (y < main->ray.yy)
	{
		while (main->place.cubemap[y][x] != '\0')
		{
			if (main->place.cubemap[y][x] == '2')
			{
				main->sprites[numsprites].x = (double)x + 0.5;
				main->sprites[numsprites].y = (double)y + 0.5;
				numsprites++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void			swap(t_struct_m *main, int j)
{
	int		temp_order;
	double	temp_dist;

	temp_dist = (main->spritedistance)[j];
	temp_order = (main->spriteorder)[j];
	(main->spritedistance)[j] = (main->spritedistance)[j + 1];
	(main->spritedistance)[j + 1] = temp_dist;
	(main->spriteorder)[j] = (main->spriteorder)[j + 1];
	(main->spriteorder)[j + 1] = temp_order;
}

void			bubble_sort(t_struct_m *main)
{
	int		swapped;
	int		i;
	int		j;

	swapped = 1;
	i = 0;
	j = 0;
	while (main->numsprites - i > 1 && swapped == 1)
	{
		swapped = 0;
		j = 0;
		while (j < main->numsprites - i - 1)
		{
			if ((main->spritedistance)[j] < (main->spritedistance)[j + 1])
			{
				swap(main, j);
				swapped = 1;
			}
			j++;
		}
		i++;
	}
}

int				ft_atoi_cube(char *str, t_struct_m *main, int i)
{
	int		res;
	int		sign;
	int		max;

	max = 2147483647;
	res = 0;
	sign = 1;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > (max / 10))
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			main->place.i = i;
			return (2147483647);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	main->place.i = i;
	return (res);
}
