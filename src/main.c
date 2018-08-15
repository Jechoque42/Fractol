/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <jbchoquet@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:31:38 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/07 14:07:21 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		ft_fract_calc(t_fractol *data)
{
	if (data->iter < 0)
		data->iter = 0;
	if (data->fract == 0)
		mandelbrot_pthread(data);
	else if (data->fract == 1)
		julia_pthread(data);
	else if (data->fract == 2)
		burningship_pthread(data);
	else if (data->fract == 3)
		batman_pthread(data);
	put_text(data);
}

int		ft_fract_comp(char *str, t_fractol *data)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		data->fract = 0;
	else if (ft_strcmp(str, "julia") == 0)
		data->fract = 1;
	else if (ft_strcmp(str, "burningship") == 0)
		data->fract = 2;
	else if (ft_strcmp(str, "batman") == 0)
		data->fract = 3;
	else
		ft_fractol_error(data, 1);
	return (1);
}

int		main(int ac, char **av)
{
	t_fractol	*data;

	if (!(data = (t_fractol *)malloc(sizeof(t_fractol))))
		ft_fractol_error(data, 2);
	if (ac == 2)
		ft_fract_comp(av[1], data);
	else
		ft_fractol_error(data, 1);
	ft_mlx_init(data);
	ft_frc_init(data);
	mlx_hook(data->win, MOTION, MOTIONMASK, ft_mouse_var, data);
	mlx_hook(data->win, KEYPRESS, KEYPRESSMASK,  ft_key_hook, data);
	mlx_mouse_hook(data->win, ft_mouse_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
