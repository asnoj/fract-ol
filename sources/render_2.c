/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:43:05 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/12 23:55:40 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	handle_pixel_celtic(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	double		temp;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (map(x, ifm(-2, 2, 0, WIDTH)) * fractal->zoom + fractal->shift_x);
	c.y = (map(y, ifm(2, -2, 0, HEIGHT)) * fractal->zoom + fractal->shift_y);
	while (i < fractal->iterations_def)
	{
		temp = fabs(z.x * z.x - z.y * z.y) + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = temp;
		if ((z.x * z.x + z.y * z.y) > 4)
		{
			color = get_color_log(i, fractal);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, fractal->f_color);
}

void	handle_pixel_ship(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	double		temp;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (map(x, ifm(-2, 1, 0, WIDTH)) * fractal->zoom + fractal->shift_x);
	c.y = (map(y, ifm(-2, 1, 0, HEIGHT)) * fractal->zoom + fractal->shift_y);
	while (i < fractal->iterations_def)
	{
		temp = z.x * z.x - z.y * z.y + c.x;
		z.y = fabs(2 * z.x * z.y) + c.y;
		z.x = fabs(temp);
		if ((z.x * z.x + z.y * z.y) > 4)
		{
			color = get_color_log(i, fractal);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, fractal->f_color);
}
