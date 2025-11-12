/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 05:03:09 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/13 00:07:58 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	get_color_log(int i, t_fractal *fractal)
{
	double	t;
	int		idx;

	t = log(1 + i) / log(1 + fractal->iterations_def);
	idx = (int)(t * fractal->color_psy->len) % fractal->color_psy->len;
	return (fractal->color_psy->tab_psy[idx]);
}

int	mouse_handler_other(int button, int x, int y, t_fractal *fractal)
{
	double	x_fract;
	double	y_fract;

	if (3 == button)
	{
		x_fract = (map(x, ifm(-2, 2, 0, WIDTH)) * fractal->zoom
				+ fractal->shift_x);
		y_fract = (map(y, ifm(2, -2, 0, HEIGHT)) * fractal->zoom
				+ fractal->shift_y);
		ft_printf("\n🦔  📍  Click position:\n");
		ft_printf("    Pixel: [%d, %d]\n", x, y);
		ft_printf("    Fractal: [%D, %D]\n", x_fract, y_fract);
	}
	return (0);
}

int	mouse_handler_zoom_ship(int button, int x, int y, t_fractal *fractal)
{
	double	zoom_factor;
	double	x_in_f;
	double	y_in_f;

	x_in_f = (map(x, ifm(-2, 1, 0, WIDTH)) * fractal->zoom + fractal->shift_x);
	y_in_f = (map(y, ifm(-2, 1, 0, HEIGHT)) * fractal->zoom + fractal->shift_y);
	if (button == 4)
	{
		zoom_factor = 0.9;
		fractal->zoom_count += 0.1;
	}
	else if (button == 5)
	{
		zoom_factor = 1.1;
		fractal->zoom_count -= 0.1;
	}
	else
		return (0);
	fractal->shift_x = x_in_f - (x_in_f - fractal->shift_x)
		* zoom_factor;
	fractal->shift_y = y_in_f - (y_in_f - fractal->shift_y)
		* zoom_factor;
	fractal->zoom *= zoom_factor;
	return (0);
}

int	mouse_handler_zoom(int button, int x, int y, t_fractal *fractal)
{
	double	zoom_factor;
	double	x_in_f;
	double	y_in_f;

	x_in_f = (map(x, ifm(-2, 2, 0, WIDTH)) * fractal->zoom + fractal->shift_x);
	y_in_f = (map(y, ifm(2, -2, 0, HEIGHT)) * fractal->zoom + fractal->shift_y);
	if (button == 4)
	{
		zoom_factor = 0.9;
		fractal->zoom_count += 0.1;
	}
	else if (button == 5)
	{
		zoom_factor = 1.1;
		fractal->zoom_count -= 0.1;
	}
	else
		return (0);
	fractal->shift_x = x_in_f - (x_in_f - fractal->shift_x)
		* zoom_factor;
	fractal->shift_y = y_in_f - (y_in_f - fractal->shift_y)
		* zoom_factor;
	fractal->zoom *= zoom_factor;
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "burning_ship", 11))
	{
		mouse_handler_zoom_ship(button, x, y, fractal);
		mouse_handler_other_ship(button, x, y, fractal);
		fractal_render(fractal);
		return (0);
	}
	mouse_handler_zoom(button, x, y, fractal);
	mouse_handler_other(button, x, y, fractal);
	fractal_render(fractal);
	return (0);
}
