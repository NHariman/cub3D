/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_struct.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/16 23:43:53 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/19 16:43:10 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		print_struct(t_cub *cub)
{
	int i;

	i = 0;
	// ft_printf("textures:\nNO: %s!\n", cub->textures[NO]);
	// ft_printf("textures:\nSO: %s!\n", cub->textures[SO]);
	// ft_printf("textures:\nWE: %s!\n", cub->textures[WE]);
	// ft_printf("textures:\nEA: %s!\n", cub->textures[EA]);
	// ft_printf("textures:\nSP: %s!\n", cub->textures[SP]);
	// ft_printf("filepath: %s!\n", cub->path);
	// ft_printf("file: %s!\n", cub->file);
	// ft_printf("whole file in 2D array:\n");
	// show_map(cub->filearr);
	// ft_printf("\nfilesize: %i!\nspawn_pos: %c!\nspawn_x: %i!\nspawn_y: %i!\n",
	// 	cub->filesize, cub->spawn_pos, cub->spawn_x, cub->spawn_y);
	// ft_printf("sprites: %i!\n", cub->sprites);
	// ft_printf("res_x: %i!\nres_y: %i!\nfloor int: %i!\nceiling int: %i!\n",
	// 	cub->res_x, cub->res_y, cub->floor, cub->cling);
	// ft_printf("map:\n");
	// show_map(cub->map);
	// ft_printf("\ncpmap:\n");
	// show_map(cub->filearr);
	// ft_printf("show what's in the sprites list:\n");
	while (i < cub->sprites)
	{
		ft_printf("%i: x[%i] // y[%i]\n", i, cub->sp.sprites[i].x, cub->sp.sprites[i].y);
		i++;
	}
}

void		printsort(t_cub *cub)
{
	int i;

	i = 0;
	while (i < cub->sprites)
	{
		ft_printf("order: %i\ndistance: %i\n", cub->sp.sp_order[i], cub->sp.sp_dist[i]);
		i++;
	}
}
