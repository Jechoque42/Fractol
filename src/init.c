/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:33:10 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/07 14:07:08 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_mlx_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->line, &data->end);
}

void	ft_frc_init(t_fractol *data)
{
	data->iter = 40;
	data->zoom = 200;
	data->x1 = -2.0;
	data->y1 = -2.0;
	data->color = 200;
	data->block_mouse = 0;
	ft_fract_calc(data);
}
