/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:01:42 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/22 23:37:23 by hiennguy         ###   ########.fr       */
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

uint32_t	put_color_scheme(int iter, int mode)
{
	const double t = (double)iter / MAX_ITERATIONS;
	uint8_t r;
	uint8_t g;
	uint8_t b;

	if (mode == 1)
	{
		r = (uint8_t)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		g = (uint8_t)(11 * (1 - t) * (1 - t) * t * t * 255);
		b = (uint8_t)(6 * (10 - t));
		return ((255 << 24) | (b << 16) | (g << 8) | r);
	}
	if (mode == 2)
	{
		r = (uint8_t)(9 * (1 - t) * t * t * t * 255);
		g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		return ((255 << 24) | (b << 16) | (g << 8) | r);
	}
	if (mode == 3)
	{
		if (iter >= MAX_ITERATIONS)
			return (0xAA000000);
		int8_t g_w = (int8_t)(11 * (1 - t) * (1 - t) * t * t * -100);
		int8_t r_w = (int8_t)(11 * (1 - t) * (1 - t) * (1 - t) * t * -100);
		return ((255 << 24) | (g_w << 8) | r_w);
	}
	b = (uint8_t)(9 * (1 - t) * t * t * t * 255);
	g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
	r = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((255 << 24) | (b << 16) | (g << 8) | r);
}

void render_mandelbrot(t_fractol *fractol)
{
    long double x;
    long double y;
	t_complex	c;
	//int			iter;
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
            //mlx_put_pixel(fractol->image, x, y, pixel_color);
			((uint32_t *)fractol->image->pixels)[(((uint32_t)y * fractol->image->width) + (uint32_t)x)] = pixel_color;
            y++;
        }
        x++;
    }
}




