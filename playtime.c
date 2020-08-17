/*
** Playing with mlx. and maths.
 */
#include <stdlib.h>
#include <math.h>
#include "srcs/mlx/mlx.h"
#include <stdio.h>

typedef struct	s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}				t_data;

typedef struct  s_vars {
        void    *mlx;
        void    *win;
}               t_vars;

/* an image is presented in realtime in a window, changing the same image will cause screen terror when writing to it, therefore, creating two or more images to hold your frames temporarily is a must to avoid writing to the current image. */
void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int             keys(int keycode, t_vars *vars)
{
	printf("print keycode: %i\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}

int		warn(void)
{
	printf("you are clicking around\n");
	return (0);
}

int		release(void)
{
	printf("you have released a button\n");
	return (0);
}

int		move(void)
{
	printf("wheeeeeeee\n");
	return (0);
}

int		delete(t_vars *vars)
{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
}

void	get_keyinput(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, keys, vars);
	mlx_hook(vars->win, 4, 1L << 19, warn, vars);
	mlx_hook(vars->win, 5, 1L << 19, release, vars);
	//mlx_hook(vars->win, 6, 1L << 19, move, vars);
	mlx_hook(vars->win, 17, 0L, delete, vars);
}

int		main(void)
{
	int		i;
	int		j;
	int		tmp;
	t_vars	vars;
	t_data  img;

	i = 0;
	j = 0;
	tmp = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (j < 25)
	{
		while (i < 25)
		{
			my_mlx_pixel_put(&img, 0 + j, 0 + i, 14443520);
			i++;
		}
		j++;
		i = 0;
	}
	// 	while (j < tmp + 25)
	// {
	// 	while (i < 250)
	// 	{
	// 		my_mlx_pixel_put(&img, 0 + j, 0 + i, 0x6033FF);
	// 		i++;
	// 	}
	// 	j++;
	// 	i = 0;
	// }
	// i = 0;
	// while (i < img.endian)
	// {
	// 	my_mlx_pixel_put(&img, 0, 2 + i, 0x6033FF);
	// 	i++;
	// }
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	get_keyinput(&vars);
	mlx_loop(vars.mlx);
}
