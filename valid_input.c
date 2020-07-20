/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 20:07:12 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/20 22:24:31 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		valid_res_input(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 3)
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		while (str[i] != '\0' && ft_isdigit(str[i]))
			i++;
		j++;
	}
	return (str[i] == '\n' ? 1 : -1);
}

int		valid_rgb_input(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		while (str[i] != '\0' && ft_isdigit(str[i]))
			i++;
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		if (str[i] != '\0' && str[i] == ',')
			i++;
		j++;
	}
	return (str[i] == '\n' ? 1 : 0);
}

int		find_res_y(char *str)
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
