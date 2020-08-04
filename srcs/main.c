/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 21:16:18 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/04 11:49:28 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char			*ft_strlower(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	if (str[ft_strlen(str) - 1] == '/')
	{
		tmp = ft_substr(str, 0, ft_strlen(str) - 1);
		str = tmp;
		free(tmp);
	}
	return (str);
}

static size_t	input_check(int argc, char **argv, t_cub *cub)
{
	if (argc > 3 || argc == 1)
		return (print_error(13));
	else if (ft_strncmp(cub->path + (ft_strlen(cub->path) - 4), ".cub", 4)
	&& ft_strncmp(cub->path + (ft_strlen(cub->path) - 5), ".cub/", 5))
		return (print_error(14));
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 7)))
		return (print_error(15));
	else if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
		cub->save = 1;
	return (1);
}

int				main(int argc, char **argv)
{
	t_cub	*cub;

	cub = ft_calloc(1, sizeof(t_cub));
	cub->path = argv[1] ? ft_strdup(ft_strlower(argv[1])) : NULL;
	if (!input_check(argc, argv, cub))
		return (0);
	if (!file_parser(cub))
		return (0);
	if (!data_parser(cub))
		return (0);
	show_map(cub->map);
	while (1) {;}
	// if (cub->save)
	// 	save_bmp(cub);
	// if (!ray_time(cub))
	// 	return (0);
	return (0);
}

	// int i;

	// i = 0;
	// while (map[i][0] != '\0')
	// {
	// 	ft_printf("%i: %s", i, map[i]);
	// 	i++;
	// }
	// ft_printf("\n");
