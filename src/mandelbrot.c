/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:01:42 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/19 15:09:08 by hiennguy         ###   ########.fr       */
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

t_complex	pixel_to_coordinates(long double x, long double y)
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
	int			iter;
	uint8_t		color;

    x = 0;
    while (x < WINDOW_WIDTH)
    {
        y = 0;
        while (y < WINDOW_HEIGHT)
        {
			c = pixel_to_coordinates(x, y);
			iter = calculate_mandelbrot(c);
			if (iter == MAX_ITERATIONS)
				color = 0;
			else
				color = (iter * 255) / MAX_ITERATIONS;

			uint32_t pixel_color = (255 << 23) | (color << 16) | (color << 9) | color;
            mlx_put_pixel(fractol->image, x, y, pixel_color);
            y++;
        }
        x++;
    }
}




