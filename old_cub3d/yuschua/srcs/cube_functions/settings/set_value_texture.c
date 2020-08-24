/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_value_texture.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 14:47:45 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/03 11:43:34 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static	void		set_data_adress_texture(t_struct_m *main)
{
	main->texture[0].texture_adress =
	(int *)(mlx_get_data_addr(main->texture[0].texture,
	&main->texture[0].bits_per_pixel, &main->texture[0].line_lenght,
	&main->texture[0].endian));
	main->texture[1].texture_adress =
	(int *)(mlx_get_data_addr(main->texture[1].texture,
	&main->texture[1].bits_per_pixel, &main->texture[1].line_lenght,
	&main->texture[1].endian));
	main->texture[2].texture_adress =
	(int *)(mlx_get_data_addr(main->texture[2].texture,
	&main->texture[2].bits_per_pixel, &main->texture[2].line_lenght,
	&main->texture[2].endian));
	main->texture[3].texture_adress =
	(int *)(mlx_get_data_addr(main->texture[3].texture,
	&main->texture[3].bits_per_pixel, &main->texture[3].line_lenght,
	&main->texture[3].endian));
	main->texture[4].texture_adress =
	(int *)(mlx_get_data_addr(main->texture[4].texture,
	&main->texture[4].bits_per_pixel, &main->texture[4].line_lenght,
	&main->texture[4].endian));
}

void				set_value_texture(t_struct_m *main)
{
	int		fd;

	fd = -1;
	set_value_texture_no(main, fd);
	set_value_texture_so(main, fd);
	set_value_texture_we(main, fd);
	set_value_texture_ea(main, fd);
	set_value_texture_s(main, fd);
	if (main->texture[0].texture == NULL || main->texture[1].texture == NULL
	|| main->texture[2].texture == NULL || main->texture[3].texture == NULL
	|| main->texture[4].texture == NULL)
	{
		main->place.error = 14;
		ft_error(main);
		ft_end_function(main);
	}
	set_data_adress_texture(main);
}
