/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functions.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/05 11:35:00 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/03 11:44:14 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int				ft_strleng(char *str, int i)
{
	int		r;

	r = 0;
	while (str[i])
	{
		r++;
		i++;
	}
	return (r);
}

void			ft_putstr(char *str)
{
	int i;

	i = ft_strlen(str);
	write(1, "[", 1);
	write(1, str, i);
	write(1, "]", 1);
	write(1, "\n", 1);
}

void			printmap(t_struct_m *main)
{
	int	y;

	y = 0;
	main->ray.yy--;
	ft_putstr("-original-");
	while (y <= main->ray.yy)
	{
		ft_putstr(main->place.cubemap[y]);
		y++;
	}
	ft_putstr("-copy-");
	y = 0;
	while (y <= main->ray.yy)
	{
		ft_putstr(main->cubecopy[y]);
		y++;
	}
}

int				create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int				ft_strnstr_map(const char *haystack, const char *needle,
size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*needle))
		return (0);
	i = 0;
	while (*(haystack + i) && i < len)
	{
		if (*needle == *(haystack + i))
		{
			j = 0;
			while ((*(haystack + i + j) == *(needle + j)) && (i + j < len))
			{
				j += 1;
				if (!(*(needle + j)))
					return (1);
			}
		}
		i += 1;
	}
	return (0);
}
