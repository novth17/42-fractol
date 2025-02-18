/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:58:48 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/18 20:15:03 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	setup_mlx (t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, fractol->f_type, true);
	if (!fractol->mlx)
	{
		ft_putstr_fd(mlx_strerror(mlx_errno), 2);
		return (EXIT_FAILURE);
	}
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
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
	return (EXIT_SUCCESS);
}

static void	init_type(t_fractol *fractol, char **argv)
{
	if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		fractol->f_type = "julia";
		fractol->julia_c.real = -0.7269;
		fractol->julia_c.imag = 0.1889;
		if (argv[2] && argv[3])
		{
			fractol->julia_c.real = ft_atof(argv[2]);
			fractol->julia_c.imag = ft_atof(argv[3]);
		}
	}
	else
	{
		fractol->f_type = "mandelbrot";
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
	if (setup_mlx(fractol) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
}
