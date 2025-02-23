/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:59:28 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/23 20:40:03 by hiennguy         ###   ########.fr       */
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

// static void	arrow_keys(mlx_key_data_t keydata, t_fractol *fractol)
// {

// }

void key_hook(mlx_key_data_t key_data, void *param)
{
	t_fractol *fractol;

	fractol = (t_fractol *)param;
	color_mode_hook (key_data, fractol);
	esc_key_func(key_data, fractol);
}
