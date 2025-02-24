/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:59:28 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/24 12:54:32 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void color_mode_hook(mlx_key_data_t key_data, t_fractol *fractol)
{
	if (key_data.key == MLX_KEY_R)
	{
		fractol->mode = 0;
		render_fractol(fractol);
	}
	if (key_data.key == MLX_KEY_B)
	{
		fractol->mode = 2;
		render_fractol(fractol);
	}
	if (key_data.key == MLX_KEY_G)
	{
		fractol->mode = 1;
		render_fractol(fractol);
	}
	if (key_data.key == MLX_KEY_W)
	{
		fractol->mode = 3;
		render_fractol(fractol);
	}
}

static void	esc_key_func(mlx_key_data_t keydata, t_fractol *fractol)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(fractol->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	mouse_scroll_hook(double xdelta, double ydelta, void *param)
{
    (void)xdelta;

    t_fractol *fractol = (t_fractol *)param;
    int32_t mouse_x, mouse_y;

    mlx_get_mouse_pos(fractol->mlx, &mouse_x, &mouse_y);
    long double c_real = fractol->min.real + ((long double)mouse_x / WINDOW_WIDTH) *
                         (fractol->max.real - fractol->min.real);
    long double c_imag = fractol->min.imag + ((long double)mouse_y / WINDOW_HEIGHT) *
                         (fractol->max.imag - fractol->min.imag);

    if (ydelta > 0)
	{
		printf("Zooming in at (%Lf, %Lf)\n", c_real, c_imag);
        zoom(fractol, 0.9, c_real, c_imag);
	}
	else if (ydelta < 0)
	{
		printf("Zooming out at (%Lf, %Lf)\n", c_real, c_imag);
        zoom(fractol, 1.1, c_real, c_imag);
	}
    render_fractol(fractol);
}

void key_hook(mlx_key_data_t key_data, void *param)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	color_mode_hook (key_data, fractol);
	esc_key_func(key_data, fractol);
}
