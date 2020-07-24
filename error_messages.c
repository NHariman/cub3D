/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_messages.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/24 20:07:03 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/24 22:22:41 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		print_error(int num)
{
	if (num > 9)
		return (print_more_errors(num));
	else if (num == 1)
		ft_printf("Error\ninvalid or double texture input detected\n");
	else if (num == 2)
	{
		ft_printf("Error\nDouble R values detected\n");
		return (-1);
	}
	else if (num == 3)
		ft_printf("Error\nInvalid res input\n");
	else if (num == 4)
		ft_printf("Error\nInvalid rgb values detected\n");
	else if (num == 5)
		ft_printf("Error\nInvalid or double rgb values detected\n");
	else if (num == 6)
		ft_printf("Error\nMissing Elements.\n");
	else if (num == 7)
		ft_printf("Error\nInvalid Map.\n");
	else if (num == 8)
		ft_printf("Error\nMap not very last element in file.\n");
	else if (num == 9)
		ft_printf("Error\nNo spawnpoint in map.\n");
	return (0);
}

int		print_more_errors(int num)
{
	if (num > 19)
		return (print_even_more_errors(num));
	else if (num == 10)
		ft_printf("Error\nFloodfill failed.\n");
	else if (num == 11)
		ft_printf("Error\nOpen map.\n");
	else if (num == 3)
		ft_printf("Error\nInvalid res input\n");
	else if (num == 4)
		ft_printf("Error\nInvalid rgb values detected\n");
	else if (num == 5)
		ft_printf("Error\nInvalid or double rgb values detected\n");
	else if (num == 6)
		ft_printf("Error\nMissing Elements.\n");
	else if (num == 7)
		ft_printf("Error\nInvalid Map.\n");
	else if (num == 8)
		ft_printf("Error\nMap not very last element in file.\n");
	else if (num == 9)
		ft_printf("Error\nNo spawnpoint in map.\n");
	return (0);
}

int		print_even_more_errors(int num)
{
	if (num == 20)
		ft_printf("Oh lord\n");
	return (0);
}
