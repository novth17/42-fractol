/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:02:02 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/22 23:34:49 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include "MLX42.h"
#include "libft.h"

# define WINDOW_WIDTH 2160
# define WINDOW_HEIGHT 2160
# define MAX_ITERATIONS 100

typedef struct s_complex
{
	long double		real;
	long double		imag;
}				t_complex;

// typedef struct s_color_elem
// {
// 	uint8_t	red_factor[800*800];
// 	uint8_t	*green_factor[800*800];
// 	uint8_t	*blue_factor[800*800];
// }			t_color_elem;

//  typedef struct	s_color_scheme
// {
// 	t_color_elem *lava;
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
	int			mode;
	int			iter;

}				t_fractol;

/* ===================== INPUT PARSING & INIT ===================== */
void	init_fractol(t_fractol *fractol, char **argv);

/* ===================== FOR DRAW ===================== */
void render_mandelbrot(t_fractol *fractol);
uint32_t	put_color_scheme(int iter, int mode);

void key_hook(mlx_key_data_t key_data, void *param);


/* ===================== FOR PRINTING ERROR =================== */


/* ===================== FOR FREE =================== */


#endif
