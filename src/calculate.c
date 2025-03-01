/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:08:55 by hiennguy          #+#    #+#             */
/*   Updated: 2025/03/01 14:31:18 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline int	inside_radius(t_complex z)
{
	return (z.real * z.real + z.imag * z.imag <= 4);
}

t_complex	pixel_to_coordinates(t_fractol *fractol, double x, double y)
{
	t_complex	c;

	y = WINDOW_HEIGHT - y;
	c.real = fractol->min.real + (x / WINDOW_WIDTH) * (fractol->max.real
			- fractol->min.real);
	c.imag = fractol->min.imag + (y / WINDOW_HEIGHT) * (fractol->max.imag
			- fractol->min.imag);
	return (c);
}

void	zoom(t_fractol *fractol, double zoom_factor, double c_real,
		double c_imag)
{
	fractol->min.real = c_real - (c_real - fractol->min.real) * zoom_factor;
	fractol->max.real = c_real + (fractol->max.real - c_real) * zoom_factor;
	fractol->min.imag = c_imag - (c_imag - fractol->min.imag) * zoom_factor;
	fractol->max.imag = c_imag + (fractol->max.imag - c_imag) * zoom_factor;
}
