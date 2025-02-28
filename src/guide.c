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
        "   Mandelbrot Usage:\n"
        "       ./fractol mandelbrot\n\n"
        "   Julia Usage (must have custom parameters):\n"
        "       - ./fractol julia [real_part] [imaginary_part]\n"
        "       - [real_part] & [imaginary_part] must be presented in double with a dot\n"
        "       - decimal part must be less than 9 digits, otherwise out of bound\n\n"            
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