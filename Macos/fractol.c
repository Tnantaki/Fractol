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

void init_window(t_param *par)
{
	par->mlx = mlx_init(); // initialize structure variable for display.
	if (par->mlx == NULL)
		exit(1);
	par->win = mlx_new_window(par->mlx, WD_WIDTH, WD_HEIGHT, "My Window"); // Create window
	if (par->win == NULL)
	{
		// mlx_destroy_display(par->mlx);
		// free(par->mlx);
		exit(1);
	}
}

int	move_ob(t_param *par)
{
	render_rec(par);
	return (0);
}


int main(void)
{
	t_param par;

	init_window(&par);// create window
	par.mouse_scro = 0;


	par.pix.img = mlx_new_image(par.mlx, WD_WIDTH, WD_HEIGHT);
	par.pix.addr = mlx_get_data_addr(par.pix.img, &par.pix.bpp, &par.pix.line_len, &par.pix.endian);

	printf("bpp:%d\n", par.pix.bpp);
	printf("line_len:%d\n", par.pix.line_len);
	printf("endian:%d\n", par.pix.endian);

	par.pos_x = 5;
	par.pos_y = 5;
	par.w = 300;
	par.h = 300;
	// render_rec(&par);
	render_rec(&par);
	// while (par.pos_x < 300)
		// my_put_pixel(&par.pix, par.pos_x++, par.pos_y, RED_PIXEL);
	// mlx_loop_hook(par.mlx, render_rec, &par);
	mlx_put_image_to_window(par.mlx, par.win, par.pix.img, 0, 0);
	// render_rec(&par, par.w, par.h, par.pos_x, par.pos_y);
	mlx_key_hook(par.win, key_hook, &par); // keyboard hook
	mlx_mouse_hook(par.win, mouse_hook, &par); // mouse hook
	mlx_hook(par.win, 17, 0, close, &par);	   // keycode hook
	// mlx_loop_hook(par.mlx, render_next_frame, &par);
	mlx_loop(par.mlx); // Make Window are staying
	// free(par.mlx);	   // free init variable
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
