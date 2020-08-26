/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_pixels.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/20 21:37:47 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/26 22:15:10 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		ft_draw_walls(t_cub *cub, int pov, int x)
{
	int		texy;
	int		colour;

	while (cub->draw.drawstart < cub->draw.drawend)
	{
		texy = (int)cub->texxy.texpos & (cub->text[pov].height - 1);
		cub->texxy.texpos += cub->texxy.step;
		colour = cub->text[pov].addr[(cub->text[pov].line_length * texy / 4) +
					cub->texxy.texx];
		if (cub->side.side == 1)
			colour = (colour >> 1) & 8355711;
		my_mlx_pixel_put(&cub->mlx, x, cub->draw.drawstart, colour);
		cub->draw.drawstart++;
	}
}

static void	ft_draw_sprites(t_cub *cub, int vmovescreen, int stripe)
{
	int y;
	int d;
	int	colour;

	y = cub->sp.drawstarty;
	while (y < cub->sp.drawendy)
	{
		d = (y - vmovescreen) * 256 - cub->res_y *
				128 + cub->sp.spriteheight * 128;
		cub->sp.texy = ((d * cub->text[SP].height) /
						cub->sp.spriteheight) / 256;
		colour = cub->text[SP].addr[(cub->text[SP].line_length *
					cub->sp.texy / 4) + cub->sp.texx];
		if (colour < 0)
			colour = 0;
		if (colour > 0)
			my_mlx_pixel_put(&cub->mlx, stripe, y, colour);
		y++;
	}
}

static int	ft_sprite_statement(t_cub *cub, int stripe)
{
	return (cub->sp.transformy > 0 &&
				stripe > 0 &&
					stripe < cub->res_x &&
						cub->sp.transformy < cub->sp.zbuffer[stripe] ? 1 : 0);
}

void		ft_setup_draw_sprites(t_cub *cub, int vmovescreen)
{
	int		stripe;

	stripe = cub->sp.drawstartx;
	while (stripe < cub->sp.drawendx)
	{
		cub->sp.texx =
			(int)(256 * (stripe - (-cub->sp.spritewidth / 2 +
			cub->sp.spritescreenx)) *
				cub->text[SP].width / cub->sp.spritewidth) / 256;
		if (ft_sprite_statement(cub, stripe))
			ft_draw_sprites(cub, vmovescreen, stripe);
		stripe++;
	}
}
