// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "fractol.h"


static void	print_error(void)
{
	ft_putstr_fd("Enter:\n./fractol mandelbrot OR \n./fractol julia <real_num><img_num>", 2);
	exit(EXIT_FAILURE);
}

static void	print_fractol(t_fractol *f)
{
	printf("=== t_fractol Structure ===\n");
	printf("MLX Address: %p\n", (void *)f->mlx);
	printf("Image Address: %p\n", (void *)f->image);
	printf("Fractal Type: %s\n", f->f_type ? f->f_type : "NULL");
	printf("Min Complex: (%.3Lf, %.3Lf)\n", f->min.real, f->min.imag);
	printf("Max Complex: (%.3Lf, %.3Lf)\n", f->max.real, f->max.imag);
	printf("Julia Constant: (%.3Lf, %.3Lf)\n", f->julia_c.real, f->julia_c.imag);
	printf("===========================\n");
}

int main (int argc, char **argv)
{
	t_fractol fractol;
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		write(1 ,"success", 8);

		init_fractol(&fractol, argv);

		//render_fractol(&fractol);
		print_fractol(&fractol);

		render_mandelbrot(&fractol);

		mlx_loop(fractol.mlx);
		mlx_terminate(fractol.mlx);
	}
	else
	{
		print_error();
	}
	return (EXIT_SUCCESS);
}
