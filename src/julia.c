/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 10:17:02 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/07 14:07:16 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia_calc(t_fractol *data)
{
	double	r;
	double	i;

	r = data->x / data->zoom + data->x1;
	i = data->y / data->zoom + data->y1;
	data->z = gen_complex(r, i);
	data->it = 0;
	while (mod_complex(data->z) < 2 && data->it < data->iter)
	{
		r = data->z.r;
		data->z.r = data->z.r * data->z.r -
			data->z.i * data->z.i - data->c.r / WIDTH;
		data->z.i = 2 * data->z.i * r + data->c.i / WIDTH;
		data->it++;
	}
	put_pxl_to_img(data, data->x, data->y, ft_getcolor(data));
}

void	*julia(void *tab)
{
	double		tmp;
	t_fractol	*data;

	data = (t_fractol *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			julia_calc(data);
			data->y++;
		}
		data->x++;
	}
	pthread_exit(NULL);
}

void	julia_pthread(t_fractol *data)
{
	t_fractol	tab[8];
	pthread_t	thr[8];
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
		pthread_create(&thr[i - 1], NULL, julia, &tab[i - 1]);
	while (i--)
		pthread_join(thr[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
