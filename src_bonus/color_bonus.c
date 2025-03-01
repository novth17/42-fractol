/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:55:24 by hiennguy          #+#    #+#             */
/*   Updated: 2025/03/01 15:32:40 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static inline uint32_t	color_mode_green(t_fractol *fractol, int iter)
{
	double	t;
	uint8_t	b;
	uint8_t	r;
	uint8_t	g;

	t = (double)iter / fractol->max_iter;
	b = (uint8_t)(9 * (1 - t) * t * t * t * 255);
	r = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
	g = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((255 << 24) | (b << 16) | (g << 8) | r);
}

static inline uint32_t	color_mode_blue(t_fractol *fractol, int iter)
{
	double	t;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	t = (double)iter / fractol->max_iter;
	r = (uint8_t)(9 * (1 - t) * t * t * t * 255);
	g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((255 << 24) | (b << 16) | (g << 8) | r);
}

static inline uint32_t	color_mode_white(t_fractol *fractol, int iter)
{
	double	t;
	int8_t	g_w;
	int8_t	r_w;

	t = (double)iter / fractol->max_iter;
	if (iter >= fractol->max_iter)
		return (0xAA000000);
	g_w = (int8_t)(11 * (1 - t) * (1 - t) * t * t * -100);
	r_w = (int8_t)(11 * (1 - t) * (1 - t) * (1 - t) * t * -100);
	return ((255 << 24) | (g_w << 8) | r_w);
}

static inline uint32_t	color_mode_red(t_fractol *fractol, int iter)
{
	double	t;
	uint8_t	b;
	uint8_t	g;
	uint8_t	r;

	t = (double)iter / fractol->max_iter;
	b = (uint8_t)(9 * (1 - t) * t * t * t * 255);
	g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
	r = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((255 << 24) | (b << 16) | (g << 8) | r);
}

uint32_t	put_color_scheme(t_fractol *fractol, int iter, int mode)
{
	if (mode == 1)
		return (color_mode_green(fractol, iter));
	else if (mode == 2)
		return (color_mode_blue(fractol, iter));
	else if (mode == 3)
		return (color_mode_white(fractol, iter));
	return (color_mode_red(fractol, iter));
}
