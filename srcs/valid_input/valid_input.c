/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 20:07:12 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/24 21:08:39 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		valid_res_input(const char *str)
{
	int		i;
	int		j;
	int		check;

	i = 0;
	j = 0;
	check = 0;
	while (j < 3)
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		if (str[i] != '\0' && ft_isdigit(str[i]))
			check++;
		while (str[i] != '\0' && ft_isdigit(str[i]))
			i++;
		j++;
	}
	return ((str[i] == '\n' && check == 2) ? 1 : -1);
}

int		valid_rgb_input(const char *str)
{
	int		i;
	int		j;
	int		check;

	i = 0;
	j = 0;
	check = 0;
	while (j < 4)
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		if (str[i] != '\0' && ft_isdigit(str[i]))
			check++;
		while (str[i] != '\0' && ft_isdigit(str[i]))
			i++;
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		if (str[i] != '\0' && str[i] == ',')
			i++;
		j++;
	}
	if (str[i] == '\n')
		i++;
	return ((str[i] == '\0' && check == 3) ? 1 : 0);
}

int		valid_rgb_values(t_rgb *rgb)
{
	return (rgb->r > 255 || rgb->g > 255 || rgb->b > 255 ||
	rgb->r < 0 || rgb->g < 0 || rgb->b < 0 ? 0 : 1);
}

int		find_res_y(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			break ;
		i++;
	}
	return (i);
}

int		complete_input_data(t_check *check)
{
	return (check->ceiling && check->east && check->floor && check->west &&
		check->north && check->res && check->south && check->sprite ? 1 : 0);
}
