/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:06:46 by hiennguy          #+#    #+#             */
/*   Updated: 2025/03/01 19:10:57 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractol(t_fractol *fractol)
{
	if (fractol->f_name == MANDELBROT)
		render_mandelbrot(fractol);
	else
		render_julia(fractol);
}

static void	fractol(char **argv)
{
	t_fractol	fractol;

	init_fractol(&fractol, argv);
	render_fractol(&fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
}

int	main(int argc, char **argv)
{
	if (!validate_input(argc, argv))
	{
		print_guide();
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd("Initializing beautiful set... Here you go!\n", 1);
	fractol(argv);
	return (EXIT_SUCCESS);
}
