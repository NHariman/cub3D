/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_value.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 13:26:52 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/11 10:47:28 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void		set_value_one(t_struct_m *main)
{
	main->place.s_width = -1;
	main->place.s_height = -1;
	main->place.dir = -1;
	main->place.fcol1 = -1;
	main->place.fcol2 = -1;
	main->place.fcol3 = -1;
	main->place.ccol1 = -1;
	main->place.ccol2 = -1;
	main->place.ccol3 = -1;
	main->place.error = -1;
	main->place.error_c = 0;
	main->place.error_n = -1;
	main->place.check_double = 0;
	main->place.x = 100;
	main->place.y = 100;
	main->place.w = 100;
	main->place.h = 100;
	main->doublle.d_r = 0;
	main->doublle.d_no = 0;
	main->doublle.d_so = 0;
	main->doublle.d_we = 0;
	main->doublle.d_ea = 0;
	main->doublle.d_s = 0;
}

void			set_value(t_struct_m *main)
{
	set_value_one(main);
	main->doublle.d_f = 0;
	main->doublle.d_c = 0;
	main->place.no = NULL;
	main->place.so = NULL;
	main->place.ea = NULL;
	main->place.s = NULL;
	main->place.we = NULL;
	main->place.mapx = 0;
	main->place.mapy = 0;
	main->place.mapp = 0;
	main->place.mape = 0;
	main->place.mapc = -1;
	main->place.cubemap = NULL;
	main->cubecopytwo = NULL;
	main->keys.w = 0;
	main->keys.s = 0;
	main->keys.a = 0;
	main->keys.d = 0;
	main->keys.up = 0;
	main->keys.dow = 0;
	main->keys.lef = 0;
	main->keys.rig = 0;
	main->ray.look = 0;
}
