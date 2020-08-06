/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_structs.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 17:59:03 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/06 16:47:49 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int			free_struct(t_cub *cub)
{
	free(cub);
	return (0);
}

void		empty_check(t_check *check)
{
	check->res = 0;
	check->north = 0;
	check->south = 0;
	check->east = 0;
	check->west = 0;
	check->sprite = 0;
	check->floor = 0;
	check->ceiling = 0;
}

void		empty_buf(char ***buf, int y, int x)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
		{
			*buf[j][i] = 0;
			i++;
		}
		i = 0;
		j++;
	}
}
