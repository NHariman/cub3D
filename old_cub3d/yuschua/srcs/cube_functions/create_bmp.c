/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_bmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 10:26:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/20 10:02:21 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int			ft_header_bmp(t_struct_m *main, int fd)
{
	int		width;
	int		padd;
	char	s[54];

	width = main->place.s_width;
	padd = 0;
	ft_bzero(s, 54);
	s[0] = 0X42;
	s[1] = 0x4D;
	while ((3 * width + padd) % 4 != 0)
		padd++;
	s[2] = 3 * (width + padd) * main->place.s_width + 54;
	s[10] = 54;
	s[14] = 40;
	ft_memcpy(s + 18, &main->place.s_width, 4);
	ft_memcpy(s + 22, &main->place.s_height, 4);
	s[26] = 1;
	s[28] = 24;
	write(fd, s, 54);
	return (padd);
}

static void			ft_image(t_struct_m *main)
{
	main->img.img = mlx_new_image(main->vars.mlx, main->place.s_width,
	main->place.s_height);
	if (!main->img.img)
	{
		main->place.error = 24;
		ft_error(main);
	}
	main->img.addr = mlx_get_data_addr(main->img.img, &main->img.bits_per_pixel,
	&main->img.line_length, &main->img.endian);
	set_value_texture(main);
	if (main->place.error_n == 0)
	{
		ft_putstr("error\nerror after map print");
		ft_end_function(main);
	}
	background(main);
	ft_raycasting(main);
	render_next_frame_sprites(main);
	if (main->place.error_n == 0)
	{
		ft_putstr("error\nerror after map print");
		ft_end_function(main);
	}
}

static void			ft_bmp_draw_screenshot(t_struct_m *main, int fd)
{
	char		*string;
	int			padd;
	int			len;
	int			x;

	padd = ft_header_bmp(main, fd);
	len = main->place.s_height - 1;
	while (len >= 0)
	{
		x = 0;
		while (x < main->place.s_width)
		{
			string = (main->img.addr + (len * main->img.line_length
			+ x * (main->img.bits_per_pixel / 8)));
			write(fd, string, 3);
			x++;
		}
		write(fd, "\0\0\0", padd);
		len--;
	}
}

void				ft_bmp(t_struct_m *main)
{
	int			fd;

	fd = open("screen.bmp", O_RDWR | O_CREAT, 0666);
	if (fd < 0)
	{
		ft_putstr("screenshot fd is incorrect");
		close(fd);
	}
	ft_image(main);
	ft_bmp_draw_screenshot(main, fd);
	close(fd);
}

void				start_bmp(t_struct_m *main)
{
	set_value(main);
	if (ft_read_map(main) == 2)
	{
		ft_putstr("error\nnot enough information");
		ft_end_function(main);
	}
	read_map_bmp(main);
	main->vars.mlx = mlx_init();
	ft_bmp(main);
	ft_end_function(main);
}
