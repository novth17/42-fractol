/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:58:48 by hiennguy          #+#    #+#             */
/*   Updated: 2025/03/01 11:25:41 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const char	*get_fractal_name(t_set_name f_name)
{
    if (f_name == JULIA)
		return "Julia Set";
    if (f_name == MANDELBROT)
		return "Mandelbrot Set";
    return "Unknown Fractal";
}

static int	setup_mlx (t_fractol *fractol)
{
	fractol->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, get_fractal_name(fractol->f_name), true);
	if (!fractol->mlx)
	{
		ft_putstr_fd(mlx_strerror(mlx_errno), 2);
		return (EXIT_FAILURE);
	}
	mlx_key_hook(fractol->mlx, &key_hook, fractol);
	mlx_scroll_hook(fractol->mlx, &mouse_scroll_hook, fractol);

	fractol->image = mlx_new_image(fractol->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!fractol->image)
	{
		mlx_close_window(fractol->mlx);
		ft_putstr_fd(mlx_strerror(mlx_errno), 2);
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(fractol->mlx, fractol->image, 0, 0) == -1)

	{
		mlx_close_window(fractol->mlx);
		ft_putstr_fd(mlx_strerror(mlx_errno), 2);
		return(EXIT_FAILURE);
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_set_window_size(fractol->mlx, 1024, 1024);
	return (EXIT_SUCCESS);
}

static void	init_type(t_fractol *fractol, char **argv)
{
	if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		fractol->f_name = JULIA;
		if (argv[2] && argv[3])
		{
			fractol->julia_c.real = ft_atof(argv[2]);
			fractol->julia_c.imag = ft_atof(argv[3]);
		}
	}
	else
	{
		fractol->f_name = MANDELBROT;
	}
}

static void	init_min_max(t_fractol *fractol)
{
	fractol->min.real = -2;
	fractol->min.imag = -2;
	fractol->max.real = 2;
	fractol->max.imag = 2;
}

void	init_fractol(t_fractol *fractol, char **argv)
{
	ft_bzero(fractol, sizeof(t_fractol));
	init_type(fractol, argv);
	init_min_max(fractol);
	fractol->max_iter = 100;
	fractol->mode = 0;
	if (setup_mlx(fractol) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
}
