/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 17:40:49 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/16 22:01:52 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		line_checker(char *str, t_cub *cub)
{
	int i;

	i = 0;

	ft_printf("line_checker: %s\n", str);
	while (str[i] == ' ')
		i++;
//	ft_printf("%s\n", (str + i));
//	if (ft_strncmp(str + i, "R ", 2))
//		save_res(str + i + 2, cub);
	if (ft_strchr("NSWE", str[i]))
	{
		if (!texture_saver(str + i, cub))
			return (-1);
	}
	else
		return (0);
//	else if (ft_strchr("FC", str[i]))
//			if

	return (1);
}

int		file_checker(t_cub *cub)
{
	int i;

	i = 0;
	while (cub->map[i][0] != '\0')
	{
		ft_printf("string %i: %s\n", i, cub->map[i]);
		if (line_checker(cub->map[i], cub) == -1)
			return (-1);
		i++;
	}
	return (1);
}
