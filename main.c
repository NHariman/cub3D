/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 21:16:18 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/08 00:09:08 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		main(int argc, char **argv)
{
	char	*cubfile;

	cubfile = argv[1] ? ft_strdup(argv[1]) : NULL;
	if (argc > 3 || argc == 1)
	{
		ft_printf("Invalid amount of arguments\n");
	}
	else if (!ft_strnstr(cubfile, ".cub", ft_strlen(cubfile)))
	{
		ft_printf("no .cub file was received.");
	}
	else if (argc == 3 && (ft_strncmp(argv[2], "--save", 7)))
	{
		ft_printf("This program only takes --save as second argument\n");
	}
	else
	{
		ft_printf("yay i print smth.\n");
	}
	free(cubfile);
	return (0);
}
