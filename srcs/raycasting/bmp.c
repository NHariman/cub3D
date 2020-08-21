/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/15 22:20:36 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/22 01:06:01 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int			ft_bmp_header(int fd, int x, int y)
{
	int		width;
	int		pad;
	char	s[54];

	width = x;
	pad = 0;
	ft_bzero(s, 54);
	s[0] = 0X42;
	s[1] = 0x4D;
	while ((3 * width + pad) % 4 != 0)
		pad++;
	s[2] = 3 * (width + pad) * x + 54;
	s[10] = 54;
	s[14] = 40;
	ft_memcpy(s + 18, &x, 4);
	ft_memcpy(s + 22, &y, 4);
	s[26] = 1;
	s[28] = 24;
	write(fd, s, 54);
	return (pad);
}

static void			create_image(t_cub *cub, int x, int y)
{
	cub->mlx.img =
		mlx_new_image(cub->mlx.mlx, x, y);
	if (!cub->mlx.img)
		exit(print_error(20));
	cub->mlx.img_addr = mlx_get_data_addr(cub->mlx.img,
		&cub->mlx.img_bits_per_pixel, &cub->mlx.line_length,
			&cub->mlx.endian);
	ft_set_start_values(cub);
	ft_colour_background(cub);
	ft_raycast_walls(cub);
	if (cub->sprites > 0)
		ft_raycast_sprites(cub);
}

static void			save_to_screenshot(t_cub *cub, int fd, int sizex, int sizey)
{
	char	*str;
	int		pad;
	int		len;
	int		x;

	pad = ft_bmp_header(fd, sizex, sizey);
	len = sizey - 1;
	while (len >= 0)
	{
		x = 0;
		while (x < sizex)
		{
			str =
			cub->mlx.img_addr +
				(len * cub->mlx.line_length + x *
					(cub->mlx.img_bits_per_pixel / 8));
			write(fd, str, 3);
			x++;
		}
		write(fd, "\0\0\0", pad);
		len--;
	}
}

void				save_bmp(t_cub *cub)
{
	int			fd;

	fd = open("screen.bmp", O_RDWR | O_CREAT, 0666);
	if (fd < 0)
		exit(print_error(26));
	cub->res_x = cub->res_x > 16384 ? 16384 : cub->res_x;
	cub->res_y = cub->res_y > 16384 ? 16384 : cub->res_y;
	cub->mlx.mlx = mlx_init();
	if (!cub->mlx.mlx)
		exit(print_error(19));
	if (!set_textures(cub))
		exit(1);
	create_image(cub, cub->res_x, cub->res_y);
	save_to_screenshot(cub, fd, cub->res_x, cub->res_y);
	exit(0);
}
