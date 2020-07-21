/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 17:40:49 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/22 01:38:50 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int		data_checker(char *str, t_cub *cub, t_check *check)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '1' && complete_input_data(check))
		return (2);
	else if (((str[i] == '1' && !complete_input_data(check)) || str[i] == '0'))
		return (0);
	else if (!ft_strncmp(str + i, "R", 1))
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
	return (1);
}

int				file_checker(t_cub *cub)
{
	int		i;
	int		j;
	t_check	check;

	i = 0;
	j = 1;
	empty_check(&check);
	while (cub->map[i][0] != '\0')
	{
		j = data_checker(cub->map[i], cub, &check);
		if (j == -1 || j == 0)
		{
			if (j == 0)
				ft_printf("invalid map detected\n");
			return (-1);
		}
		else if (j == 2)
			break ;
		i++;
	}
	return (1);
}
