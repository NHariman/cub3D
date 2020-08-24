/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_we.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/01 11:03:46 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static int		ft_read_we_read(t_struct_m *main, char *map, int i, int r)
{
	while (map[i] == ' ')
		i++;
	if (map[i] == 'W')
		i++;
	if (map[i] == 'E')
		i++;
	while (map[i] == ' ')
		i++;
	if (map[i] != ' ')
	{
		r = ft_strleng(map, i);
		main->place.we = ft_substr(map, i, r);
		i = i + r;
		r = 1;
		main->doublle.d_we = 1;
	}
	return (i);
}

int				ft_read_we(t_struct_m *main, char *map)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	if (main->doublle.d_we > 0)
	{
		main->place.error = 38;
		ft_error(main);
	}
	else
	{
		i = ft_read_we_read(main, map, i, r);
		if (map[i] != '\0')
		{
			main->place.error = 39;
			ft_error(main);
		}
	}
	return (0);
}
