/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/23 18:37:30 by ybakker       #+#    #+#                 */
/*   Updated: 2020/07/29 21:24:50 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define ESC 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define UP_KEY 126
# define DOW_KEY 125
# define LEF_KEY 123
# define RIG_KEY 124

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
}				t_data;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct	s_place {
	int			x;
	int			y;
	int			w;
	int			h;
	int			col;
	int			s_width;
	int			s_height;
	int			dir;
	char		*no;
	char		*so;
	char		*ea;
	char		*s;
	char		*we;
	int			i;
	int			fcol1;
	int			fcol2;
	int			fcol3;
	int			ccol1;
	int			ccol2;
	int			ccol3;
	int			error;
	int			error_c;
	int			error_n;
	int			check_double;
	char		**cubemap;
	int			mapx;
	int			mapy;
	int			mapp;
	int			mape;
	int			mapc;

	int			crouch;
}				t_place;

typedef struct	s_doublle {
	int			d_r;
	int			d_no;
	int			d_so;
	int			d_ea;
	int			d_s;
	int			d_we;

	int			d_f;
	int			d_c;
}				t_doublle;

typedef struct	s_ray {

	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			h;
	int			x;
	int			yy;
	int			yyy;
	int			xx;
	int			eh;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			texnum;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
	int			look;
}				t_ray;

typedef struct	s_texture {
	void		*texture;
	int			*texture_adress;
	int			line_lenght;
	int			bits_per_pixel;
	int			texture_width;
	int			texture_height;
	int			endian;

}				t_texture;

typedef struct	s_sprite {

	double		spritex;
	double		spritey;
	double		invdet;

	double		transformx;
	double		transformy;

	int			spritescreenx;
	int			vmovescreen;

	int			spriteheight;

	int			drawstarty;
	int			drawendy;
	int			drawstartx;
	int			drawendx;

	int			spritewidth;
	int			stripe;

	double		first;
	int			second;

	int			begin;
	int			end;
}				t_sprite;

typedef struct	s_sprites {

	double		x;
	double		y;
	int			texy;
	int			texx;

}				t_sprites;

typedef	struct	s_keys {

	int			w;
	int			s;
	int			a;
	int			d;
	int			up;
	int			dow;
	int			lef;
	int			rig;
	float		raydirx0;
	float		raydiry0;
	float		raydirx1;
	float		raydiry1;
	int			p;
	float		posz;
	float		rowdistance;
	float		floorstepx;
	float		floorstepy;
	float		floorx;
	float		floory;
	int			cellx;
	int			celly;
	int			tx;
	int			ty;
	int			colour;

}				t_keys;

typedef struct	s_struct_m {
	t_data		img;
	t_vars		vars;
	t_place		place;
	t_doublle	doublle;
	t_ray		ray;
	t_texture	texture[5];
	t_sprite	sprite;
	t_sprites	*sprites;
	t_keys		keys;

	int			numsprites;
	double		*zbuffer;
	int			*spriteorder;
	double		*spritedistance;
	char		**cubecopy;
	char		**cubecopytwo;
	int			count;
	char		*map;
	int			i;
	int			ii;
	int			cealing;
	int			cealingw;
}				t_struct_m;

void			my_mlx_pixel_put(t_struct_m *main, int x, int y, int color);
void			read_map(t_struct_m *main);
int				wasd(int keycode, t_struct_m *main);

void			cube(t_struct_m *main);
int				background(t_struct_m *main);
int				ft_read_map(t_struct_m *main);
int				ft_read_map_where(t_struct_m *main, char *map);
int				ft_get_info(t_struct_m *main, char *map);
int				ft_strnstr_map(const char *haystack, const char *needle,
size_t len);
int				ft_check_for_map(char *map);

int				ft_read_ea(t_struct_m *main, char *map);
int				ft_read_c(t_struct_m *main, char *map);
int				ft_read_f(t_struct_m *main, char *map);
int				ft_read_no(t_struct_m *main, char *map);
int				ft_read_r(t_struct_m *main, char *map);
int				ft_read_s(t_struct_m *main, char *map);
int				ft_read_so(t_struct_m *main, char *map);
int				ft_read_we(t_struct_m *main, char *map);
void			ft_read_cubecube(t_struct_m *main, char *map);
void			check_map_symbol(t_struct_m *main, char *map);
int				ft_clutter(t_struct_m *main, char *map);

void			set_value_texture_no(t_struct_m *main, int fd);
void			set_value_texture_so(t_struct_m *main, int fd);
void			set_value_texture_we(t_struct_m *main, int fd);
void			set_value_texture_s(t_struct_m *main, int fd);
void			set_value_texture_ea(t_struct_m *main, int fd);

void			wasd_s_d(t_struct_m *main, double movesp, double rotsp);
void			wasd_a(t_struct_m *main, double rotsp);
void			wasd_r_l(t_struct_m *main, double movesp);
void			readmap(t_struct_m *main);
void			read_string(t_struct_m *main, char *map);
void			ft_check(t_struct_m *main, char *map);

int				check_r(t_struct_m *main, char *map, int i);
int				check_no(t_struct_m *main, char *map, int i);
int				check_so(t_struct_m *main, char *map, int i);
int				check_s(t_struct_m *main, char *map, int i);
int				check_we(t_struct_m *main, char *map, int i);
int				check_ea(t_struct_m *main, char *map, int i);
int				check_f(t_struct_m *main, char *map, int i);
int				check_c(t_struct_m *main, char *map, int i);
void			set_value(t_struct_m *main);

void			ft_error(t_struct_m *main);

int				ft_size_store_map(t_struct_m *main);
int				get_size_map(t_struct_m *main, char *map);
int				ft_map_line(t_struct_m *main, char *map);
void			set_location(t_struct_m *main);
void			spritesnumb(t_struct_m *main);
void			get_spritenumber(t_struct_m *main, int y, int x);
int				check_fill(t_struct_m *main);
void			flood_fill(int x, int y, t_struct_m *main);
int				if_empty(int x, int y, t_struct_m *main);
int				ft_check_empty(int x, int y, t_struct_m *main);
int				ft_atoi_cube(char *str, t_struct_m *main, int i);
int				ft_isalnummer(int i, char *str);
int				ft_strlenght(char *s);
int				ft_strleng(char *str, int i);
char			*ft_cp_string(char *str, int i, int lenght);
void			ft_putchar(char *str);
void			ft_putstr(char *str);
void			space_cubemap(t_struct_m *main);

int				render_next_frame(t_struct_m *main);
int				ft_raycasting(t_struct_m *main);
int				wasd_2(t_struct_m *main);
int				ft_push_key(int keycode, t_struct_m *main);
int				ft_release_key(int keycode, t_struct_m *main);
int				ft_close(void);
void			verline(int x, int drawstart, int drawend,
				int col, t_struct_m *main);
int				create_trgb(int r, int g, int b);

void			printmap(t_struct_m *main);
int				render_next_frame_structure(t_struct_m *main);
void			verline_texture(int x, t_struct_m *main);
void			set_value_texture(t_struct_m *main);
void			verline_structure(t_struct_m *main);

void			render_next_frame_sprites(t_struct_m *main);
void			swap(t_struct_m *main, int j);
void			bubble_sort(t_struct_m *main);
void			ft_bmp(t_struct_m *main);
void			start_bmp(t_struct_m *main);
void			ft_end_function(t_struct_m *main);
int				ft_check_empty_line(t_struct_m *main, int x, int y);
int				ft_map_line_get_x(char *map);
void			ft_fill_empty_string(t_struct_m *main, int y);
int				ft_strncmp_map(const char *haystack, const char *needle);
int				error_r(t_struct_m *main, int y);
int				ft_error_map(t_struct_m *main, int fd);

int				ft_info_parser_check(t_struct_m *main);

void			check_screen(t_struct_m *main);
void			check_value(t_struct_m *main);
void			read_map_bmp(t_struct_m *main);
void			check_screen_bmp(t_struct_m *main);
void			read_map_bmp(t_struct_m *main);
int				ft_strnstr_cub(const char *haystack, const char *needle);
int				check_valid_x(t_struct_m *main);
void			render_next_frame_sprites_colourr(t_struct_m *main, int y,
int d, int colour);

#endif
