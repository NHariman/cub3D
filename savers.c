/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   savers.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 21:03:27 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/17 21:49:31 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*save_path(char *str)
{
	char *path;

	path = ft_strtrim(str, " \n");
	return (path);
}

int		save_texture(char *str, t_cub *cub)
{
	if (!ft_strncmp(str, "NO", 2))
		cub->no = save_path(str + 2);
	else if (!ft_strncmp(str, "SO", 2))
		cub->so = save_path(str + 2);
	else if (!ft_strncmp(str, "S", 1))
		cub->sprite = save_path(str + 1);
	else if (!ft_strncmp(str, "WE", 2))
		cub->we = save_path(str + 2);
	else if (!ft_strncmp(str, "EA", 2))
		cub->ea = save_path(str + 2);
	else
	{
		ft_printf("something went wrong in texture_saver");
		return (0);
	}
	return (1);
}

int		save_res(char *str, t_cub *cub)
{
	int		i;

	i = 0;
	cub->res_x = ft_atoi(str);
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			break ;
		i++;
	}
	cub->res_y = ft_atoi(str + i);
	return (1);
}

int		save_rgb(char *str, t_cub *cub)
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

int		save_colours(char *str, t_cub *cub)
{
	int hex;

	save_rgb(str + 1, cub);
	hex = 0;
	if (ft_strncmp(str, "F", 1))
		cub->floor = hex;
	else if (ft_strncmp(str, "C", 1))
		cub->cling = hex;
	else
		return (0);
	return (1);
}
