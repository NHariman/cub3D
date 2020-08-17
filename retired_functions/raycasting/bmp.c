/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/15 22:20:36 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/16 00:46:58 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int			ft_bmp_header(int x, int y, int fd)
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

static void			create_image(t_camera *cam, int x, int y)
{
	cam->mlx.img.texture =
		mlx_new_image(cam->mlx.mlx, x, y);
	if (!cam->mlx.img.texture)
		exit(print_error(20));
	cam->mlx.img.addr = mlx_get_data_addr(cam->mlx.img.texture,
		&cam->mlx.img.bits_per_pixel, &cam->mlx.img.line_length,
			&cam->mlx.img.endian);
	ft_background(cam);
	//giant_fucking_function(cam);
}

static void			ft_draw_screenshot(t_camera *cam, int fd, int sizex, int sizey)
{
	char	*str;
	int		pad;
	int		len;
	int		x;

	pad = ft_bmp_header(fd, sizex, sizey);
	len = sizey - 1; //screensize but bmp version - 1
	while (len >= 0)
	{
		x = 0;
		while (x < sizex)
		{
			str = cam->mlx.img.addr + (len * cam->mlx.img.line_length + x * (cam->mlx.img.bits_per_pixel / 8));
			write(fd, str, 3);
			x++;
		}
		write(fd, "\0\0\0", pad);
		len--;
	}
}

void				bmp_start(t_cub *cub)
{
	t_camera	*cam;
	int			x;
	int			y;
	int			fd;

	fd = open("screen.bmp", O_RDWR | O_CREAT, 0666);
	if (fd < 0)
		exit(print_error(26));
	cam = ft_calloc(1, sizeof(t_camera));
	set_spawnpoint(cub, cam);
	x = cam->cub->res_x > 16384 ? 16384 : cub->res_x;
	y = cam->cub->res_y > 16384 ? 16384 : cub->res_y;
	cam->mlx.mlx = mlx_init();
	if (!cam->mlx.mlx)
		exit(print_error(19));
	create_image(cam, x, y);
	ft_draw_screenshot(cam, fd, x, y);
	exit(0);
}
