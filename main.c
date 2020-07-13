/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 21:16:18 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/10 20:46:37 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char		*ft_strlower(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

void			empty_cub(t_cub *cub)
{
	cub->cubpath = NULL;
	cub->save = 0;
	cub->cubfile = NULL;
	cub->filesize = 0;
	cub->x = 0;
	cub->y = 0;
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
	else if (ft_strncmp(cub->cubpath + (ft_strlen(cub->cubpath) - 4), ".cub", 4)
	&& ft_strncmp(cub->cubpath + (ft_strlen(cub->cubpath) - 5), ".cub/", 5))
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
	cub.cubpath = argv[1] ? ft_strdup(ft_strlower(argv[1])) : NULL;
	if (input_check(argc, argv, &cub))
	{	
		ft_printf("yay i print smth.\ncub->save: %i\n", cub.save);
		map_parser(&cub);
	}
	if (cub.cubfile)
	{
		while (cub.cubfile[i] != '\0')
		{
			ft_printf("%s\n", cub.cubfile[i]);
			i++;
		}
	}
	else
	{
		ft_printf("lol that didn't work\n");
	}
	
//	free_array(cub->cubfile);
	return (0);
}
