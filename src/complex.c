/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:19:33 by jechoque          #+#    #+#             */
/*   Updated: 2018/02/07 14:06:56 by jechoque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex		gen_complex(double r, double i)
{
	t_complex z;

	z.r = r;
	z.i = i;
	return (z);
}

void			add_complex(t_complex *z1, t_complex z2)
{
	z1->r += z2.r;
	z1->i += z2.i;
}

void			square_complex(t_complex *z)
{
	double r;
	double i;

	r = z->r * z->r - z->i * z->i;
	i = 2 * z->r * z->i;
	z->r = r;
	z->i = i;
}

double			mod_complex(t_complex z)
{
	return (sqrtf(z.r * z.r + z.i * z.i));
}
