/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_so.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/30 15:23:08 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static int		ft_read_so_read(t_struct_m *main, char *map, int i, int r)
{
	while (map[i] == ' ')
		i++;
	if (map[i] == 'S')
		i++;
	if (map[i] == 'O')
		i++;
	while (map[i] == ' ')
		i++;
	if (map[i] != ' ')
	{
		r = ft_strleng(map, i);
		main->place.so = ft_substr(map, i, r);
		i = i + r;
		r = 1;
		main->doublle.d_so = 1;
	}
	return (i);
}

int				ft_read_so(t_struct_m *main, char *map)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	if (main->doublle.d_so > 0)
	{
		main->place.error = 36;
		ft_error(main);
	}
	else
	{
		i = ft_read_so_read(main, map, i, r);
		if (map[i] != '\0')
		{
			main->place.error = 37;
			ft_error(main);
		}
	}
	return (0);
}
