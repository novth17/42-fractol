/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:01:42 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/18 22:55:56 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	inside_mandelbrot(t_complex z)
// {
// 	return (z.real * z.real + z.imag * z.imag <= 4);
// }

// int	calculate_mandelbrot(t_complex c)
// {
// 	t_complex	z;
// 	int			iter;
// 	double		tmp_real;

// 	t_complex z = {0.0, 0.0};

// 	while (inside_mandelbrot(z) && iter < MAX_ITERATIONS)
// 	{
// 		tmp_real = z.real * z.real - z.imag * z.imag + c.real;
// 		z.imag = 2.0 * z.real * z.imag + c.imag;
// 		z.real = tmp_real;
// 		iter++;
//  	}
// 	return (iter);
// }

void draw_mandelbrot(t_fractol *fractol)
{
    int col;
    int width;

    col = 0;
    while (col < HEIGHT)
    {
        width = 0;  // Reset width for each new row
        while (width < WIDTH)
        {
            mlx_put_pixel(fractol->image, width, col, 0xffFFFFFF + width); // Use 'width' and 'col'
            width++;
        }
        col++;
    }
}



// void	render_fractol(t_fractol *fractol)
// {
// 	if (fractol->f_type == "mandelbrot")
// 		calculate_mandelbrot(fractol); // TODO
// 	else
// 		calculate_julia(fractol); // TODO
// }
