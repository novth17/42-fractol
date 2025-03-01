/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:28:05 by hiennguy          #+#    #+#             */
/*   Updated: 2025/03/01 14:28:07 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void print_guide_how_to(void)
{
    ft_putstr_fd(
        "📌 Hien's FAV Julia Set Parameters: 😘💋\n"
        "   ────────────────────────────────────\n"
        "   🔹 -0.4    0.6     (Look to your soul)\n"
        "   🔹  0.285  0.01    (Baby dino)\n"
        "   🔹  0      0.8     (A sky full of stars)\n"
        "   🔹 -1.476  0       (Radio hardcore)\n"
        "   🔹 -0.12  -0.77    (Puzzled bunnies)\n"
        "   ────────────────────────────────────\n\n"
        "🎮 How to Play:\n"
        "   ────────────────────────────────────\n"
        "   🏁 ESC          ➜ Exit the program\n"
        "   🎯 Arrow Keys   ➜ Move the view (← ↑ ↓ →)\n"
        "   🔍 Mouse Scroll ➜ Zoom in/out at mouse position\n"
        "   ➕ Keypad + / -  ➜ Increase or decrease iterations\n"
        "   🎨 R, G, B, W   ➜ Switch color modes (Red, Green, Blue, White)\n"
        "   ────────────────────────────────────\n",
        1);
}

void print_guide(void)
{
    ft_putstr_fd(
        "**************************************************\n"
        "*               FRACT-OL USAGE GUIDE             *\n"
        "**************************************************\n\n"
        "🌀 Available Fractal Sets:\n"
        "   ────────────────────────────────────\n"
        "   🔹 Mandelbrot\n"
        "   🔹 Julia\n"
        "   ────────────────────────────────────\n\n"
        "🚀 How to Run:\n"
        "   ────────────────────────────────────\n"
        "   🟢 Mandelbrot Usage:\n"
        "      ➜ ./fractol mandelbrot\n\n"
        "   🟣 Julia Usage (Must have custom parameters):\n"
        "      ➜ ./fractol julia [real_part] [imaginary_part]\n"
        "      🔹 [real_part] & [imaginary_part] must be doubles with a dot\n"
        "      🔹 Julia set parameters must be between -2.0 and 2.0\n"
        "      🔹 Decimal part must be less than 9 digits to avoid out-of-bounds errors\n"
        "   ────────────────────────────────────\n\n",
        1);
    print_guide_how_to();
}
