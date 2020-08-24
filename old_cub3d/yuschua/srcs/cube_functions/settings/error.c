/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/18 14:22:42 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/15 14:06:52 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void		error_check_one(t_struct_m *main)
{
	if (main->place.error == 2)
		ft_putstr("[2]unknown input in map, or clutter fix your map\n");
	else if (main->place.error == 3)
		ft_putstr("[3]unacceptable command in line R, fix your map\n");
	else if (main->place.error == 4)
		ft_putstr("[4]unacceptable command in line NO, fix your map\n");
	else if (main->place.error == 5)
		ft_putstr("[5]unacceptable command in line EA, fix your map\n");
	else if (main->place.error == 6)
		ft_putstr("[6]unacceptable command in line S, fix your map\n");
	else if (main->place.error == 7)
		ft_putstr("[7]unacceptable command in line SO, fix your map\n");
	else if (main->place.error == 8)
		ft_putstr("[8]unacceptable command in line WE, fix your map\n");
	else if (main->place.error == 9)
		ft_putstr("[9]unacceptable command in line F, fix your map\n");
	else if (main->place.error == 10)
		ft_putstr("[10]unacceptable command in line C, fix your map\n");
	else if (main->place.error == 11)
		ft_putstr("[11]INCORRECT input of position input, fix your map\n");
	else if (main->place.error == 48)
		ft_putstr("[48]double input after input, wrong input, fix your map\n");
	else if (main->place.error == 12)
		ft_putstr("[12]wrong input in map, can't read map, fix your map\n");
}

static void		error_check_two(t_struct_m *main)
{
	if (main->place.error == 13)
		ft_putstr("[13]problem in malloc, try again\n");
	else if (main->place.error == 14)
		ft_putstr("[14]problem in functions, line is NULL\n");
	else if (main->place.error == 15)
		ft_putstr("[15]map incorrect, not surrounded by 1, top/bottom wrong\n");
	else if (main->place.error == 16)
		ft_putstr("[16]map incorrect, not surroudned by 1, left side wrong\n");
	else if (main->place.error == 17)
		ft_putstr("[17]map incorrect, not surroudned by 1, right side wrong\n");
	else if (main->place.error == 18)
		ft_putstr("[18]map incorrect\n");
	else if (main->place.error == 19)
		ft_putstr("[19]link in map file incorrect at NO, fd is -1\n");
	else if (main->place.error == 20)
		ft_putstr("[20]link in map file incorrect at SO, fd is -1\n");
	else if (main->place.error == 21)
		ft_putstr("[21]link in map file incorrect at WE, fd is -1\n");
	else if (main->place.error == 22)
		ft_putstr("[22]link in map file incorrect at EA, fd is -1");
	else if (main->place.error == 23)
		ft_putstr("[23]link in map file incorrect at S, fd is -1");
	else if (main->place.error == 24)
		ft_putstr("[24]error in fd, read map, fd < 0");
}

static void		error_check_three(t_struct_m *main)
{
	if (main->place.error == 25)
		ft_putstr("[25]not all info was given or map is in wrong location");
	else if (main->place.error == 26)
		ft_putstr("[26]double R");
	else if (main->place.error == 27)
		ft_putstr("[27]first set numbers in R is incorrect");
	else if (main->place.error == 28)
		ft_putstr("[28]too many inputs in R, fix R");
	else if (main->place.error == 29)
		ft_putstr("[29]double F");
	else if (main->place.error == 30)
		ft_putstr("[30]too many inputs in F, fix F");
	else if (main->place.error == 31)
		ft_putstr("[31]first set numbers in F is incorrect");
	else if (main->place.error == 32)
		ft_putstr("[32]not enough inputs in R");
	else if (main->place.error == 33)
		ft_putstr("[33]not enough inputs in C");
	else if (main->place.error == 34)
		ft_putstr("[34]too many inputs in F, fix F");
	else if (main->place.error == 35)
		ft_putstr("[35]double C");
	else if (main->place.error == 36)
		ft_putstr("[36]double SO");
}

static void		error_check_four(t_struct_m *main)
{
	if (main->place.error == 37)
		ft_putstr("[37]SO info after link, remove this info");
	else if (main->place.error == 38)
		ft_putstr("[38]double WE");
	else if (main->place.error == 39)
		ft_putstr("[39]WE info after link, remove this info");
	else if (main->place.error == 40)
		ft_putstr("[40]double NO");
	else if (main->place.error == 41)
		ft_putstr("[41]NO info after link, remove this info");
	else if (main->place.error == 42)
		ft_putstr("[42]double EA");
	else if (main->place.error == 43)
		ft_putstr("[43]EA info after link, remove this info");
	else if (main->place.error == 44)
		ft_putstr("[44]double S");
	else if (main->place.error == 45)
		ft_putstr("[45]S info after link, remove this info");
	else if (main->place.error == 46)
		ft_putstr("[46]malloc error in check_fill");
	else if (main->place.error == 47)
		ft_putstr("[47]empty horiontal line in map");
	else if (main->place.error == 49)
		ft_putstr("[49]no map inputs");
}

void			ft_error(t_struct_m *main)
{
	if (main->place.error_n != 1)
	{
		ft_putstr("Error\n");
		main->place.error_n = 0;
	}
	if (main->place.error == 1)
	{
		ft_putstr("[1]you got double lines, fix your map\n");
		main->place.check_double = 0;
		main->place.error = 0;
	}
	error_check_one(main);
	error_check_two(main);
	error_check_three(main);
	error_check_four(main);
	if (main->place.error == 50)
		ft_putstr("[50] clutter in the map file");
	else if (main->place.error == 51)
		ft_putstr("[51] c colour negative or higher than 254");
	else if (main->place.error == 52)
		ft_putstr("[52] f colour negative or higher than 254");
	else if (main->place.error == 53)
		ft_putstr("[53] width or hight in the negative");
	main->place.error = 0;
}
