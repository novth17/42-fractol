/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:25:39 by hiennguy          #+#    #+#             */
/*   Updated: 2025/03/01 14:25:41 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void color_mode_hook(mlx_key_data_t key_data, t_fractol *fractol)
{
	if (key_data.key == MLX_KEY_R)
		fractol->mode = 0;
	if (key_data.key == MLX_KEY_G)
		fractol->mode = 1;
	if (key_data.key == MLX_KEY_B)
		fractol->mode = 2;
	if (key_data.key == MLX_KEY_W)
		fractol->mode = 3;
	render_fractol(fractol);
}

static void	esc_key_func(mlx_key_data_t keydata, t_fractol *fractol)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(fractol->mlx);
		exit(EXIT_SUCCESS);
	}
}

static void shift_horizontal(mlx_key_data_t key_data, t_fractol *fractol)
{
    double shift_real = (fractol->max.real - fractol->min.real) * 0.1;

    if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
    {
        fractol->min.real -= shift_real;
        fractol->max.real -= shift_real;
    }
    else if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
    {
        fractol->min.real += shift_real;
        fractol->max.real += shift_real;
    }
	render_fractol(fractol);
}

static void shift_vertical(mlx_key_data_t key_data, t_fractol *fractol)
{
    double shift_imag = (fractol->max.imag - fractol->min.imag) * 0.1;

    if (key_data.key == MLX_KEY_UP && key_data.action == MLX_PRESS)
    {
        fractol->min.imag += shift_imag;
        fractol->max.imag += shift_imag;
    }
    else if (key_data.key == MLX_KEY_DOWN && key_data.action == MLX_PRESS)
    {
        fractol->min.imag -= shift_imag;
        fractol->max.imag -= shift_imag;
    }
	render_fractol(fractol);
}

void key_hook(mlx_key_data_t key_data, void *param)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	color_mode_hook (key_data, fractol);
	shift_horizontal(key_data, fractol);
    shift_vertical(key_data, fractol);
	esc_key_func(key_data, fractol);

	if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_SUBTRACT)
		&& fractol->max_iter > 5)
	{
		fractol->max_iter *= 0.9;
		if (fractol->max_iter <= 5)
			fractol->max_iter = 5;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_ADD)
		&& fractol->max_iter < 500)
	{
		fractol->max_iter *= 1.5;
		if (fractol->max_iter >= 500)
			fractol->max_iter = 500;
	}
}
