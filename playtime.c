/*
** Playing with mlx. and maths.
 */

#include <math.h>
#include "mlx/mlx.h"

typedef struct	s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}				t_data;

/* an image is presented in realtime in a window, changing the same image will cause screen terror when writing to it, therefore, creating two or more images to hold your frames temporarily is a must to avoid writing to the current image. */
void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		main(void)
{
	void    *mlx;
	void    *mlx_win;
	int		i;
	int		j;
	int		tmp;
	t_data  img;

	i = 0;
	j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
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
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
