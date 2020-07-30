/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 21:06:59 by nhariman      #+#    #+#                 */
/*   Updated: 2020/07/30 22:49:27 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H

# define CUB_H

# include "mlx/mlx.h"
# include "srcs/libft/libft.h"
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
	char	**filearr;
	int		filesize;
	char	sprite_pos;
	int		sprite_x;
	int		sprite_y;
	int		res_x;
	int		res_y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sprite;
	int		floor;
	int		cling;
	char	**map;
	char	**cpmap;
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

/*
** creates a string and a 2D array of
** of the .cub file.
** Leads to the saving data functions
** found in checker.c and parser.c, folder: PARSER
*/
int				get_next_line(int fd, char **line);
int				file_parser(t_cub *cub);
int				data_parser(t_cub *cub);
char			**create_array(char *str, int len);

/*
** functions that empty and free structs,
** found in clear_structs.c, folder: PARSER
*/
void			empty_check(t_check *check);
//void			empty_cub(t_cub *cub);
int				free_struct(t_cub *cub);

/*
** input sanitation
** found in main.c, folder: SRCS
*/
char			*ft_strlower(char *str);

/*
** functions that save data into struct
** found in savers.c, folder: SRCS
*/
char			*save_path(char *str, int i, t_check *check, t_cub *cub);
int				save_texture(char *str, t_cub *cub, t_check *check);
int				save_res(const char *str, t_cub *cub, t_check *check);
int				save_colours(const char *str, t_cub *cub, t_check *check);
int				save_rgb(const char *str, t_cub *cub);

/*
** functions that check if input is valid
** found in valid_input.c, folder VALID_INPUT
*/
int				find_res_y(const char *str);
int				valid_res_input(const char *str);
int				valid_rgb_input(const char *str);
int				valid_map(t_cub *cub);
int				complete_input_data(t_check *check);

/*
** functions that check if the map received is valid
** found in floodfill.c, folder VALID_INPUT
*/
void			floodfill_map(char **map, int *success, int x, int y);
/*
** error messages, found in error_messages.c, map_errors.c
** folder ERRORS/
*/
int				print_error(int num);
int				check_noise(char **map);
void			show_map(char **map);
int				show_file_error(char **file, int error);

#endif
