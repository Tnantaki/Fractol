#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>

# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

# define WD_WIDTH 1920
# define WD_HEIGHT 1080
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFF
# define WHITE_PIXEL 0xFFFFFF
# define TRAN_PIXEL 0x3000FF00

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
}	t_param;

#endif