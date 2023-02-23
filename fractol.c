#include "fractol.h"

typedef struct s_rec
{
	int	width;
	int	height;
	int	x;
	int	y;
}	t_rec;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	key_hook(int keycode, t_param *par)
{
	if (keycode == XK_Escape)
		mlx_destroy_window(par->mlx, par->win);
	return (0);
}

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	handle_keypress(int keysym, t_param *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);

	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

// void	img_pix_put(t_img *img, int x, int y, int color)
// {
// 	char    *pixel;

//     pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	*(int *)pixel = color;
// }

void	img_pix_put(t_pix *pix, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = pix->bpp - 8;
    pixel = pix->addr + (y * pix->line_len + x * (pix->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (pix->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (pix->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	render_backgroud(t_param *par)
{
	for (int i = 0; i < WD_HEIGHT; i++)
	{
		for (int j = 0; j < WD_WIDTH; j++)
			mlx_pixel_put(par->mlx, par->win, j, i, 0x00FFFF);
	}
}

void render_point(t_param *par)
{
	mlx_pixel_put(par->mlx, par->win, 10, 10, RED_PIXEL);
}

void render_rec(t_param *par, int width, int height, int x, int y)
{
	for (int i = y; i < height; i++)
	{
		for (int j = x; j < width; j++)
		{
			if (i == y || i == height - 1)
				mlx_pixel_put(par->mlx, par->win, j, i, GREEN_PIXEL);
			else
			{
				mlx_pixel_put(par->mlx, par->win, x, i, GREEN_PIXEL);
				mlx_pixel_put(par->mlx, par->win, width - 1, i, GREEN_PIXEL);
				break ;
			}
		}
	}
}

// void render_cir(t_param *par, int radius, int x, int y)
// {
// 	int	k = 0;

// 	for (int i = y; i < radius * 2 - y; i++, k++)
// 	{
// 		if (k == 0 || k == radius * 2 - 1)
// 			mlx_pixel_put(par->mlx, par->win, radius + x, i, RED_PIXEL);	
// 		else
// 		{
// 			mlx_pixel_put(par->mlx, par->win, radius + x - k, i, RED_PIXEL);	
// 			mlx_pixel_put(par->mlx, par->win, radius + x + k, i, RED_PIXEL);	
// 		}
// 	}
// }
void render_tri(t_param *par, int width, int height, int x, int y)
{
	int k = 0;
	for (int i = y; i < height; i++)
	{
		for (int j = x; j < width; j++)
		{
			if (i == height - 1)
				mlx_pixel_put(par->mlx, par->win, j, i, RED_PIXEL);
			else if (i == 0)
			{
				mlx_pixel_put(par->mlx, par->win, x + (width/2), i, RED_PIXEL);
				break ;
			}
			else
			{
				k = (width * i)/(2 * height);
				mlx_pixel_put(par->mlx, par->win, x + (width/2) - k, i, RED_PIXEL);
				mlx_pixel_put(par->mlx, par->win, (width/2) + k, i, RED_PIXEL);
				break ;
			}
		}
	}
}

int	render(t_param *par)
{
	// render_point(par);
	// render_rec(par, 500, 500, 100, 100);
	// render_tri(par, 500, 500, 100, 100);
	// render_cir(par, 50, 10, 10);
	render_backgroud(par);
	// mlx_put_image_to_window(par->mlx, par->win, par->pix.img, 0, 0);
	// for(int i = 0; i < WD_WIDTH;i++)
	// 	mlx_pixel_put(par->mlx, par->win, i, 5, RED_PIXEL);
	// if (par->win)
	// 	mlx_pixel_put(par->mlx, par->win, 5, 5, RED_PIXEL);
	return (0);
}

void	init_window(t_param *par)
{
	par->mlx = mlx_init();//initialize structure variable for display.
	if (par->mlx == NULL)
		exit(1);
	par->win = mlx_new_window(par->mlx, WD_WIDTH, WD_HEIGHT, "My Window");//Create window
	if (par->win == NULL)
	{
		mlx_destroy_display(par->mlx);
		free(par->mlx);
		exit(1);
	}
}

int	main(void)
{
	t_param	par;

	init_window(&par);
	par.pix.img = mlx_new_image(par.mlx, WD_WIDTH, WD_HEIGHT);
	par.pix.addr = mlx_get_data_addr(par.pix.img, &par.pix.bpp, &par.pix.line_len, &par.pix.endian);
	render(&par);
	// mlx_put_image_to_window(par.mlx, par.win, img.img, 0, 0);
	// par.img.img = mlx_new_image(par.mlx, WD_WIDTH, WD_HEIGHT);

	// mlx_hook(par.win, KeyPress, KeyPressMask, &handle_keypress, &par);
	// mlx_hook(par.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &par);
	// for (int i = 0; i < 1920; i++)
	// 	mlx_pixel_put(par.mlx, par.win, i, 5, 20);
	// mlx_loop_hook(par.mlx, &render, &par);
	mlx_key_hook(par.win, &key_hook, &par);
	mlx_loop(par.mlx);// Make Window are staying
	mlx_destroy_display(par.mlx);
	free(par.mlx);
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
}