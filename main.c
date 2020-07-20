/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 21:16:18 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/20 22:35:05 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char		*ft_strlower(char *str)
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
	{
		ft_printf("Invalid amount of arguments\n");
		return (0);
	}
	else if (ft_strncmp(cub->path + (ft_strlen(cub->path) - 4), ".cub", 4)
	&& ft_strncmp(cub->path + (ft_strlen(cub->path) - 5), ".cub/", 5))
	{
		ft_printf("no .cub file was received.\n");
		return (0);
	}
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 7)))
	{
		ft_printf("This program only takes --save as second argument\n");
		return (0);
	}
	else if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
	{
		cub->save = 1;
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_cub	cub;
	int		i;

	i = 0;
	empty_cub(&cub);
	cub.path = argv[1] ? ft_strdup(ft_strlower(argv[1])) : NULL;
	if (input_check(argc, argv, &cub))
	{
		map_parser(&cub);
		if (file_checker(&cub) == -1)
		{
			ft_printf("NO: %s\n", cub.no);
			ft_printf("SO: %s\n", cub.so);
			ft_printf("WE: %s\n", cub.we);
			ft_printf("EA: %s\n", cub.ea);
			ft_printf("S : %s\n", cub.sprite);
			ft_printf("res_x: %i\n", cub.res_x);
			ft_printf("res_y: %i\n", cub.res_y);
			ft_printf("r: %i\n", cub.r);
			ft_printf("g: %i\n", cub.g);
			ft_printf("b: %i\n", cub.b);
			while (cub.map[i])
			{
				ft_printf("%s\n", cub.map[i]);
				i++;
			}
			// free_struct(&cub);
			// ft_printf("NO: %s\n", cub.no);
			// ft_printf("SO: %s\n", cub.so);
			// ft_printf("WE: %s\n", cub.we);
			// ft_printf("EA: %s\n", cub.ea);
			// ft_printf("S : %s\n", cub.sprite);
			// ft_printf("res_x: %i\n", cub.res_x);
			// ft_printf("res_y: %i\n", cub.res_y);
			// ft_printf("r: %i\n", cub.r);
			// ft_printf("g: %i\n", cub.g);
			// ft_printf("b: %i\n", cub.b);
			ft_printf("something went wrong\n");
			while (1) {;}
			return (0);
		}
	}
	if (cub.map)
	{
		while (cub.map[i])
		{
			ft_printf("%s\n", cub.map[i]);
			i++;
		}
		ft_printf("NO: %s\n", cub.no);
		ft_printf("SO: %s\n", cub.so);
		ft_printf("WE: %s\n", cub.we);
		ft_printf("EA: %s\n", cub.ea);
		ft_printf("S : %s\n", cub.sprite);
		ft_printf("res_x: %i\n", cub.res_x);
		ft_printf("res_y: %i\n", cub.res_y);
		ft_printf("r: %i\n", cub.r);
		ft_printf("g: %i\n", cub.g);
		ft_printf("b: %i\n", cub.b);
		while (1) {;}
	}
	else
	{
		ft_printf("lol that didn't work\n");
		while (1) {;}
	}
	return (0);
}
