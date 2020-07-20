/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 21:06:59 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/20 22:33:44 by nhariman      ########   odam.nl         */
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
	char	*path;
	int		save;
	char	*file;
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
	long	cling;
	char	**map;
	int		*cpmap;
	int		r;
	int		g;
	int		b;
	int		hex;

}				t_cub;

typedef	struct	s_check
{
	int		north;
	int		south;
	int		east;
	int		west;
	int		sprite;
	int		floor;
	int		ceiling;
	int		res;
}				t_check;

typedef struct	s_gnl
{
	int			bytes_read;
	int			fd;
	char		*line_read;
}				t_gnl;

int				get_next_line(int fd, char **line);
void			empty_cub(t_cub *cub);
void			empty_check(t_check *check);
int				free_array(t_cub *cub);
void			free_struct(t_cub *cub);
int				map_parser(t_cub *cub);
int				file_checker(t_cub *cub);
char			*save_path(char *str, int i, t_check *check);
int				save_texture(char *str, t_cub *cub, t_check *check);
int				save_res(char *str, t_cub *cub, t_check *check);
int				save_colours(char *str, t_cub *cub, t_check *check);
int				save_rgb(char *str, t_cub *cub);
int				find_res_y(char *str);
int				valid_res_input(char *str);
int				valid_rgb_input(char *str);


#endif
