/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 17:40:49 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/17 21:41:05 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		line_checker(char *str, t_cub *cub)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (!ft_strncmp(str + i, "R", 1))
		save_res(str + i + 1, cub);
	else if (ft_strchr("NSWE", str[i]))
	{
		if (!save_texture(str + i, cub))
			return (-1);
	}
	else if (ft_strchr("FC", str[i]))
		save_colours(str + i, cub);
	else
		return (0);
	return (1);
}

int		file_checker(t_cub *cub)
{
	int i;

	i = 0;
	while (cub->map[i][0] != '\0')
	{
		if (line_checker(cub->map[i], cub) == -1)
			return (-1);
		i++;
	}
	return (1);
}
