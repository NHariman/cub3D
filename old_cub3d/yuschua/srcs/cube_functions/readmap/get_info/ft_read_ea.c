/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_ea.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 12:11:00 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static int		ft_read_ea_read(t_struct_m *main, char *map, int i, int r)
{
	while (map[i] == ' ')
		i++;
	if (map[i] == 'E')
		i++;
	if (map[i] == 'A')
		i++;
	while (map[i] == ' ')
		i++;
	if (map[i] != ' ')
	{
		r = ft_strleng(map, i);
		main->place.ea = ft_substr(map, i, r);
		i = i + r;
		r = 1;
		main->doublle.d_ea = 1;
	}
	return (i);
}

int				ft_read_ea(t_struct_m *main, char *map)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	if (main->doublle.d_ea > 0)
	{
		main->place.error = 42;
		ft_error(main);
	}
	else
	{
		i = ft_read_ea_read(main, map, i, r);
		if (map[i] != '\0')
		{
			main->place.error = 43;
			ft_error(main);
			return (0);
		}
	}
	return (0);
}
