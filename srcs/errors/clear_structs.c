/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_structs.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 17:59:03 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/03 21:09:20 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int			free_struct(t_cub *cub)
{
	free(cub);
	return (0);
}

// void		empty_cub(t_cub *cub)
// {
// 	cub->path = NULL;
// 	cub->save = 0;
// 	cub->file = NULL;
// 	cub->filearr = NULL;
// 	cub->filesize = 0;
// 	cub->spawn_x = 0;
// 	cub->spawn_y = 0;
// 	cub->spawn_pos = ' ';
// 	cub->res_x = 0;
// 	cub->res_y = 0;
// 	cub->no = NULL;
// 	cub->so = NULL;
// 	cub->we = NULL;
// 	cub->ea = NULL;
// 	cub->sprite = NULL;
// 	cub->floor = 0;
// 	cub->cling = 0;
// 	cub->map = NULL;
// 	cub->cpmap = NULL;
// 	cub->r = 0;
// 	cub->g = 0;
// 	cub->b = 0;
// 	cub->hex = 0;
// }

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
