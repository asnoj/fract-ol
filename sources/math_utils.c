/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:46:22 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/13 00:28:42 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	map(double unscaled_num, t_maparg *arg)
{
	double	res;

	res = (arg->new_max - arg->new_min) * (unscaled_num - arg->old_min)
		/ (arg->old_max - arg->old_min) + arg->new_min;
	free(arg);
	return (res);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

double	char_to_double(char *s)
{
	long	int_part;
	double	fractional_part;
	double	pow;
	int		sign;

	int_part = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		s++;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		int_part = (int_part * 10) + (*s++ - '0');
	if ('.' == *s)
		s++;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s - '0') * pow;
		s++;
	}
	return ((int_part + fractional_part) * sign);
}

// f(z) = 1/4 × [2 + 7z - (2z+5)cos(πz)] => very complicate hihi

t_complex	collatz_complex(t_complex z)
{
	t_complex	result;

	result.x = 0.25 * (1 + 4 * z.x - ((1 + 2 * z.x) * cos(PI * z.x) * cosh(PI
					* z.y) - 2 * z.y * (-sin(PI * z.x) * sinh(PI * z.y))));
	result.y = 0.25 * (4 * z.y - ((1 + 2 * z.x) * (-sin(PI * z.x) * sinh(PI
						* z.y)) + 2 * z.y * (cos(PI * z.x) * cosh(PI * z.y))));
	return (result);
}
