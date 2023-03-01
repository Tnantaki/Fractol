#include "fractol.h"

void	my_put_pixel(t_pix *pix, int x, int y, int color)
{
	char	*dst;

	dst = pix->addr + (y * pix->line_len + x * (pix->bpp / 8));
	*(unsigned int*)dst = color;
}
