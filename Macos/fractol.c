#include "fractol.h"

// void img_pix_put(t_p *pix, int x, int y, int color)
// {
// 	char *pixel;
// 	int i;

// 	i = pix->bpp - 8;
// 	pixel = pix->addr + (y * pix->line_len + x * (pix->bpp / 8));
// 	while (i >= 0)
// 	{
// 		/* big endian, MSB is the leftmost bit */
// 		if (pix->endian != 0)
// 			*pixel++ = (color >> i) & 0xFF;
// 		/* little endian, LSB is the leftmost bit */
// 		else
// 			*pixel++ = (color >> (pix->bpp - 8 - i)) & 0xFF;
// 		i -= 8;
// 	}
// }

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

char *join_path(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 5));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len_s1)
		str[i++] = *s1++;
	while (i < len_s1 + len_s2)
		str[i++] = *s2++;
	j = 0;
	while (i < len_s1 + len_s2 + 5)
		str[i++] = ".xpm"[j++];
	return (str);
}

void	set_object(t_param *par, void ***banana)
{
	int		i;
	char	*path;

	i = 0;
	while (i < 8)
	{
		path = join_path("xmp/file/", ft_itoa(i));
		printf("%s\n", path);
		exit (0);
		(*banana)[i++] = mlx_xpm_file_to_image(par->mlx, path, 0, 0);
		free(path);
	}

}

void	setup_box(t_obj *box, int x, int y, int h, int w)
{
	box->x = x;
	box->y = y;
	box->h = h;
	box->w = w;
}

int main(void)
{
	t_param	par;
	t_obj	boxA;
	t_obj	boxB;
	t_obj	boxC;
	void	*banana[9];

	init_window(&par);// create window
	par.mouse_scro = 0;
	setup_box(&boxA, 100, 10, 200, 200);
	setup_box(&boxB, 10, 100, 200, 200);
	setup_box(&boxC, 150, 100, 200, 200);
	par.img_dt.img = mlx_new_image(par.mlx, WD_WIDTH, WD_HEIGHT);
	par.img_dt.addr = mlx_get_data_addr(par.img_dt.img, &par.img_dt.bpp, &par.img_dt.line_len, &par.img_dt.endian);
	set_object(&par, &banana);

	// printf("image : %p \n", par.img_dt.img);
	// printf("bpp:%d\n", par.img_dt.bpp);
	// printf("line_len:%d\n", par.img_dt.line_len);
	// printf("endian:%d\n", par.img_dt.endian);

	// par.pos_x = 5;
	// par.pos_y = 5;
	// par.w = 300;
	// par.h = 300;
	render_background(&par, WHITE_PIXEL);
	// render_rec(&par, boxA, RED_PIXEL);
	// render_rec(&par, boxB, GREEN_PIXEL);
	// render_rec(&par, boxC, BLUE_PIXEL);
	// mlx_loop_hook(par.mlx, render_rec, &par);
	// mlx_put_image_to_window(par.mlx, par.win, par.img_dt.img, 0, 0);
	// render_rec(&par, par.w, par.h, par.pos_x, par.pos_y);
	mlx_key_hook(par.win, key_hook, &par); // keyboard hook
	mlx_mouse_hook(par.win, mouse_hook, &par); // mouse hook
	mlx_hook(par.win, 17, 0, close_win, &par);	   // keycode hook
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
