/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 20:47:46 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/05 22:52:40 by nhariman      ########   odam.nl         */
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

static int		get_texnr(t_camera *cam)
{
	if (cam->ray.side == 0)
	{
		if (cam->posx > cam->ray.mapx)
			return (NO);
		else
			return (EA);
	}
	else
	{
		if (cam->posy > cam->ray.mapy)
			return (SO);
		else
			return (WE);
	}
}

void			calc_textures(t_camera *cam, t_cub *cub, int *buf)
{
	int nr;

	nr = get_texnr(cam);
	cam->wall.wallx = cam->ray.side == 0 ?
				cam->posy + cam->ray.perpwalldist * cam->raydiry :
				cam->posx + cam->ray.perpwalldist * cam->raydirx;
	cam->wall.wallx -= floor(cam->wall.wallx);
	cam->wall.texx =
			(int)(cam->wall.wallx * (double)cub->textures[nr].width);
	if ((cam->ray.side == 0 && cam->raydirx > 0) ||
				cam->ray.side == 1 && cam->raydiry < 0)
		cam->wall.texx = cub->textures[nr].width - cam->wall.texx - 1;
	cam->step = 1.0 * cub->textures[nr].height / cam->draw.lineheight;
	cam->texpos =
		(cam->draw.start - cub->res_y / 2 + cam->draw.lineheight / 2) *
		cam->step;
	// STILL NEEDS TO USE THE BUFFER!!!!
}
