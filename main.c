/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 21:16:18 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/15 22:37:29 by nhariman      ########   odam.nl         */
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

void			empty_cub(t_cub *cub)
{
	cub->path = NULL;
	cub->file = NULL;
	cub->save = 0;
	cub->pos_sprite = 0;
	cub->filesize = 0;
	cub->x = 0;
	cub->y = 0;
	cub->res_x = 0;
	cub->res_y = 0;
	cub->no = 0;
	cub->so = 0;
	cub->we = 0;
	cub->ea = 0;
	cub->sprite = 0;
	cub->floor = 0;
	cub->top = 0;
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
		ft_printf("yay i print smth.\ncub->save: %i\n", cub.save);
		map_parser(&cub);
	}
	if (cub.map)
	{
		while (cub.map[i])
		{
			ft_printf("%s\n", cub.map[i]);
			i++;
		}
	}
	else
	{
		ft_printf("lol that didn't work\n");
	}
	return (0);
}
