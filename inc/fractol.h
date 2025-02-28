/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:02:02 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/28 13:46:08 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include "MLX42.h"
#include "libft.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
//# define MAX_ITERATIONS 500

typedef enum	e_set_name
{
	MANDELBROT,
	JULIA
}				t_set_name;


typedef struct	s_complex
{
	long double		real;
	long double		imag;
}				t_complex;

typedef struct	s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_complex	min;
	t_complex	max;
	t_complex	julia_c;
	int			mode;
	int			max_iter;
	int			iter;
	double		change_ratio;
	t_set_name	f_name;
}				t_fractol;

/* ===================== INPUT PARSING & INIT ===================== */
void		init_fractol(t_fractol *fractol, char **argv);
int			validate_input(int argc, char **argv);

/* ===================== FOR DRAW ===================== */
void		render_mandelbrot(t_fractol *fractol);
void		render_julia(t_fractol *fractol);
void		render_fractol(t_fractol *fractol);
uint32_t	put_color_scheme(t_fractol *fractol, int iter, int mode);

/* ===================== FOR HOOK ===================== */
void		key_hook (mlx_key_data_t key_data, void *param);
void		mouse_scroll_hook(double xdelta, double ydelta, void *param);

/* ===================== FOR CALCULATION =================== */
int			inside_radius(t_complex z);
t_complex	pixel_to_coordinates(t_fractol *fractol, long double x, long double y);
void		zoom(t_fractol *fractol, long double zoom_factor, long double c_real, long double c_imag);


/* ===================== FOR ERROR =================== */
void	print_guide(void);

#endif
