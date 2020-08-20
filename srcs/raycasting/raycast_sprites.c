/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_sprites.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/20 21:53:29 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/20 22:51:46 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void			setup_sp(t_cub *cub)
{
	cub->sp.zbuffer = ft_calloc(cub->res_x, sizeof(double));
	cub->sp.sp_order = (int *)ft_calloc(cub->sprites, sizeof(int));
	cub->sp.sp_dist = (double *)ft_calloc(cub->sprites, sizeof(double));
}

/*
** sort sprites:
** the bigger the distance, the more it must be put forward
*/

static void		sortsprites(t_cub *cub)
{
	double		tmp_dist;
	int			tmp_order;
	int			i;

	tmp_dist = 0.0;
	tmp_order = 0;
	i = 0;
	while (i < cub->sprites - 1)
	{
		if (cub->sp.sp_dist[i] < cub->sp.sp_dist[i + 1])
		{
			tmp_dist = cub->sp.sp_dist[i];
			tmp_order = cub->sp.sp_order[i];
			cub->sp.sp_dist[i] = cub->sp.sp_dist[i + 1];
			cub->sp.sp_order[i] = cub->sp.sp_order[i + 1];
			cub->sp.sp_dist[i + 1] = tmp_dist;
			cub->sp.sp_order[i + 1] = tmp_order;
			i = 0;
		}
		i++;
	}
}

// void			ft_raycast_sprites(t_cub *cub)
// {
// 	int i;
// 	int vmovescreen;

// 	i = 0;
// 	ft_calc_sp_dist_and_order(cub);
// 	sortsprites(cub);
// 	while (i < cub->sprites)
// 	{
// 		ft_calc_sp_xy(cub, i);
// 		vmovescreen = (int)(VMOVE / cub->sp.transformy);
// 		ft_calc_sp_draw(cub, vmovescreen);
// 		ft_setup_draw_sprites(cub, vmovescreen);
// 		i++;
// 	}
// }

void			ft_raycast_sprites(t_cub *cub)
{
	int i;
	//int colour;
	int vmovescreen;

	i = 0;
	ft_calc_sp_dist_and_order(cub);
	sortsprites(cub);
	while (i < cub->sprites)
	{
		ft_calc_sp_xy(cub, i);

		vmovescreen = (int)(VMOVE / cub->sp.transformy);
		ft_calc_sp_draw(cub, vmovescreen);
		ft_setup_draw_sprites(cub, vmovescreen);
		// int stripe;	
		// stripe = cub->sp.drawstartx;
		//ft_printf("stripe: %i\ndrawstartx: %i\n", stripe, cub->sp.drawstartx);
		// while (stripe < cub->sp.drawendx)
		// {
		// 	cub->sp.texx = (int)(256 * (stripe - (-cub->sp.spritewidth / 2 + cub->sp.spritescreenx)) * cub->text[SP].width / cub->sp.spritewidth) / 256;
		// 	if (cub->sp.transformy > 0 && stripe > 0 && stripe < cub->res_x && cub->sp.transformy < cub->sp.zbuffer[stripe])
		// 	{
		// 		int y;

		// 		y = cub->sp.drawstarty;
		// 		while (y < cub->sp.drawendy)
		// 		{
		// 			int d;

		// 			d = (y - vmovescreen) * 256 - cub->res_y * 128 + cub->sp.spriteheight * 128;
		// 			cub->sp.texy = ((d * cub->text[SP].height) / cub->sp.spriteheight) / 256;
		// 			colour = cub->text[SP].addr[cub->text[SP].width * cub->sp.texy + cub->sp.texx];
		// 			//ft_printf("colour: %i\n", colour);
		// 			if (colour > 0)
		// 				my_mlx_pixel_put(&cub->mlx, stripe, y, colour);
		// 			y++;
		// 		}
		// 	}
		// 	stripe++;
		// }
		i++;
	}
}