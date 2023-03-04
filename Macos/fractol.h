#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include <X11/keysym.h>
// # include <X11/X.h>
# include <math.h>

# define WD_WIDTH 1000
# define WD_HEIGHT 800
# define RED_PIXEL 0xa0FF0000
# define GREEN_PIXEL 0xB000FF00
# define BLUE_PIXEL 0xFF
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x0
# define TRAN_PIXEL 0x3000FF00

typedef struct	s_obj//Image structure
{
	int		w;
	int		h;
	int		x;
	int		y;
	// int		endian;
}	t_obj;

typedef struct	s_img_data//Image structure
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img_data;

typedef struct	s_param//Param structure
{
	void		*mlx;
	void		*win;
	t_img_data	img_dt;
	int			pos_x;
	int			pos_y;
	int			w;
	int			h;
	int			mouse_scro;
}	t_param;

//hook
int	close(t_param *par);
int	key_hook(int keycode, t_param *par);
int	mouse_hook(int keycode, int x, int y, t_param *par);
//render
int render_next_frame(t_param *par);
int render_rec(t_param *par, t_obj box, int color);
//put_pixel
void	my_put_pixel(t_img_data *img_dt, int x, int y, int color);

#endif
