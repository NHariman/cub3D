/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/06 21:06:59 by nhariman      #+#    #+#                 */
/*   Updated: 2020/08/19 18:15:44 by nhariman      ########   odam.nl         */
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
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
	int				confirm_press;
}				t_keys;

typedef struct	s_mlx
{
	void			*mlx;
	void			*img;
	void			*win;
	char			*img_addr;
	int				img_bits_per_pixel;
	int				line_length;
	int				endian;
	void			*old_img;
}				t_mlx;

typedef	struct	s_ray
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	deltadistx;
	double	deltadisty;
	int		hit;
}				t_ray;

typedef	struct	s_side
{
	int		stepx;
	int		stepy;
	double	sidedistx;
	double	sidedisty;
	int		side;
}				t_side;

typedef struct	s_set
{
	double			camerax;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
}				t_set;

typedef	struct	s_text
{
	void			*img;
	int				*addr;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

}				t_text;

typedef struct	s_sp_lst
{
	int				x;
	int				y;
}				t_sp_lst;

typedef struct	s_sprite
{
	double			*zbuffer;
	int				*sp_order;
	double			*sp_dist;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				texx;
	int				texy;
	int				colour;
	t_sp_lst		*sprites;
}				t_sprite;

typedef struct	s_cub
{
	t_keys			keys;
	t_set			set;
	t_mlx			mlx;
	t_ray			ray;
	t_side			side;
	t_text			text[5];
	t_sprite		sp;
	char			*textures[5];
	char			*path;
	int				save;
	char			*file;
	char			**filearr;
	int				filesize;
	int				sprites;
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

typedef struct	s_rgb
{
	int				r;
	int				g;
	int				b;
}				t_rgb;

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

/*
** actually gets int value of rgb
*/
int				get_hex(int r, int g, int b);

/*
** sprite handling, finds sprites and puts them in an array
** from furthest sprite to closest based on POV
*/
void			count_sprites(t_cub *cub);
void			floodfill_no(t_cub *cub, int x, int y, int nb);
void			floodfill_so(t_cub *cub, int x, int y, int nb);
void			floodfill_ea(t_cub *cub, int x, int y, int nb);
void			floodfill_we(t_cub *cub, int x, int y, int nb);
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
** raycasting functions
*/
void			start_mlx(t_cub *cub);
int				set_textures(t_cub *cub);
void			get_key_input(t_cub *cub);
void			my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void			ft_colour_background(t_cub *cub);
void			ft_raycasting(t_cub *cub);
void			ft_movement(t_cub *cub);
void			ft_calc_side(t_cub *cub);
void			save_bmp(t_cub *cub);
void			print_struct(t_cub *cub);
void			printsort(t_cub *cub);
void			get_sprites(t_cub *cub);
#endif
