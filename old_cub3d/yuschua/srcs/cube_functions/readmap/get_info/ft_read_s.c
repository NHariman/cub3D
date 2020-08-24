/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 15:08:39 by ybakker       #+#    #+#                 */
/*   Updated: 2020/06/29 16:07:53 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static int		ft_read_s_read(t_struct_m *main, char *map, int i, int r)
{
	while (map[i] == ' ')
		i++;
	while (map[i] == 'S')
		i++;
	while (map[i] == ' ')
		i++;
	if (map[i] != ' ')
	{
		r = ft_strleng(map, i);
		main->place.s = ft_substr(map, i, r);
		i = i + r;
		r = 1;
		main->doublle.d_s = 1;
	}
	return (i);
}

int				ft_read_s(t_struct_m *main, char *map)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	if (main->doublle.d_s > 0)
	{
		main->place.error = 44;
		ft_error(main);
	}
	else
	{
		i = ft_read_s_read(main, map, i, r);
		if (map[i] != '\0')
		{
			main->place.error = 45;
			ft_error(main);
		}
	}
	return (0);
}
