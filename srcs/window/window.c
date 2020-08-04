/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 23:05:57 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/04 14:55:59 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void		get_png(void *mlx, t_cub *cub, int i)
{
	cub->textures[i].texture = mlx_png_file_to_image(mlx,
							cub->textures[i].path, &cub->textures[i].width,
							&cub->textures[i].height);
}

static void		get_xpm(void *mlx, t_cub *cub, int i)
{
	cub->textures[i].texture = mlx_xpm_file_to_image(mlx,
							cub->textures[i].path, &cub->textures[i].width,
							&cub->textures[i].height);
}

int				get_textures(void *mlx, t_cub *cub)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (!ft_strncmp(cub->textures[i].path +
		(ft_strlen(cub->textures[i].path) - 4), ".png", 4))
			get_png(mlx, cub, i);
		else if (!ft_strncmp(cub->textures[i].path +
		(ft_strlen(cub->textures[i].path) - 4), ".xpm", 4))
			get_xpm(mlx, cub, i);
		else
			return (print_error(22));
		if (!cub->textures[i].texture)
			return (print_error(21));
		i++;
	}
	return (1);
}

int				ray_time(t_cub *cub)
{
	void		*mlx;
	void		*mlx_img;
	t_camera	cam;

	set_spawnpoint(cub);
	mlx = mlx_init();
	if (!mlx)
		return (print_error(19));
	if (!get_textures(mlx, cub))
		return (0);
	mlx_img = mlx_new_window(mlx, cub->res_x, cub->res_y, "Cub3D");
	if (!mlx_img)
		return (mlx_exit(mlx, mlx_img, 20));
	while (mlx_loop(mlx))
	{
		
	}
}
