/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:25:56 by hiennguy          #+#    #+#             */
/*   Updated: 2025/03/01 15:33:04 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	is_valid_format(const char *str)
{
	int	i;
	int	dot_count;

	dot_count = 0;
	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1 || !ft_isdigit(str[i + 1]))
				return (0);
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_double(const char *str)
{
	double	value;
	int		decimal_places;

	decimal_places = 0;
	if (!is_valid_format(str))
		return (0);
	value = ft_atof(str);
	if (value < -2.0 || value > 2.0)
		return (0);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	while (*str && ft_isdigit(*str))
	{
		decimal_places++;
		if (decimal_places > 8)
			return (0);
		str++;
	}
	return (1);
}

int	validate_input(int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		return (1);
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
	{
		if (!is_valid_double(argv[2]) || !is_valid_double(argv[3]))
		{
			ft_putstr_fd("Error: Invalid Julia set parameters. "
				"Expected two valid floating-point numbers"
				"(from -2 to 2, max 8 decimal places)\n\n",
				2);
			return (0);
		}
		return (1);
	}
	ft_putstr_fd("Error: Incorrect input format. Please read the guide!\n\n",
		2);
	return (0);
}
