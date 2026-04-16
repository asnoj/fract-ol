/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:46:11 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/12 06:36:46 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_maparg	*ifm(double new_min, double new_max, double old_min,
		double old_max)
{
	t_maparg	*arg;

	arg = malloc(sizeof(t_maparg));
	arg->new_min = new_min;
	arg->new_max = new_max;
	arg->old_min = old_min;
	arg->old_max = old_max;
	return (arg);
}

void	malloc_error(void)
{
	perror("Problems with malloc\n");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "collatz", 7))
		fractal->escape_value = 100;
	else
		fractal->escape_value = 4;
	fractal->iterations_def = 22;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->zoom_count = 1.0;
	fractal->x = 0;
	fractal->y = 0;
	fractal->f_color = COLOR_BLACK;
	color_init_7(fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	fractal->color_psy = NULL;
	data_init(fractal);
	events_init(fractal);
}
