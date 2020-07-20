/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 17:40:49 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/20 20:29:22 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		line_checker(char *str, t_cub *cub, t_check *check)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (!ft_strncmp(str + i, "R", 1))
	{
		if (!save_res(str + i + 1, cub, check))
			return (-1);
	}
	else if (ft_strchr("NSWE", str[i]))
	{
		if (!save_texture(str + i, cub, check))
			return (-1);
	}
	else if (ft_strchr("FC", str[i]))
	{
		if (!save_colours(str + i, cub, check))
			return (-1);
	}
	else
		return (0);
	return (1);
}

int		file_checker(t_cub *cub)
{
	int		i;
	t_check	check;

	i = 0;
	empty_check(&check);
	while (cub->map[i][0] != '\0')
	{
		if (line_checker(cub->map[i], cub, &check) == -1)
			return (-1);
		i++;
	}
	return (1);
}
