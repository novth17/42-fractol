/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:02:02 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/18 22:37:58 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include "MLX42.h"
#include "libft.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 100

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		*f_type;
	t_complex	min;
	t_complex	max;
	t_complex	julia_c;
}				t_fractol;

/* ===================== INPUT PARSING & INIT ===================== */
void	init_fractol(t_fractol *fractol, char **argv);

/* ===================== FOR DRAW ===================== */
void	draw_mandelbrot(t_fractol *fractol);



/* ===================== FOR PRINTING ERROR =================== */


/* ===================== FOR FREE =================== */


#endif
