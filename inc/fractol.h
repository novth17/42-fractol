/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:02:02 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/23 20:39:28 by hiennguy         ###   ########.fr       */
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

typedef enum e_set_name
{
	MANDELBROT,
	JULIA
}	t_set_name;


typedef struct s_complex
{
	long double		real;
	long double		imag;
}				t_complex;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	//char		*f_type;
	t_complex	min;
	t_complex	max;
	t_complex	julia_c;
	int			mode;
	int			iter;
	t_set_name	f_name;

}				t_fractol;

/* ===================== INPUT PARSING & INIT ===================== */
void		init_fractol(t_fractol *fractol, char **argv);

/* ===================== FOR DRAW ===================== */
void		render_mandelbrot(t_fractol *fractol);
void		render_julia(t_fractol *fractol);
void		render_fractol(t_fractol *fractol);

uint32_t	put_color_scheme(int iter, int mode);

/* ===================== FOR HOOK ===================== */
void		key_hook (mlx_key_data_t key_data, void *param);



/* ===================== FOR PRINTING ERROR =================== */


/* ===================== FOR FREE =================== */


#endif
