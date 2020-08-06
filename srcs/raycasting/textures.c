/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 20:47:46 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/06 16:32:55 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void		get_img(void *mlx, t_cub *cub, int i, int img_type)
{
	if (img_type == PNG)
		cub->textures[i].texture = mlx_png_file_to_image(mlx,
							cub->textures[i].path, &cub->textures[i].width,
							&cub->textures[i].height);
	if (img_type == XPM)
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
			get_img(mlx, cub, i, PNG);
		else if (!ft_strncmp(cub->textures[i].path +
		(ft_strlen(cub->textures[i].path) - 4), ".xpm", 4))
			get_img(mlx, cub, i, XPM);
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

static void			calc_texy(t_camera *cam, t_texture tex,
						unsigned int **buf, int x)
{
	int y;

	y = cam->draw.start;
	while (y < cam->draw.end)
	{
		cam->wall.texy = (int)cam->texpos & (tex.height - 1);
		cam->texpos += cam->step;
		cam->wall.colour = tex.texture[tex.height * cam->wall.texy + cam->wall.texx];
		if (cam->ray.side == 1)
			cam->wall.colour = (cam->wall.colour >> 1) && 8355711;
		buf[y][x] = cam->wall.colour;
		y++;
	}
}

void			calc_textures(t_camera *cam, t_cub *cub,
									unsigned int **buf, int x)
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
	calc_texy(cam, cub->textures[nr], buf, x);
}
