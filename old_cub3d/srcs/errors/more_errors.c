/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_errors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 22:05:17 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/22 00:21:05 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int			fd_errors(int num, int type)
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
	print_error(num);
	return (0);
}
