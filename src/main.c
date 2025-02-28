/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:06:46 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/28 14:28:52 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_fractol(t_fractol *f)
{
    if (!f)
    {
        printf("t_fractol structure is NULL\n");
        return;
    }

    printf("=== t_fractol Structure ===\n");
    printf("MLX Address: %p\n", (void *)f->mlx);
    printf("Image Address: %p\n", (void *)f->image);

    // Convert fractal type to a string if t_set_name is an enum
    const char *fractol_name = "Unknown";
    if (f->f_name == JULIA)      fractol_name = "Julia";
    else if (f->f_name == MANDELBROT) fractol_name = "Mandelbrot";

    printf("Fractal Type: %s\n", fractol_name);

    printf("Min Complex: (%.6Lf, %.6Lf)\n", f->min.real, f->min.imag);
    printf("Max Complex: (%.6Lf, %.6Lf)\n", f->max.real, f->max.imag);
    printf("Julia Constant: (%.6Lf, %.6Lf)\n", f->julia_c.real, f->julia_c.imag);
    printf("Mode: %d\n", f->mode);
    printf("Iterations: %d\n", f->iter);
    printf("===========================\n");
}

void	render_fractol(t_fractol *fractol)
{
	if (fractol->f_name == MANDELBROT)
		render_mandelbrot(fractol);
	else
		render_julia(fractol);
}

void fractol(char **argv)
{
    t_fractol fractol;

    init_fractol(&fractol, argv);
    print_fractol(&fractol);
    render_fractol(&fractol);
    mlx_loop(fractol.mlx);
    mlx_terminate(fractol.mlx);
}

int main(int argc, char **argv)
{
    if (!validate_input(argc, argv))
	{
		print_guide();
 		exit(EXIT_FAILURE);
	}
	write(1, "success\n", 8);
    fractol(argv);
    return (EXIT_SUCCESS);
}
