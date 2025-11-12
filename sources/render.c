/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:46:25 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/13 00:07:46 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	mandel_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, ifm(-2, 2, 0, WIDTH)) * fractal->zoom + fractal->shift_x);
	z.y = (map(y, ifm(2, -2, 0, HEIGHT)) * fractal->zoom + fractal->shift_y);
	mandel_julia(&z, &c, fractal);
	while (i < fractal->iterations_def)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = get_color_log(i, fractal);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, fractal->f_color);
}

void	handle_pixel_collatz(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	int			i;
	int			color;

	z.x = (map(x, ifm(-2, 2, 0, WIDTH)) * fractal->zoom + fractal->shift_x);
	z.y = (map(y, ifm(2, -2, 0, HEIGHT)) * fractal->zoom + fractal->shift_y);
	i = 0;
	while (i < fractal->iterations_def)
	{
		z = collatz_complex(z);
		if ((z.x * z.x + z.y * z.y) > fractal->escape_value)
		{
			color = get_color_log(i, fractal);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, fractal->f_color);
}

// fractal->escape_value

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (!ft_strncmp(fractal->name, "collatz", 7))
				handle_pixel_collatz(x, y, fractal);
			else if (!ft_strncmp(fractal->name, "burning_ship", 11))
				handle_pixel_ship(x, y, fractal);
			else if (!ft_strncmp(fractal->name, "celtic", 6))
				handle_pixel_celtic(x, y, fractal);
			else
				handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
