/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utills_six.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 18:50:30 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/29 21:17:20 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	surround_x(t_struct_m *main, int x, int y)
{
	if (main->cubecopy[y][x + 1] == ' ' ||
	main->cubecopy[y + 1][x] == ' ' ||
	main->cubecopy[y + 1][x + 1] == ' ' ||
	main->cubecopy[y - 1][x - 1] == ' ' ||
	main->cubecopy[y][x - 1] == ' ' ||
	main->cubecopy[y - 1][x] == ' ' ||
	main->cubecopy[y - 1][x + 1] == ' ' ||
	main->cubecopy[y + 1][x - 1] == ' ')
		return (1);
	return (0);
}

int			check_valid_x(t_struct_m *main)
{
	int		y;
	int		x;

	y = 1;
	x = 1;
	while (y < main->ray.yy)
	{
		while (x < main->ray.xx)
		{
			if (main->cubecopy[y][x] == 'X')
			{
				if (surround_x(main, x, y) == 1)
					return (1);
			}
			x++;
		}
		y++;
		x = 1;
	}
	return (0);
}

void		render_next_frame_sprites_colourr(t_struct_m *main, int y, int d,
int colour)
{
	main->sprites->texx = (int)(256 * (main->sprite.stripe -
	(-main->sprite.spritewidth / 2 + main->sprite.spritescreenx)) *
	main->texture->texture_width / main->sprite.spritewidth) / 256;
	y = main->sprite.drawstarty;
	if (main->sprite.transformy > 0 && main->sprite.stripe > 0 &&
	main->sprite.stripe < main->place.s_width &&
	main->sprite.transformy < main->zbuffer[main->sprite.stripe])
	{
		while (y < main->sprite.drawendy)
		{
			d = (y) * 256 - main->place.s_height * 128 +
			main->sprite.spriteheight * 128;
			main->sprites->texy = ((d * main->texture[4].texture_height) /
			main->sprite.spriteheight) / 256;
			colour =
			main->texture[4].texture_adress[main->texture[4].texture_width
			* main->sprites->texy + main->sprites->texx];
			if (colour != 0)
				my_mlx_pixel_put(main, main->sprite.stripe, y, colour);
			y++;
		}
	}
}
