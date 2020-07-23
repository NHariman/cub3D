/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 17:40:49 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/23 02:00:40 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int		gather_data(char *str, t_cub *cub, t_check *check)
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

static int		gather_map(char *str, t_cub *cub, int start, t_check *check)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && j != start)
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	cub->map = create_array(str + i + 1, cub->filesize - start);
	if (!cub->map)
		return (0);
	if (!valid_map(cub->map, cub->filesize - start, check))
	{
		ft_printf("invalid map detected\n");
		return (0);
	}
	return (1);
}

int				data_parser(t_cub *cub)
{
	int		i;
	int		j;
	t_check	check;

	i = 0;
	j = 1;
	empty_check(&check);
	while (cub->filearr[i][0] != '\0' && i != cub->filesize)
	{
		j = gather_data(cub->filearr[i], cub, &check);
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
	return (gather_map(cub->file, cub, i, &check) == 1 ? 1 : -1);
}
