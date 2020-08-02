/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 23:05:57 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/02 21:47:18 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int   set_window(t_cub *cub)
{
    void    *mlx;
    void    *mlx_win;
    
    mlx = mlx_init();
    if (mlx == NULL)
        return (0);
    mlx_win = mlx_new_window(mlx, cub->res_x, cub->res_y, "Cub3D");


}
