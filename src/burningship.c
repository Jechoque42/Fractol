/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:26:11 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/07 14:06:50 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	burningship_calc(t_fractol *data)
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
		data->z.i = fabs(data->z.i);
		data->z.r = fabs(data->z.r);
		data->it++;
	}
	put_pxl_to_img(data, data->x, data->y, ft_getcolor(data));
}

void	*burningship(void *tab)
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
			burningship_calc(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	burningship_pthread(t_fractol *data)
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
		pthread_create(&t[i - 1], NULL, burningship, &tab[i - 1]);
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
