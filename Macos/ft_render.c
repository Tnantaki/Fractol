#include "fractol.h"

void render_background(t_param *par, int color)
{
	for (int i = 0; i < WD_HEIGHT; i++)
	{
		for (int j = 0; j < WD_WIDTH; j++)
			put_pixel_to_image(&par->img_dt, j, i, color);
	}
	mlx_put_image_to_window(par->mlx, par->win, par->img_dt.img, 0, 0);
}

int render_rec(t_param *par, t_obj box, int color)
{
	int	width = box.h + box.y;
	int	height = box.w + box.x;
	int	y = box.y;
	int	x = box.x;
	for (int i = y; i < width; i++)
	{
		for (int j = x; j < height; j++)
			put_pixel_to_image(&par->img_dt, j, i, color);
	}
	mlx_put_image_to_window(par->mlx, par->win, par->img_dt.img, 0, 0);
	return (0);
}

// void render_tri(t_param *par, int width, int height, int x, int y)
// {
// 	int k = 0;
// 	for (int i = y; i < height; i++)
// 	{
// 		for (int j = x; j < width; j++)
// 		{
// 			if (i == height - 1)
// 				mlx_pixel_put(par->mlx, par->win, j, i, RED_PIXEL);
// 			else if (i == 0)
// 			{
// 				mlx_pixel_put(par->mlx, par->win, x + (width / 2), i, RED_PIXEL);
// 				break;
// 			}
// 			else
// 			{
// 				k = (width * i) / (2 * height);
// 				mlx_pixel_put(par->mlx, par->win, x + (width / 2) - k, i, RED_PIXEL);
// 				mlx_pixel_put(par->mlx, par->win, (width / 2) + k, i, RED_PIXEL);
// 				break;
// 			}
// 		}
// 	}
// }

// int render(t_param *par)
// {
// 	// render_point(par);
// 	// render_rec(par, 500, 500, 100, 100);
// 	// render_tri(par, 500, 500, 100, 100);
// 	// render_cir(par, 50, 10, 10);
// 	render_backgroud(par);
// 	// mlx_put_image_to_window(par->mlx, par->win, par->pix.img, 0, 0);
// 	// for(int i = 0; i < WD_WIDTH;i++)
// 	// 	mlx_pixel_put(par->mlx, par->win, i, 5, RED_PIXEL);
// 	// if (par->win)
// 	// 	mlx_pixel_put(par->mlx, par->win, 5, 5, RED_PIXEL);
// 	return (0);
// }

// void ft_render(t_param *par, int x)
// {
// 	for (int i = 0; i < WD_WIDTH; i++)
// 		mlx_pixel_put(par->mlx, par->win, i, x, RED_PIXEL); // put pixel to window
// 	if (x > 0)
// 	{
// 		for (int i = 0; i < WD_WIDTH; i++)
// 			mlx_pixel_put(par->mlx, par->win, i, x - 1, BLACK_PIXEL); // put pixel to window
// 	}
// }

// void ft_render_ver(t_param *par, int y)
// {
// 	for (int i = 0; i < WD_HEIGHT; i++)
// 		mlx_pixel_put(par->mlx, par->win, y, i, RED_PIXEL); // put pixel to window
// 	if (y > 0)
// 	{
// 		for (int i = 0; i < WD_HEIGHT; i++)
// 			mlx_pixel_put(par->mlx, par->win, y - 1, i, BLACK_PIXEL); // put pixel to window
// 	}
// }

int render_next_frame(t_param *par, t_obj *boxA)
{
	render_rec(&par, *boxA, RED_PIXEL);
	// ft_render(par, par->pos_x);
	// par->pos_x++;
	// ft_render_ver(par, par->pos_y);
	// par->pos_y++;
	return (0);
}
