/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 19:04:31 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/17 20:03:09 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	fill_text(t_cub *cub, int pov, int type)
{
	int fd;

	fd = open(cub->textures[pov], O_RDONLY);
	if (fd == -1)
		return (print_error(25));
	ft_printf("crash on png?\n");
	if (type == PNG)
	{
		cub->text[pov]->img = mlx_png_file_to_image(cub->mlx.mlx,
			cub->textures[pov], &cub->text[pov]->width,
				&cub->text[pov]->height);
	}
	else if (type == XPM)
	{
		cub->text[pov]->img = mlx_xpm_file_to_image(cub->mlx.mlx,
			cub->textures[pov], &cub->text[pov]->width,
				&cub->text[pov]->height);
	}
	ft_printf("no crash on png?\n");
	if (!cub->text[pov]->img)
		return (print_error(24));
	cub->text[pov]->addr = mlx_get_data_addr(cub->text[pov]->img,
		&cub->text[pov]->bits_per_pixel, &cub->text[pov]->line_length,
			&cub->text[pov]->endian);
	return (1);
}

int			set_textures(t_cub *cub)
{
	int pov;

	pov = 0;
	while (pov <= 4)
	{
		if (!ft_strncmp(cub->textures[pov] +
		(ft_strlen(cub->textures[pov]) - 4), ".png", 4))
		{
			if (!fill_text(cub, pov, PNG))
				exit(1);
		}
		else if (!ft_strncmp(cub->textures[pov] +
		(ft_strlen(cub->textures[pov]) - 4), ".xpm", 4))
		{
			if (!fill_text(cub, pov, XPM))
				exit(1);
		}
		else
			return (print_error(22));
		if (!cub->text[pov]->img)
			return (print_error(21));
		pov++;
	}
	return (1);
}
