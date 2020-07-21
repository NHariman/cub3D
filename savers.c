/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   savers.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 21:03:27 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/22 01:40:33 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*save_path(char *str, int i, t_check *check)
{
	str = ft_strtrim(ft_strlower(str), " \n");
	if (i == 1)
		check->north = 1;
	else if (i == 2)
		check->south = 1;
	else if (i == 3)
		check->west = 1;
	else if (i == 4)
		check->east = 1;
	else if (i == 5)
		check->sprite = 1;
	return (str);
}

int		save_texture(char *str, t_cub *cub, t_check *check)
{
	if (!ft_strncmp(str, "NO", 2))
		cub->no = save_path(str + 2, 1, check);
	else if (!ft_strncmp(str, "SO", 2))
		cub->so = save_path(str + 2, 2, check);
	else if (!ft_strncmp(str, "WE", 2))
		cub->we = save_path(str + 2, 3, check);
	else if (!ft_strncmp(str, "EA", 2))
		cub->ea = save_path(str + 2, 4, check);
	else if (!ft_strncmp(str, "S", 1))
		cub->sprite = save_path(str + 2, 5, check);
	else
	{
		ft_printf("invalid or double texture input detected\n");
		return (0);
	}
	return (1);
}

int		save_res(const char *str, t_cub *cub, t_check *check)
{
	int		i;

	i = 0;
	if (check->res)
	{
		ft_printf("double R values detected\n");
		return (-1);
	}
	check->res = valid_res_input(str);
	if (check->res == -1)
	{
		ft_printf("invalid res input\n");
		return (0);
	}
	cub->res_x = ft_atoi(str);
	i = find_res_y(str);
	cub->res_y = ft_atoi(str + i);
	return (1);
}

int		save_rgb(const char *str, t_cub *cub)
{
	int		i;

	i = 0;
	cub->r = ft_atoi(str);
	while ((str[i] == ' ' || ft_isdigit(str[i])) && str[i] != '\0')
	{
		if (str[i] == ',')
			break ;
		i++;
	}
	cub->g = ft_atoi(str + i + 1);
	i++;
	while ((str[i] == ' ' || ft_isdigit(str[i])) && str[i] != '\0')
	{
		if (str[i] == ',')
			break ;
		i++;
	}
	cub->b = ft_atoi(str + i + 1);
	return (1);
}

int		save_colours(const char *str, t_cub *cub, t_check *check)
{
	int hex;

	if (!valid_rgb_input(str + 1))
	{
		ft_printf("Invalid rgb values detected\n");
		return (0);
	}
	save_rgb(str + 1, cub);
	hex = 0;
	if (ft_strncmp(str, "F", 1) && !check->floor)
	{
		cub->floor = hex;
		check->floor = 1;
	}
	else if (ft_strncmp(str, "C", 1) && !check->floor)
	{
		cub->cling = hex;
		check->ceiling = 1;
	}
	else
	{
		ft_printf("invalid or double rgb values detected\n");
		return (0);
	}
	return (1);
}
