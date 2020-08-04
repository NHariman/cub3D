/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   savers.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 21:03:27 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/04 11:15:35 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*save_path(char *str, int i, t_check *check, t_cub *cub)
{
	str = ft_strtrim(ft_strlower(str), " ");
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

int		save_texture(char *str, t_cub *cub, t_check *check)
{
	if (!ft_strncmp(str, "NO", 2) && !check->north)
		cub->textures[NO].path = save_path(str + 2, NO, check, cub);
	else if (!ft_strncmp(str, "SO", 2) && !check->south)
		cub->textures[SO].path = save_path(str + 2, SO, check, cub);
	else if (!ft_strncmp(str, "WE", 2) && !check->west)
		cub->textures[WE].path = save_path(str + 2, WE, check, cub);
	else if (!ft_strncmp(str, "EA", 2) && !check->east)
		cub->textures[EA].path = save_path(str + 2, EA, check, cub);
	else if (!ft_strncmp(str, "S", 1) && !check->sprite)
		cub->textures[SP].path = save_path(str + 1, SP, check, cub);
	else
		return (print_error(1));
	return (1);
}

int		save_res(const char *str, t_cub *cub, t_check *check)
{
	int		i;

	i = 0;
	if (check->res)
		return (print_error(2));
	check->res = valid_res_input(str);
	if (check->res == -1)
		return (print_error(3));
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
		return (print_error(4));
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
		return (print_error(5));
	return (1);
}
