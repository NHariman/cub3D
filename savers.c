/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   savers.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 21:03:27 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/16 22:27:20 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*save_path(char *str)
{
	char *path;

	path = ft_strtrim(str, " ");
	return (path);
}

int		texture_saver(char *str, t_cub *cub)
{
	ft_printf("texture_saver: %s\nft_strncmp result: %i\n", str, ft_strncmp(str, "NO ", 3));
	if (!ft_strncmp(str, "NO ", 3))
	{
		ft_printf("texture_saver: %s\n", str);
		cub->no = save_path(str + 3);
	}
	else if (!ft_strncmp(str, "SO ", 3))
	{
		ft_printf("why am i in SO?\n");
		cub->so = save_path(str + 3);
	}
	else if (!ft_strncmp(str, "WE ", 3))
		cub->we = save_path(str + 3);
	else if (!ft_strncmp(str, "EA ", 3))
		cub->ea = save_path(str + 3);
	else
	{
		ft_printf("something went wrong in texture_saver");
		return (1);
	}
	return (1);
}

// int		rgb_saver(char *str, int *i, t_cub *cub)
// {
// 	if (ft_strncmp(str + *i, "F ", 2))
// 		cub->floor = save_hex(str + *i + 2);
// 	else if (ft_strncmp(str + *i, "C ", 2))
// 		cub->cling = save_hex(str + *i + 2);
// 	else
// 		return (0);
// 	return (1);
// }
