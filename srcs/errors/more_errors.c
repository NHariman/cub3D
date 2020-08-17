/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_errors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 22:05:17 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/06 16:07:10 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int			omg_so_many_errors(int num)
{
	if (num > 28)
		return (0);
	else if (num == 19)
		ft_printf("Error\n%i: Floodfill failed.\n", num);
	return (0);
}
