/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 20:47:46 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/13 20:16:09 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int			get_img(t_camera *cam, int i, int img_type)
{
	int fd;

	ft_printf("get images?\n");
	fd = open(cam->cub->textures[i].path, O_RDONLY);
	if (img_type == PNG)
		cam->tex[i].texture = mlx_png_file_to_image(cam->mlx.mlx,
							cam->cub->textures[i].path, &cam->tex[i].width,
							&cam->tex[i].height);
	if (img_type == XPM)
		cam->tex[i].texture = mlx_xpm_file_to_image(cam->mlx.mlx,
							cam->cub->textures[i].path, &cam->tex[i].width,
							&cam->tex[i].height);
	cam->tex[i].addr = mlx_get_data_addr(cam->tex[i].texture,
	&cam->tex[i].bits_per_pixel, &cam->tex[i].line_length, &cam->tex[i].endian);
	return (1);
}

int					get_textures(t_camera *cam)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (!ft_strncmp(cam->cub->textures[i].path +
		(ft_strlen(cam->cub->textures[i].path) - 4), ".png", 4))
		{
			if (!get_img(cam, i, PNG))
				exit(1);
		}
		else if (!ft_strncmp(cam->cub->textures[i].path +
		(ft_strlen(cam->cub->textures[i].path) - 4), ".xpm", 4))
		{
			if (!get_img(cam, i, XPM))
				exit(1);
		}
		else
			return (print_error(22));
		if (!cam->tex[i].texture)
			return (print_error(21));
		i++;
	}
	return (1);
}

static int			get_texnr(t_camera *cam)
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

static void			calc_texy(t_camera *cam, t_data tex, int x)
{
	int				y;
	unsigned int	colour;

	y = cam->draw.start;
	colour = 14443520;
	while (y < cam->draw.end)
	{
		cam->wall.texy = (int)cam->texpos & (tex.height - 1);
		cam->texpos += cam->step;
		//colour = tex.addr[tex.height * cam->wall.texy + cam->wall.texx];
		if (cam->ray.side == 1)
			colour = (colour >> 1) & 8355711;
		my_mlx_pixel_put(&cam->mlx.img, x, y, colour);
		y++;
	}
}

void				calc_textures(t_camera *cam, int x)
{
	int nr;

	nr = get_texnr(cam);
	cam->wall.wallx = cam->ray.side == 0 ?
				cam->posy + cam->ray.perpwalldist * cam->raydiry :
				cam->posx + cam->ray.perpwalldist * cam->raydirx;
	cam->wall.wallx -= floor(cam->wall.wallx);
	cam->wall.texx =
			(int)(cam->wall.wallx * (double)cam->tex[nr].width);
	if ((cam->ray.side == 0 && cam->raydirx > 0) ||
				(cam->ray.side == 1 && cam->raydiry < 0))
		cam->wall.texx = cam->tex[nr].width - cam->wall.texx - 1;
	cam->step = 1.0 * cam->tex[nr].height / cam->draw.lineheight;
	cam->texpos =
		(cam->draw.start - cam->cub->res_y / 2 + cam->draw.lineheight / 2) *
		cam->step;
	calc_texy(cam, cam->tex[nr], x);
}
