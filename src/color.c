/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:55:24 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/23 20:04:56 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t color_mode_green(int iter)
{
    double t = (double)iter / MAX_ITERATIONS;
    uint8_t b = (uint8_t)(9 * (1 - t) * t * t * t * 255);
    uint8_t r = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
    uint8_t g = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    return (255 << 24) | (b << 16) | (g << 8) | r;
}

static uint32_t color_mode_blue(int iter)
{
    double t = (double)iter / MAX_ITERATIONS;
    uint8_t r = (uint8_t)(9 * (1 - t) * t * t * t * 255);
    uint8_t g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
    uint8_t b = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    return (255 << 24) | (b << 16) | (g << 8) | r;
}

uint32_t color_mode_white(int iter)
{
	double t = (double)iter / MAX_ITERATIONS;

	if (iter >= MAX_ITERATIONS)
		return (0xAA000000);
	int8_t g_w = (int8_t)(11 * (1 - t) * (1 - t) * t * t * -100);
	int8_t r_w = (int8_t)(11 * (1 - t) * (1 - t) * (1 - t) * t * -100);
	return ((255 << 24) | (g_w << 8) | r_w);
}

static uint32_t color_mode_red(int iter)
{
    double t = (double)iter / MAX_ITERATIONS;
    uint8_t b = (uint8_t)(9 * (1 - t) * t * t * t * 255);
    uint8_t g = (uint8_t)(15 * (1 - t) * (1 - t) * t * t * 255);
    uint8_t r = (uint8_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    return (255 << 24) | (b << 16) | (g << 8) | r;
}

uint32_t put_color_scheme(int iter, int mode)
{
    if (mode == 1)
        return color_mode_green(iter);
    else if (mode == 2)
        return color_mode_blue(iter);
    else if (mode == 3)
        return color_mode_white(iter);
    return color_mode_red(iter);
}
