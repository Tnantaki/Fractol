#include "fractol.h"

typedef struct s_rec
{
	int width;
	int height;
	int x;
	int y;
} t_rec;

void img_pix_put(t_pix *pix, int x, int y, int color)
{
	char *pixel;
	int i;

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

void render_backgroud(t_param *par)
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
				break;
			}
		}
	}
}

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
				mlx_pixel_put(par->mlx, par->win, x + (width / 2), i, RED_PIXEL);
				break;
			}
			else
			{
				k = (width * i) / (2 * height);
				mlx_pixel_put(par->mlx, par->win, x + (width / 2) - k, i, RED_PIXEL);
				mlx_pixel_put(par->mlx, par->win, (width / 2) + k, i, RED_PIXEL);
				break;
			}
		}
	}
}

int render(t_param *par)
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

void init_window(t_param *par)
{
	par->mlx = mlx_init(); // initialize structure variable for display.
	if (par->mlx == NULL)
		exit(1);
	par->win = mlx_new_window(par->mlx, WD_WIDTH, WD_HEIGHT, "My Window"); // Create window
	if (par->win == NULL)
	{
		// mlx_destroy_display(par->mlx);
		free(par->mlx);
		exit(1);
	}
}

void ft_render(t_param *par, int x)
{
	for (int i = 0; i < WD_WIDTH; i++)
		mlx_pixel_put(par->mlx, par->win, i, x, RED_PIXEL); // put pixel to window
	if (x > 0)
	{
		for (int i = 0; i < WD_WIDTH; i++)
			mlx_pixel_put(par->mlx, par->win, i, x - 1, BLACK_PIXEL); // put pixel to window
	}
}

int render_next_frame(t_param *par)
{
	ft_render(par, par->pos_x);
	par->pos_x++;
	return (0);
}

int main(void)
{
	t_param par;
	t_pix *b;

	init_window(&par);					   // create window
	mlx_key_hook(par.win, key_hook, &par); // keyboard hook
	par.mouse_scro = 0;

	// int x = 5;
	par.pos_x = 0;
	mlx_mouse_hook(par.win, mouse_hook, &par); // mouse hook
	mlx_hook(par.win, 17, 0, close, &par);	   // keycode hook
	// x++;
	mlx_loop_hook(par.mlx, render_next_frame, &par);
	mlx_loop(par.mlx); // Make Window are staying
	free(par.mlx);	   // free init variable
}

// par.pix.img = mlx_new_image(par.mlx, WD_WIDTH, WD_HEIGHT);
// render(&par);
// mlx_put_image_to_window(par.mlx, par.win, img.img, 0, 0);
// par.pix.img = mlx_new_image(par.mlx, WD_WIDTH, WD_HEIGHT);
// par.pix.addr = mlx_get_data_addr(par.pix.img, &par.pix.bpp, &par.pix.line_len, &par.pix.endian);

// mlx_hook(par.win, KeyPress, KeyPressMask, &handle_keypress, &par);
// mlx_hook(par.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &par);
// for (int i = 0; i < 1920; i++)
// mlx_loop_hook(par.mlx, &render, &par);
// mlx_key_hook(par.win, &key_hook, &par);
// mlx_destroy_display(par.mlx);
// img.img = mlx_new_image(mlx, 1920, 1080);
// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 							&img.endian);
// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
