/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:59:28 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/22 23:37:45 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void key_hook(mlx_key_data_t key_data, void *param)
{
	t_fractol *fractol;
	fractol = (t_fractol *)param;

	if (key_data.key == MLX_KEY_R)
	{
		fractol->mode = 0;
		render_mandelbrot(fractol);
	}
	if (key_data.key == MLX_KEY_B)
	{
		fractol->mode = 2;
		render_mandelbrot(fractol);
	}
	if (key_data.key == MLX_KEY_P)
	{
		fractol->mode = 1;
		render_mandelbrot(fractol);
	}
	if (key_data.key == MLX_KEY_W)
	{
		fractol->mode = 3;
		render_mandelbrot(fractol);
	}
}


