/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_structs.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 17:59:03 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/20 21:48:35 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		empty_cub(t_cub *cub)
{
	cub->path = NULL;
	cub->save = 0;
	cub->file = NULL;
	cub->pos_sprite = 0;
	cub->filesize = 0;
	cub->x = 0;
	cub->y = 0;
	cub->res_x = 0;
	cub->res_y = 0;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->sprite = NULL;
	cub->floor = 0;
	cub->cling = 0;
	cub->map = NULL;
	cub->cpmap = NULL;
	cub->r = 0;
	cub->g = 0;
	cub->b = 0;
	cub->hex = 0;
}

void		free_strings(t_cub *cub)
{
	if (cub->path)
		free(cub->path);
	if (cub->file)
		free(cub->file);
	if (cub->no)
		free(cub->no);
	if (cub->so)
		free(cub->so);
	if (cub->ea)
		free(cub->ea);
	if (cub->we)
		free(cub->we);
	if (cub->sprite)
		free(cub->sprite);
	if (cub->cpmap)
		free(cub->cpmap);
}

void		free_struct(t_cub *cub)
{
	free_strings(cub);
	free_array(cub);
	empty_cub(cub);
}

int			free_array(t_cub *cub)
{
	int i;
	int j;

	i = cub->filesize;
	j = 0;
	while (i >= 0)
	{
		if (cub->map[cub->filesize][0] != '\0')
		{
			free(cub->map[cub->filesize]);
			j++;
		}
		i--;
	}
	free(cub->map);
	return (j == cub->filesize ? 1 : -1);
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
