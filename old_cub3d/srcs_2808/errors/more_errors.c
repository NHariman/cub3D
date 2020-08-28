/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_errors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 22:05:17 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/26 18:45:06 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int			ft_fd_errors(int num, int type)
{
	if (type == NO)
		ft_printf("Error\n%i: Unable to load NORTH (NO) texture.\n", num);
	if (type == SO)
		ft_printf("Error\n%i: Unable to load SOUTH (SO) texture.\n", num);
	if (type == EA)
		ft_printf("Error\n%i: Unable to load EAST (EA) texture.\n", num);
	if (type == WE)
		ft_printf("Error\n%i: Unable to load WEST (WE) texture.\n", num);
	if (type == SP)
		ft_printf("Error\n%i: Unable to load SPRITE (SP) texture.\n", num);
	ft_print_error(num);
	return (0);
}

int			ft_you_can_never_print_too_many_errors(int num)
{
	if (num == 28)
		ft_printf("Error\n%i: Invalid type identifier detected.\n", num);
	else if (num == 29)
		ft_printf("Error\n%i: Overflow protection, map too large.\n", num);
	else if (num == 30)
		ft_printf("Error\n%i: invalid spawnpoint.\n", num);
	else if (num == 31)
		ft_printf("Error\n%i: res_x is 0.\n", num);
	else if (num == 32)
		ft_printf("Error\n%i: res_y is 0.\n", num);
	return (0);
}
