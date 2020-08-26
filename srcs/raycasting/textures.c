/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 19:04:31 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/26 21:51:29 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int		fill_text(t_cub *cub, int pov, int type)
{
	int fd;

	fd = open(cub->textures[pov], O_RDONLY);
	if (fd == -1)
		return (ft_fd_errors(25, pov));
	if (type == PNG)
	{
		cub->text[pov].img = mlx_png_file_to_image(cub->mlx.mlx,
			cub->textures[pov], &cub->text[pov].width,
				&cub->text[pov].height);
	}
	else if (type == XPM)
	{
		cub->text[pov].img = mlx_xpm_file_to_image(cub->mlx.mlx,
			cub->textures[pov], &cub->text[pov].width,
				&cub->text[pov].height);
	}
	if (!cub->text[pov].img)
		return (ft_fd_errors(24, pov));
	cub->text[pov].addr = (int *)mlx_get_data_addr(cub->text[pov].img,
		&cub->text[pov].bits_per_pixel, &cub->text[pov].line_length,
			&cub->text[pov].endian);
	return (1);
}

static void		ft_print_warning(t_text text)
{
	if (text.width != text.height)
		ft_printf("- Image is not a square.\n");
	if ((text.width != 0) && ((text.width & (text.width - 1)) != 0))
		ft_printf("- Image width is not a power of 2.\n");
	if ((text.height != 0) && ((text.height & (text.height - 1)) != 0))
		ft_printf("- Image height is not a power of 2.\n");
}

static void		ft_check_valid_texture(t_text text, int type)
{
	if (text.width != text.height ||
	((text.width != 0) && ((text.width & (text.width - 1)) != 0)) ||
	((text.height != 0) && ((text.height & (text.height - 1)) != 0)))
	{
		if (type == NO)
			ft_printf("WARNING\nAbout the NORTH (NO) texture:\n");
		if (type == SO)
			ft_printf("WARNING\nAbout the SOUTH (SO) texture:\n");
		if (type == EA)
			ft_printf("WARNING\nAbout the EAST (EA) texture:\n");
		if (type == WE)
			ft_printf("WARNING\nAbout the WEST (WE) texture:\n");
		if (type == SP)
			ft_printf("WARNING\nAbout the SPRITE (SP) texture:\n");
		ft_print_warning(text);
		ft_printf(
		"This may result in undefined behaviour. (Especially with sprites.)\n");
	}
}

int				ft_set_textures(t_cub *cub)
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
			return (ft_print_error(22));
		if (!cub->text[pov].img)
			return (ft_print_error(21));
		ft_check_valid_texture(cub->text[pov], pov);
		pov++;
	}
	return (1);
}
