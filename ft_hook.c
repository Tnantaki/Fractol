#include "fractol.h"

int	close(t_param *par)
{
	mlx_destroy_window(par->mlx, par->win);
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_param *par)
{
	if (keycode == 53)
		close(par);
	else if (keycode == 13)
	printf("Key code: %d\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_param *par)
{
	if (keycode == 4)
		par->mouse_scro--;
	else if (keycode == 5)
		par->mouse_scro++;
	printf("%d\n", par->mouse_scro);
	// printf("Key code: %d\n", keycode);
	return (0);
}
