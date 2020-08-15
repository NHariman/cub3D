/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 21:06:59 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/15 21:41:16 by nhariman      ########   odam.nl         */
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

# define NO 0
# define SO 1
# define EA 2
# define WE 3
# define SP 4

# define PNG 15
# define XPM 16

# define W 13
# define A 0
# define S 1
# define D 2

# define ESC 53

# define LEFT 123
# define RIGHT 124

typedef	struct	s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}				t_keys;

typedef struct	s_data {
	void		*texture;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef	struct	s_mlx
{
	void			*mlx;
	void			*mlx_win;
	t_data			img;
}				t_mlx;

typedef	struct	s_rgb
{
	int				r;
	int				g;
	int				b;
}				t_rgb;

typedef	struct	s_texture
{
	char			*path;
}				t_texture;

typedef	struct	s_ray
{
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
}				t_ray;

typedef struct	s_draw
{
	int				lineheight;
	int				start;
	int				end;
}				t_draw;

typedef struct	s_wall
{
	double			wallx;
	int				texx;
	int				texy;
}				t_wall;

typedef struct	s_cub
{
	t_texture		textures[5];
	char			*path;
	int				save;
	char			*file;
	char			**filearr;
	int				filesize;
	char			spawn_pos;
	int				spawn_x;
	int				spawn_y;
	int				res_x;
	int				res_y;
	int				floor;
	int				cling;
	char			**map;
	char			**cpmap;
}				t_cub;

typedef	struct	s_camera
{
	t_mlx			mlx;
	t_data			tex[5];
	t_ray			ray;
	t_draw			draw;
	t_wall			wall;
	t_keys			keys;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			raydirx;
	double			raydiry;
	double			planex;
	double			planey;
	double			time;
	double			prev_time;
	double			frametime;
	double			camerax;
	double			step;
	double			texpos;
	double			movespeed;
	double			rotspeed;
	double			olddirx;
	double			oldplanex;
	t_cub			*cub;
}				t_camera;

typedef	struct	s_check
{
	int				north;
	int				south;
	int				east;
	int				west;
	int				sprite;
	int				floor;
	int				ceiling;
	int				res;
}				t_check;

typedef struct	s_gnl
{
	int				bytes_read;
	int				fd;
	char			*line_read;
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
** found in clear_structs.c, folder: ERRORS
*/
void			empty_check(t_check *check);
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
char			*save_path(char *str, int i, t_check *check);
int				save_texture(char *str, t_cub *cub, t_check *check);
int				save_res(const char *str, t_cub *cub, t_check *check);
int				save_colours(const char *str, t_cub *cub, t_check *check);
int				save_rgb(const char *str, t_rgb *rgb);

/*
** functions that check if input is valid
** found in valid_input.c, folder VALID_INPUT
*/
int				find_res_y(const char *str);
int				valid_res_input(const char *str);
int				valid_rgb_input(const char *str);
int				valid_rgb_values(t_rgb *rgb);
int				valid_map(t_cub *cub);
int				complete_input_data(t_check *check);

/*
** functions that check if the map received is valid
** found in floodfill.c, folder VALID_INPUT
*/
void			floodfill_map(char **map, int *success, int x, int y);
int				get_hex(int r, int g, int b);
/*
** error messages, found in error_messages.c, map_errors.c
** folder ERRORS/
*/
int				print_error(int num);
int				omg_so_many_errors(int num);
int				check_noise(char **map);
void			show_map(char **map);
int				show_file_error(char **file, int error);

/*
** raycasting time baybeeeeee
** found in setup_raycasting.c
** folder: RAYCASTING/
*/
int				ray_time(t_cub *cub);

/*
** these functions calculate various stuff for rays
** found in: calc.c and raycasting.c
** folder: RAYCASTING/
*/
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void        	ft_background(t_camera *cam);
void			set_window_size(t_camera *cam);
int				mlx_exit(void *mlx, void *mlx_win, int error);
void			set_img(t_camera *cam);
void			setup_camray(t_camera *cam);
void			calc_camray(t_camera *cam);
void			calc_step_and_sidedist(t_camera *cam);
void			calc_dda(t_camera *cam);
void			calc_camwalldist(t_camera *cam);
void			calc_line(t_camera *cam, int y);
void			calc_textures(t_camera *cam, int x);

/*
** get and calculate textures.
** found in textures.c
** folder: RAYCASTING/
*/
int				get_textures(t_camera *cam);

/*
** get keyboard input, found in key_input.c and movement.c
** folder: RAYCASSTING/
*/
int				exit_program(t_camera *cam);
void			get_key_input(t_camera *cam);
void			move_vertical(t_camera *cam, int type);
void			move_horizontal(t_camera *cam, int type);
void			rotate(t_camera *cam, int type);
void			ft_movement(t_camera *cam);

void        	giant_fucking_function(t_camera *cam);
#endif
