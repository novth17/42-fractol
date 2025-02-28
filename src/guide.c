#include "fractol.h"

void print_guide(void)
{
    ft_putstr_fd(
        "**************************************************\n"
        "*              FRACT-OL USAGE GUIDE              *\n"
        "**************************************************\n\n"
        "🌀 Available Fractal Sets:\n"
        "   - Mandelbrot\n"
        "   - Julia\n\n"
        "🚀 How to Run:\n"
        "   Basic Usage:\n"
        "       ./fractol [fractal_set_name]\n\n"
        "   Julia Set with Custom Parameters:\n"
        "       ./fractol julia [real_part] [imaginary_part]\n\n"
        "📌 Example Julia Set Parameters:\n"
        "   - -0.4    0.6\n"
        "   -  0.285  0.01\n"
        "   -  0      0.8\n"
        "   - -1.476  0\n"
        "   - -0.12  -0.77\n\n"
        "🎮 Controls:\n"
        "   - 🏁 ESC: Exit the program.\n"
        "   - 🎯 Arrow Keys (← ↑ ↓ →): Move the view.\n"
        "   - 🔍 Mouse Scroll: Zoom in/out at the mouse position.\n"
        "   - ➕ Keypad + / -: Increase or decrease iterations.\n"
        "   - 🎨 R, G, B, W: Switch color modes (Red, Green, Blue, White).\n\n"
        "**************************************************\n", 1);
}