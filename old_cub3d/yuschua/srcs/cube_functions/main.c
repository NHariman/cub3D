/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:41:21 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/20 11:37:01 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void			check_value(t_struct_m *main)
{
	if (main->place.ccol1 < 0 || main->place.ccol2 < 0 || main->place.ccol3 < 0
	|| main->place.ccol1 > 255 || main->place.ccol2 > 255 ||
	main->place.ccol3 > 255)
	{
		main->place.error = 51;
		ft_error(main);
		ft_end_function(main);
	}
	if (main->place.fcol1 < 0 || main->place.fcol2 < 0 || main->place.fcol3 < 0
	|| main->place.fcol1 > 255 || main->place.fcol2 > 255 ||
	main->place.fcol3 > 255)
	{
		main->place.error = 52;
		ft_error(main);
		ft_end_function(main);
	}
}

void			ft_mlx_loop(t_struct_m *main)
{
	main->vars.mlx = mlx_init();
	main->vars.win = mlx_new_window(main->vars.mlx, main->place.s_width,
	main->place.s_height, "cube");
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
	mlx_hook(main->vars.win, 2, 1L << 0, ft_push_key, main);
	mlx_hook(main->vars.win, 3, 1L << 1, ft_release_key, main);
	mlx_hook(main->vars.win, 17, 1L << 0, ft_close, main);
	mlx_loop_hook(main->vars.mlx, render_next_frame_structure, main);
	mlx_loop(main->vars.mlx);
}

void			read_map(t_struct_m *main)
{
	if (ft_size_store_map(main) == 1)
	{
		ft_putstr("error\nsize store error");
		ft_end_function(main);
	}
	check_value(main);
	check_screen(main);
	set_location(main);
	spritesnumb(main);
	if (check_fill(main) == 1)
	{
		ft_putstr("error\nerror in check_fill");
		ft_end_function(main);
	}
	printmap(main);
	if (main->place.error_n == 0)
	{
		ft_putstr("error\nerror after map print");
		ft_end_function(main);
	}
}

static void		start_screen(t_struct_m *main)
{
	set_value(main);
	if (ft_read_map(main) == 2)
	{
		ft_putstr("error\nnot enough information");
		ft_end_function(main);
	}
	read_map(main);
	ft_mlx_loop(main);
}

int				main(int argc, char **argv)
{
	t_struct_m *main;

	main = ft_calloc(1, sizeof(t_struct_m));
	if (argc == 1 || argc >= 4 || argv[1] == NULL == 1)
	{
		ft_putstr("error\nincorrect amount of input");
		ft_end_function(main);
	}
	if (ft_strnstr_cub(argv[1], ".cub") == 1)
	{
		ft_putstr("error\n.cub not at the end of the file");
		ft_end_function(main);
	}
	else
		main->map = ft_strdup(argv[1]);
	if (argv[2] != NULL)
	{
		if (ft_strncmp_map(argv[2], "--save") == 0)
			start_bmp(main);
		ft_putstr("error\n--save incorrectly written");
		ft_end_function(main);
	}
	start_screen(main);
}
