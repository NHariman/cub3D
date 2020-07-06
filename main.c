/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 21:16:18 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/06 22:49:49 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		main(int argc, char **argv)
{
	if (argc > 3 || argc == 1)
	{
		ft_printf("Invalid amount of arguments\n");
		exit(1);
	}
	else if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub\0", 4))
	{
		ft_printf("no .cub file was received.");
		exit(1);
	}
	else if (argc == 3 && (ft_strncmp(argv[2], "--save", 7)))
	{
		ft_printf("This program only takes --save as second argument\n");
		exit(1);
	}
	else
	{
		ft_printf("yay i print smth.\n");
	}
	return (0);
}
