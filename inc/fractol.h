/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:02:02 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/19 16:55:08 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include "MLX42.h"
#include "libft.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
# define MAX_ITERATIONS 100

typedef struct s_complex
{
	long double		real;
	long double		imag;
}				t_complex;

typedef struct s_color_scheme
{
	double	red_factor;
	double	green_factor;
	double	blue_factor;
}			t_color_scheme;

// typedef struct	s_color_scheme
// {
// 	t_color_elem lava;
// 	t_color_elem icy_ocean;
// 	t_color_elem rose;
// }			t_color_scheme;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		*f_type;
	t_complex	min;
	t_complex	max;
	t_complex	julia_c;
	t_color_scheme	current_color_scheme;
}				t_fractol;

/* ===================== INPUT PARSING & INIT ===================== */
void	init_fractol(t_fractol *fractol, char **argv);

/* ===================== FOR DRAW ===================== */
void render_mandelbrot(t_fractol *fractol);



/* ===================== FOR PRINTING ERROR =================== */


/* ===================== FOR FREE =================== */


#endif
