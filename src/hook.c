/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:54:26 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/07 14:07:03 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		ft_key_hook(int keycode, t_fractol *data)
{
	if (keycode == ESC)
		ft_delfract(data);
	else if (keycode == RESET)
		ft_frc_init(data);
	else if (keycode == ITERUP)
		data->iter++;
	else if (keycode == ITERDOWN)
		data->iter--;
	else if (keycode == UP)
		data->y1 += 30 / data->zoom;
	else if (keycode == DOWN)
		data->y1 -= 30 / data->zoom;
	else if (keycode == RIGHT)
		data->x1 -= 30 / data->zoom;
	else if (keycode == LEFT)
		data->x1 += 30 / data->zoom;
	else if (keycode == UNLOCKM)
		data->block_mouse = 0;
	else if (keycode == LOCKM)
		data->block_mouse = 1;
	else if (keycode == COLOR1)
		data->color = 1020;
	else if (keycode == COLOR2)
		data->color = 200100;
	else if (keycode == COLOR3)
		data->color = 3005612;
	else if (keycode == JULIA)
		data->fract = 0;
	else if (keycode == MANDEL)
		data->fract = 1;
	else if (keycode == BURNING)
		data->fract = 2;
	else if (keycode == BATMAN)
		data->fract = 3;
	ft_fract_calc(data);
	return (0);
}

void	ft_zoom(int x, int y, t_fractol *data)
{
	data->x2 = x;
	data->y2 = y;
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.5));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.5));
	data->zoom *= 1.5;
	data->iter++;
}

void	ft_dezoom(t_fractol *data)
{
	data->x1 = (data->x2 / data->zoom + data->x1) - (data->x2 / (data->zoom / 1.5));
	data->y1 = (data->y2 / data->zoom + data->y1) - (data->y2 / (data->zoom / 1.5));
	data->zoom /= 1.5;
	data->iter--;
}

int		ft_mouse_var(int x, int y, t_fractol *data)
{
	if((data->fract == 1 || data->fract == 3) && data->block_mouse == 0)
	{
		data->c = gen_complex(x, y);
		ft_fract_calc(data);
	}
	return (0);
}

int		ft_mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, data);
	else if ((mousecode == 5 || mousecode == 2) && data->zoom > 1)
		ft_dezoom(data);
	ft_fract_calc(data);
	return (0);
}
