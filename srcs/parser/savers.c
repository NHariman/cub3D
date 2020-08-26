/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   savers.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 21:03:27 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/26 18:39:24 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_save_path(char *str, int i, t_check *check)
{
	str = ft_strtrim(ft_strlower(str), " \n");
	if (i == NO)
		check->north = 1;
	else if (i == SO)
		check->south = 1;
	else if (i == WE)
		check->west = 1;
	else if (i == EA)
		check->east = 1;
	else if (i == SP)
		check->sprite = 1;
	return (str);
}

int		ft_save_texture(char *str, t_cub *cub, t_check *check)
{
	if (!ft_strncmp(str, "NO ", 3) && !check->north)
		cub->textures[NO] = ft_save_path(str + 3, NO, check);
	else if (!ft_strncmp(str, "SO ", 3) && !check->south)
		cub->textures[SO] = ft_save_path(str + 3, SO, check);
	else if (!ft_strncmp(str, "WE ", 3) && !check->west)
		cub->textures[WE] = ft_save_path(str + 3, WE, check);
	else if (!ft_strncmp(str, "EA ", 3) && !check->east)
		cub->textures[EA] = ft_save_path(str + 3, EA, check);
	else if (!ft_strncmp(str, "S ", 2) && !check->sprite)
		cub->textures[SP] = ft_save_path(str + 1, SP, check);
	else
		return (ft_print_error(1));
	return (1);
}

int		ft_save_res(const char *str, t_cub *cub, t_check *check)
{
	int		i;

	i = 0;
	if (check->res)
		return (ft_print_error(2));
	check->res = ft_valid_res_input(str);
	if (check->res == -1)
		return (ft_print_error(3));
	cub->res_x = ft_atoi(str);
	if (cub->res_x == 0)
		return (ft_print_error(31));
	if (cub->res_x < 0)
		cub->res_x = 2147483647;
	i = ft_find_res_y(str);
	cub->res_y = ft_atoi(str + i);
	if (cub->res_y == 0)
		return (ft_print_error(32));
	if (cub->res_y < 0)
		cub->res_y = 2147483647;
	return (1);
}

int		ft_save_rgb(const char *str, t_rgb *rgb)
{
	int		i;

	i = 0;
	rgb->r = ft_atoi(str);
	while ((str[i] == ' ' || ft_isdigit(str[i])) && str[i] != '\0')
	{
		if (str[i] == ',')
			break ;
		i++;
	}
	rgb->g = ft_atoi(str + i + 1);
	i++;
	while ((str[i] == ' ' || ft_isdigit(str[i])) && str[i] != '\0')
	{
		if (str[i] == ',')
			break ;
		i++;
	}
	rgb->b = ft_atoi(str + i + 1);
	return (1);
}

int		ft_save_colours(const char *str, t_cub *cub, t_check *check)
{
	int		hex;
	t_rgb	rgb;

	if (!ft_valid_rgb_input(str + 1))
		return (ft_print_error(4));
	ft_save_rgb(str + 1, &rgb);
	if (!ft_valid_rgb_values(&rgb))
		return (ft_print_error(5));
	hex = ft_get_hex(rgb.r, rgb.g, rgb.b);
	if (!ft_strncmp(str, "F", 1) && !check->floor)
	{
		cub->floor = hex;
		check->floor = 1;
	}
	else if (!ft_strncmp(str, "C", 1) && !check->ceiling)
	{
		cub->cling = hex;
		check->ceiling = 1;
	}
	else
		return (ft_print_error(5));
	return (1);
}
