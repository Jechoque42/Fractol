/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 10:38:35 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/07 14:07:31 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot_calc(t_fractol *data)
{
	double	r;
	double	i;

	r = data->x / data->zoom + data->x1;
	i = data->y / data->zoom + data->y1;
	data->c = gen_complex(r, i);
	data->z = gen_complex(0.0, 0.0);
	data->it = 0;
	while (mod_complex(data->z) < 2 && data->it < data->iter)
	{
		square_complex(&(data->z));
		add_complex(&(data->z), data->c);
		data->it++;
	}
	put_pxl_to_img(data, data->x, data->y, ft_getcolor(data));
}

void	*mandelbrot(void *tab)
{
	t_fractol	*data;
	double		tmp;

	data = (t_fractol *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			mandelbrot_calc(data);
			data->y++;
		}
		data->x++;
	}
	pthread_exit(NULL);
}

void	mandelbrot_pthread(t_fractol *data)
{
	t_fractol	tab[8];
	pthread_t	t[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_fractol));
		tab[i].y = 100 * i;
		tab[i].y_max = 100 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= 8)
		pthread_create(&t[i - 1], NULL, mandelbrot, &tab[i - 1]);
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
