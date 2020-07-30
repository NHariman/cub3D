/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_messages.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/24 20:07:03 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/30 22:51:02 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

static int		print_even_more_errors(int num)
{
	if (num == 20)
		ft_printf("Oh lord\n");
	return (0);
}

static int		print_more_errors(int num)
{
	if (num > 19)
		return (print_even_more_errors(num));
	else if (num == 10)
		ft_printf("Error\n%i: Floodfill failed.\n", num);
	else if (num == 11)
		ft_printf("Error\n%i: Open map.\n", num);
	else if (num == 12)
		ft_printf("Error\n%i: Invalid character detected in map\n", num);
	else if (num == 13)
		ft_printf("Error\n%i: Invalid amount of arguments\n", num);
	else if (num == 14)
		ft_printf("Error\n%i: No .cub file was received.\n", num);
	else if (num == 15)
	{
		ft_printf(
		"Error\n%i: Only takes --save as second argument\n", num);
	}
	else if (num == 16)
		ft_printf("Error\n%i: Multiple spawn positions detected\n", num);
	else if (num == 17)
		ft_printf("Error\n%i: Unable to read file to array.\n", num);
	else if (num == 18)
		ft_printf("Error\n%i: Unable to open file.\n", num);
	return (0);
}

int				print_error(int num)
{
	if (num > 9)
		return (print_more_errors(num));
	else if (num == 1)
		ft_printf("Error\n%i: invalid or double texture input detected\n", num);
	else if (num == 2)
	{
		ft_printf("Error\n%i: Double R values detected\n", num);
		return (-1);
	}
	else if (num == 3)
		ft_printf("Error\n%i: Invalid res input\n", num);
	else if (num == 4)
		ft_printf("Error\n%i: Invalid rgb values detected\n", num);
	else if (num == 5)
		ft_printf("Error\n%i: Invalid or double rgb values detected\n", num);
	else if (num == 6)
		ft_printf("Error\n%i: Missing Elements.\n", num);
	else if (num == 7)
		ft_printf("Error\n%i: Invalid Map.\n", num);
	else if (num == 8)
		ft_printf("Error\n%i: Map not very last element in file.\n", num);
	else if (num == 9)
		ft_printf("Error\n%i: No spawnpoint in map.\n", num);
	return (0);
}

void			show_map(char **map)
{
	int i;

	i = 0;
	while (map[i][0] != '\0')
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n");
}

int				show_file_error(char **file, int error)
{
	int j;

	j = 0;
	while (j < error && file[j][0] != '\0')
	{
		ft_printf("line %i>> %s", j + 1, file[j]);
		j++;
	}
	ft_printf(">>>>>>ERROR IS HERE<<<<<<\n");
	ft_printf("line %i>> %s", j + 1, file[j]);
	ft_printf("\n");
	return (0);
}
