/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_structs.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 17:59:03 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/17 22:44:39 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		empty_check(t_check *check)
{
	check->res = 0;
	check->north = 0;
	check->south = 0;
	check->east = 0;
	check->west = 0;
	check->sprite = 0;
	check->floor = 0;
	check->ceiling = 0;
}
