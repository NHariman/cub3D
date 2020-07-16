/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 21:16:18 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/16 22:13:09 by nhariman      ########   odam.nl         */
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

void			free_map(char **arr, int len)
{
	while (len > 0)
	{
		free(arr[len]);
		len--;
	}
	free(arr);
	arr = NULL;
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
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->sprite = NULL;
	cub->floor = 0;
	cub->cling = 0;
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
			ft_printf("something went wrong\n");
			return (0);
		}
	}
	if (cub.map)
	{
		// while (cub.map[i])
		// {
		// 	ft_printf("%s\n", cub.map[i]);
		// 	i++;
		// }
		ft_printf("NO: %s\n", cub.no);
		ft_printf("SO: %s\n", cub.so);
		ft_printf("WE: %s\n", cub.we);
		ft_printf("EA: %s\n", cub.ea);
	}
	else
	{
		ft_printf("lol that didn't work\n");
	}
	return (0);
}
