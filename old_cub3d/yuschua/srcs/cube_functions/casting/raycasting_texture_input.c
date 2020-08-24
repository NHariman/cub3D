/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting_texture_input.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 13:52:53 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/12 15:13:23 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void		ft_wall(t_struct_m *main)
{
	if (main->ray.side == 0)
		main->ray.wallx = main->ray.posy + main->ray.perpwalldist *
		main->ray.raydiry;
	else
		main->ray.wallx = main->ray.posx + main->ray.perpwalldist *
		main->ray.raydirx;
	main->ray.wallx -= floor(main->ray.wallx);
	main->ray.texx = (int)(main->ray.wallx * (double)
	(main->texture[main->ray.texnum].texture_width));
	if (main->ray.side == 0 && main->ray.raydirx > 0)
		main->ray.texx = main->texture[main->ray.texnum].texture_width
		- main->ray.texx - 1;
	if (main->ray.side == 1 && main->ray.raydiry < 0)
		main->ray.texx = main->texture[main->ray.texnum].texture_width
		- main->ray.texx - 1;
	main->ray.step = 1.0 * main->texture[main->ray.texnum].texture_height
	/ main->ray.lineheight;
	main->ray.texpos = (main->ray.drawstart - main->place.s_height / 2
	+ main->ray.lineheight / 2) * main->ray.step;
}

static void		ft_wall_texture_input(t_struct_m *main)
{
	int		colour;

	colour = 0;
	while (main->ray.drawstart <= main->ray.drawend)
	{
		main->ray.texy = (int)(main->ray.texpos) &
		(main->texture[main->ray.texnum].texture_height - 1);
		main->ray.texpos += main->ray.step;
		colour = (main->texture[main->ray.texnum].texture_adress
		[main->texture[main->ray.texnum].texture_height *
		main->ray.texy + main->ray.texx]);
		my_mlx_pixel_put(main, main->ray.x, main->ray.drawstart, colour);
		main->ray.drawstart++;
	}
}

void			verline_structure(t_struct_m *main)
{
	int		h;
	int		i;
	int		colour;

	colour = -1;
	h = main->place.s_height / 2;
	i = 0;
	if (main->ray.side == 0)
	{
		if (main->ray.posx > main->ray.mapx)
			main->ray.texnum = 0;
		if (main->ray.posx < main->ray.mapx)
			main->ray.texnum = 1;
	}
	if (main->ray.side == 1)
	{
		if (main->ray.posy > main->ray.mapy)
			main->ray.texnum = 2;
		if (main->ray.posy < main->ray.mapy)
			main->ray.texnum = 3;
	}
	ft_wall(main);
	ft_wall_texture_input(main);
}
