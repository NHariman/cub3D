/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 21:06:59 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/14 21:10:24 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>

/*
** in ASCII:
** '0' = 48; walkable space on the map
** '1' = 49; a wall
** '2' = 50; a sprite/item
** ' ' = 32; out of bounds
*/

typedef struct	s_cub
{
	char	*cubpath;
	int		save;
	char	**cubfile;
	int		pos_sprite;
	int		filesize;
	int		x;
	int		y;
	int		res_x;
	int		res_y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sprite;
	long	floor;
	long	top;
	int		**map;
	int		**cpmap;
}				t_cub;

typedef struct	s_gnl
{
	int			bytes_read;
	int			fd;
	char		*line_read;
	int			newline;
}				t_gnl;

int				get_next_line(int fd, char **line);
void			empty_cub(t_cub *cub);
void			free_array(char **arr);
int				map_parser(t_cub *cub);

#endif
