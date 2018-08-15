/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:54:08 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/07 14:01:35 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		ft_delfract(t_fractol *data)
{
	free(data);
	exit(1);
}

void		ft_fractol_error(t_fractol *data, int mod)
{
	if (mod == 1)
		ft_putstr_fd(
		"usage: fractol [julia][mandelbrot][burningship][batman]\n", 2);
	if (mod == 2)
		ft_putstr_fd("malloc error\n", 2);
	if (data != NULL)
		free(data);
	exit(1);
}

void		put_pxl_to_img(t_fractol *data, int x, int y, int color)
{
	if (data->x < WIDTH && data->y < WIDTH)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void		put_text(t_fractol *data)
{
	char	*text;
	char	*nb;

	nb = ft_itoa(data->iter);
	text = ft_strjoin("iterations : ", nb);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, text);
	ft_strdel(&text);
	ft_strdel(&nb);
}

unsigned int	ft_getcolor(t_fractol *data)
{
	unsigned int	c;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (data->it == data->iter)
		return (0x000000);
	r = (data->it * 5) * data->color;
	g = (255 - (data->it * 5)) * data->color;
	b = (255 - (data->it * 5)) * data->color;
	c = (r << 16) + (g << 8) + b;
	return (c);
}
