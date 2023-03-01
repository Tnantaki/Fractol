#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
// # include <X11/keysym.h>
// # include <X11/X.h>
# include <math.h>

# define WD_WIDTH 1000
# define WD_HEIGHT 800
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFF
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x0
# define TRAN_PIXEL 0x3000FF00
typedef struct	s_a
{
	int a;
}	t_a;

typedef struct	s_pix//Image structure
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_pix;

typedef struct	s_param//Param structure
{
	void	*mlx;
	void	*win;
	t_pix	pix;
	int		mouse_scro;
	int		pos_x;
}	t_param;

//hook
int	close(t_param *par);
int	key_hook(int keycode, t_param *par);
int	mouse_hook(int keycode, int x, int y, t_param *par);

#endif
