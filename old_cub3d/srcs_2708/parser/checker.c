/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 17:40:49 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/26 18:38:23 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int		gather_data(char *str, t_cub *cub, t_check *check)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_strchr("021NSWE", str[i]) && ft_complete_input_data(check))
		return (2);
	else if (ft_strchr(" 120", str[i]) && !ft_complete_input_data(check))
		return (ft_print_error(6));
	else if (!ft_strncmp(str + i, "R ", 2))
		return (!ft_save_res(str + i + 1, cub, check) ? -1 : 1);
	else if (ft_strchr("NSWE", str[i]))
		return (!ft_save_texture(str + i, cub, check) ? -1 : 1);
	else if (ft_strchr("FC", str[i]))
		return (!ft_save_colours(str + i, cub, check) ? -1 : 1);
	return (str[i] == '\n' ? 3 : ft_print_error(28));
}

static int		gather_map(char *str, t_cub *cub, int start)
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
	cub->map = ft_create_array(str + i, cub->filesize - start);
	cub->cpmap = ft_create_array(str + i, cub->filesize - start);
	if (!cub->map || !cub->cpmap || cub->map[0][0] == '\n')
		return (ft_print_error(27));
	if (!ft_valid_map(cub))
		return (ft_print_error(7));
	return (1);
}

int				ft_data_parser(t_cub *cub)
{
	int		i;
	int		j;
	t_check	check;
	int		map;

	i = 0;
	j = 1;
	ft_empty_check(&check);
	while (cub->filearr[i][0] != '\0' && i != cub->filesize)
	{
		j = gather_data(cub->filearr[i], cub, &check);
		if (j == -1 || j == 0)
			return (ft_show_file_error(cub->filearr, i));
		else if (j == 2)
			break ;
		i++;
	}
	map = gather_map(cub->file, cub, i);
	return (map == 1 ? 1 : 0);
}
