/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiennguy <hiennguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:51:22 by hiennguy          #+#    #+#             */
/*   Updated: 2025/02/18 19:56:28 by hiennguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

double	ft_atof(const char *str)
{
	double	result_1;
	double	result_2;
	char	*c;
	int		len;

	c = (char *)str;
	result_1 = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	result_2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		result_2 /= 10;
	if (result_1 >= 0)
		return (result_1 + result_2);
	else
		return (result_1 + (-result_2));
}
