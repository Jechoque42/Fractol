/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:22:39 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/07 13:51:27 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <pthread.h>
# include <math.h>
# include <stdlib.h>

# define WIDTH		800

# define KEYPRESS	2
# define KEYPRESSMASK	(1L<<0)
# define MOTION		6
# define MOTIONMASK	(1L<<6)
# define UNLOCKM	0
# define LOCKM		1

# define LEFT		123
# define RIGHT		124
# define DOWN		125
# define UP		126

# define JULIA		26
# define MANDEL		28
# define BURNING	25
# define BATMAN		29

# define PSY_ON		45
# define PSY_OFF	11
# define COLOR1		18
# define COLOR2		19
# define COLOR3		20
# define COLOR4		21

# define ITERUP		12
# define ITERDOWN	13
# define RESET		49
# define ESC		53


typedef struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct		s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int		bpp;
	int		line;
	int		end;
	int		fract;
	int		color;
	int		block_mouse;
	double		zoom;
	double		it;
	double		iter;
	double		x;
	double		y;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		y_max;
	double		tmp;
	t_complex	z;
	t_complex	c;
}			t_fractol;

unsigned int		ft_getcolor(t_fractol *data);
int			ft_key_hook(int keycode, t_fractol *data);
int			ft_key_hook2(int keycode, t_fractol *data);
void			ft_zoom(int x, int y, t_fractol *data);
void			ft_dezoom(t_fractol *data);
int			ft_mouse_hook(int mousecode, int x, int y, t_fractol *data);
int			ft_mouse_var(int x, int y, t_fractol *data);

void			mandelbrot_calc(t_fractol *data);
void			*mandelbrot(void *tab);
void			mandelbrot_pthread(t_fractol *data);

void			julia_calc(t_fractol *data);
void			*julia(void *tab);
void			julia_pthread(t_fractol *data);

void			burningship_calc(t_fractol *data);
void			*burningship(void *tab);
void			burningship_pthread(t_fractol *data);

void			batman_calc(t_fractol *data);
void			*batman(void *tab);
void			batman_pthread(t_fractol *data);

void			ft_delfract(t_fractol *data);
void			put_pxl_to_img(t_fractol *data, int x, int y, int color);
void			put_text(t_fractol *data);

void			ft_fract_calc(t_fractol *data);
void			ft_fract_init(t_fractol *data);
int			ft_fract_comp(char *str, t_fractol *data);

t_complex		gen_complex(double r, double i);
void			add_complex(t_complex *z1, t_complex z2);
void			square_complex(t_complex *z);
double			mod_complex(t_complex z);

void			ft_frc_init(t_fractol *data);
void			ft_mlx_init(t_fractol *data);
void			ft_fractol_error(t_fractol *data, int mod);

#endif
