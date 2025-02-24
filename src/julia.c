/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:09:35 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/24 12:11:35 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calculate_julia(t_complex z, t_complex c)
{
	int			iter;
	double		tmp_real;

	iter = 0;
	while (inside_radius(z) && iter < MAX_ITERATIONS)
	{
		tmp_real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = tmp_real;
		iter++;
	}
	return (iter);
}

void render_julia(t_fractol *fractol)
{
    long double x;
    long double y;
	t_complex	z;
	uint32_t	pixel_color;

    x = 0;
    while (x < WINDOW_WIDTH)
    {
        y = 0;
        while (y < WINDOW_HEIGHT)
        {
			z = pixel_to_coordinates(fractol, x, y);
			fractol->iter = calculate_julia(z, fractol->julia_c);
			pixel_color = put_color_scheme(fractol->iter, fractol->mode);
			((uint32_t *)fractol->image->pixels)[(((uint32_t)y * fractol->image->width) + (uint32_t)x)] = pixel_color;
            y++;
        }
        x++;
    }
}
