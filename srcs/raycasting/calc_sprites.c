/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 22:25:46 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/26 18:10:24 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		ft_calc_sp_dist_and_order(t_cub *cub)
{
	int		i;

	i = 0;
	while (i < cub->sprites)
	{
		cub->sp.sp_order[i] = i;
		cub->sp.sp_dist[i] =
			(pow(cub->set.posx - ((double)cub->sp.sprites[i].x), 2) +
				pow(cub->set.posy - ((double)cub->sp.sprites[i].y), 2));
		i++;
	}
}

void		ft_calc_sp_xy(t_cub *cub, int i)
{
	cub->sp.spritex = cub->sp.sprites[cub->sp.sp_order[i]].x - cub->set.posx;
	cub->sp.spritey = cub->sp.sprites[cub->sp.sp_order[i]].y - cub->set.posy;
	cub->sp.invdet = 1.0 /
			(cub->set.planex * cub->set.diry - cub->set.dirx * cub->set.planey);
	cub->sp.transformx = cub->sp.invdet *
			(cub->set.diry * cub->sp.spritex - cub->set.dirx * cub->sp.spritey);
	cub->sp.transformy = cub->sp.invdet *
			(-cub->set.planey * cub->sp.spritex + cub->set.planex *
				cub->sp.spritey);
	cub->sp.spritescreenx = (int)((cub->res_x / 2) *
							(1 + cub->sp.transformx / cub->sp.transformy));
}

void		ft_calc_sp_draw(t_cub *cub, int vmovescreen)
{
	cub->sp.spriteheight = abs((int)(cub->res_y / (cub->sp.transformy))) / VDIV;
	cub->sp.drawstarty = -cub->sp.spriteheight / 2 + cub->res_y / 2
							+ vmovescreen;
	if (cub->sp.drawstarty < 0)
		cub->sp.drawstarty = 0;
	cub->sp.drawendy = cub->sp.spriteheight / 2 + cub->res_y / 2 + vmovescreen;
	if (cub->sp.drawendy >= cub->res_y)
		cub->sp.drawendy = cub->res_y - 1;
	cub->sp.spritewidth = abs((int)(cub->res_y / (cub->sp.transformy))) / UDIV;
	cub->sp.drawstartx = -(cub->sp.spritewidth) / 2 + cub->sp.spritescreenx;
	if (cub->sp.drawstartx < 0)
		cub->sp.drawstartx = 0;
	cub->sp.drawendx = cub->sp.spritewidth / 2 + cub->sp.spritescreenx;
	if (cub->sp.drawendx >= cub->res_x)
		cub->sp.drawendx = cub->res_x - 1;
}
