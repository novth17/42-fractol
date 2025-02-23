/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:01:42 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/23 17:07:28 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	inside_mandelbrot(t_complex z)
{
	return (z.real * z.real + z.imag * z.imag <= 4);
}

static int	calculate_mandelbrot(t_complex c)
{
	int			iter;
	double		tmp_real;

	t_complex z = {0.0, 0.0};
	iter = 0;

	while (inside_mandelbrot(z) && iter < MAX_ITERATIONS)
	{
		tmp_real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = tmp_real;
		iter++;
 	}
	return (iter);
}

static t_complex	pixel_to_coordinates(long double x, long double y)
{
	t_complex	c;
	c.real = (x - WINDOW_WIDTH / 2.0) * 4.0 / WINDOW_WIDTH;
	c.imag = (y - WINDOW_HEIGHT / 2.0) * 4.0 / WINDOW_HEIGHT;
	return c;
}

void render_mandelbrot(t_fractol *fractol)
{
    long double x;
    long double y;
	t_complex	c;

	uint32_t	pixel_color;

    x = 0;
    while (x < WINDOW_WIDTH)
    {
        y = 0;
        while (y < WINDOW_HEIGHT)
        {
			c = pixel_to_coordinates(x, y);
			fractol->iter = calculate_mandelbrot(c);
			pixel_color = put_color_scheme(fractol->iter, fractol->mode);
			((uint32_t *)fractol->image->pixels)[(((uint32_t)y * fractol->image->width) + (uint32_t)x)] = pixel_color;
            y++;
        }
        x++;
    }
}




