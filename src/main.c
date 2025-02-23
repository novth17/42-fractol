/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:06:46 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/23 19:47:33 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_error(void)
{
	ft_putstr_fd("Enter:\n./fractol mandelbrot OR \n./fractol julia <real_num><img_num>", 2);
	exit(EXIT_FAILURE);
}

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


int main (int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		write(1 ,"success", 8);

		init_fractol(&fractol, argv);
		print_fractol(&fractol);
		render_fractol(&fractol);
		mlx_loop(fractol.mlx);
		mlx_terminate(fractol.mlx);
	}
	else
	{
		print_error();
	}
	return (EXIT_SUCCESS);
}
