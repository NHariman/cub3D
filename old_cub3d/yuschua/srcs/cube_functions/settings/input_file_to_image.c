/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_file_to_image.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 15:16:25 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/23 16:06:49 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void			set_value_texture_no(t_struct_m *main, int fd)
{
	fd = open(main->place.no, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strnstr(main->place.no, ".xpm",
		ft_strlen(main->place.no)) != NULL)
		{
			main->texture[2].texture = mlx_xpm_file_to_image(main->vars.mlx,
			main->place.no, &(main->texture[2].texture_width),
			&(main->texture[2].texture_height));
		}
		else if (ft_strnstr(main->place.no, ".png",
		ft_strlen(main->place.no)) != NULL)
		{
			main->texture[2].texture = mlx_png_file_to_image(main->vars.mlx,
			main->place.no, &(main->texture[2].texture_width),
			&(main->texture[2].texture_height));
		}
	}
	else
	{
		main->place.error = 19;
		ft_error(main);
	}
}

void			set_value_texture_we(t_struct_m *main, int fd)
{
	fd = open(main->place.we, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strnstr(main->place.we, ".xpm",
		ft_strlen(main->place.we)) != NULL)
		{
			main->texture[0].texture = mlx_xpm_file_to_image(main->vars.mlx,
			main->place.we, &(main->texture[0].texture_width),
			&(main->texture[0].texture_height));
		}
		else if (ft_strnstr(main->place.we, ".png",
		ft_strlen(main->place.we)) != NULL)
		{
			main->texture[0].texture = mlx_png_file_to_image(main->vars.mlx,
			main->place.we, &(main->texture[0].texture_width),
			&(main->texture[0].texture_height));
		}
	}
	else
	{
		main->place.error = 21;
		ft_error(main);
	}
}

void			set_value_texture_so(t_struct_m *main, int fd)
{
	fd = open(main->place.so, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strnstr(main->place.so, ".xpm",
		ft_strlen(main->place.so)) != NULL)
		{
			main->texture[3].texture = mlx_xpm_file_to_image(main->vars.mlx,
			main->place.so, &(main->texture[3].texture_width),
			&(main->texture[3].texture_height));
		}
		else if (ft_strnstr(main->place.so, ".png",
		ft_strlen(main->place.so)) != NULL)
		{
			main->texture[3].texture = mlx_png_file_to_image(main->vars.mlx,
			main->place.so, &(main->texture[3].texture_width),
			&(main->texture[3].texture_height));
		}
	}
	else
	{
		main->place.error = 20;
		ft_error(main);
	}
}

void			set_value_texture_ea(t_struct_m *main, int fd)
{
	fd = open(main->place.ea, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strnstr(main->place.ea, ".xpm",
		ft_strlen(main->place.ea)) != NULL)
		{
			main->texture[1].texture = mlx_xpm_file_to_image(main->vars.mlx,
			main->place.ea, &(main->texture[1].texture_width),
			&(main->texture[1].texture_height));
		}
		else if (ft_strnstr(main->place.ea, ".png",
		ft_strlen(main->place.ea)) != NULL)
		{
			main->texture[1].texture = mlx_png_file_to_image(main->vars.mlx,
			main->place.ea, &(main->texture[1].texture_width),
			&(main->texture[1].texture_height));
		}
	}
	else
	{
		main->place.error = 22;
		ft_error(main);
	}
}

void			set_value_texture_s(t_struct_m *main, int fd)
{
	fd = open(main->place.s, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strnstr(main->place.s, ".xpm",
		ft_strlen(main->place.s)) != NULL)
		{
			main->texture[4].texture = mlx_xpm_file_to_image(main->vars.mlx,
			main->place.s, &main->texture[4].texture_width,
			&main->texture[4].texture_height);
		}
		else if (ft_strnstr(main->place.s, ".png",
		ft_strlen(main->place.s)) != NULL)
		{
			main->texture[4].texture = mlx_png_file_to_image(main->vars.mlx,
			main->place.s, &main->texture[4].texture_width,
			&main->texture[4].texture_height);
		}
	}
	else
	{
		main->place.error = 23;
		ft_error(main);
	}
}
