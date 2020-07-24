/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 17:40:49 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/24 23:53:17 by nhariman      ########   odam.nl         */
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
	else if ((str[i] == '0' || str[i] == '2' || str[i] == '1') &&
				!complete_input_data(check))
		return (print_error(6));
	else if (!ft_strncmp(str + i, "R", 1))
		return (!save_res(str + i + 1, cub, check) ? -1 : 1);
	else if (ft_strchr("NSWE", str[i]))
		return (!save_texture(str + i, cub, check) ? -1 : 1);
	else if (ft_strchr("FC", str[i]))
		return (!save_colours(str + i, cub, check) ? -1 : 1);
	return (1);
}

static int		check_under(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '0' || str[i] == '2' || str[i] == '1'))
		return (1);
	else if (!ft_strncmp(str + i, "R", 1))
		return (print_error(8));
	else if (ft_strchr("NSWE", str[i]))
		return (print_error(8));
	else if (ft_strchr("FC", str[i]))
		return (print_error(8));
	return (1);
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
	cub->map = create_array(str + i, cub->filesize - start);
	cub->cpmap = create_array(str + i, cub->filesize - start);
	if (!cub->map || !cub->cpmap)
		return (0);
	if (!valid_map(cub))
		return (print_error(7));
	return (1);
}

static int		check_last_element(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (cub->filearr[cub->filesize - 1 - i])
	{
		j = check_under(cub->filearr[cub->filesize - 1 - i]);
		if (j == 0)
			return (0);
		if (j == 1)
			return (1);
		i++;
	}
	return (0);
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
			return (-1);
		else if (j == 2)
			break ;
		i++;
	}
	if (!check_last_element(cub))
		return (-1);
	return (gather_map(cub->file, cub, i) == 1 ? 1 : -1);
}
