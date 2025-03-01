/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:17:00 by hiennguy          #+#    #+#             */
/*   Updated: 2025/03/01 14:25:45 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_scroll_hook(double xdelta, double ydelta, void *param)
{
    (void)xdelta;

    t_fractol *fractol = (t_fractol *)param;
    int32_t mouse_x;
	int32_t	mouse_y;

    mlx_get_mouse_pos(fractol->mlx, &mouse_x, &mouse_y);
    double c_real = fractol->min.real + ((double)mouse_x / fractol->mlx->width) *
                         (fractol->max.real - fractol->min.real);
	double c_imag = fractol->max.imag - ((double)mouse_y / fractol->mlx->height) *
						 (fractol->max.imag - fractol->min.imag);
    if (ydelta > 0)
        zoom(fractol, 0.9, c_real, c_imag);
	else if (ydelta < 0)
        zoom(fractol, 1.1, c_real, c_imag);
    render_fractol(fractol);
}
