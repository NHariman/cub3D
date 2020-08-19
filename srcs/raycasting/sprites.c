/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 22:25:46 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/19 00:55:32 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void			get_sprites(t_cub *cub)
{
	cub->sp.zbuffer = ft_calloc(cub->res_x, sizeof(double));
	cub->sp.sp_order = ft_calloc(cub->sprites, sizeof(int));
	cub->sp.sp_dist = ft_calloc(cub->sprites, sizeof(double));
}
