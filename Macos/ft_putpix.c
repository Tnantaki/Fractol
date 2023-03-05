#include "fractol.h"

void	put_pixel_to_image(t_img_data *img_dt, int x, int y, int color)
{
	char	*dst;

	dst = img_dt->addr + (y * img_dt->line_len + x * (img_dt->bpp / 8));
	*(unsigned int*)dst = color;
}
