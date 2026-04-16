/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:39:08 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/13 00:23:08 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	free(fractal->color_psy->tab_psy);
	free(fractal->color_psy);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_handler_other(int button, t_fractal *fractal)
{
	if (XK_equal == button)
	{
		fractal->iterations_def += 10;
		ft_printf("\n🦔  🔢  Iterations: %d (+10) ⬆️\n", fractal->iterations_def);
	}
	else if (XK_minus == button)
	{
		fractal->iterations_def -= 10;
		ft_printf("\n🦔  🔢  Iterations: %d (-10) ⬇️\n", fractal->iterations_def);
	}
	else if (XK_z == button)
		ft_printf("\n🦔  🔍  Zoom level: x%D\n", fractal->zoom_count);
	else if (99 == button)
	{
		color_init(fractal);
		print_color(fractal, 1);
	}
	else if (102 == button)
		(print_color(fractal, 2));
	else if (104 == button)
		print_help();
	return (0);
}

int	key_handler_move(int button, t_fractal *fractal)
{
	if (XK_Escape == button)
		close_handler(fractal);
	if (XK_Left == button || XK_a == button)
		fractal->shift_x -= (0.25 * fractal->zoom);
	else if (XK_Right == button || XK_d == button)
		fractal->shift_x += (0.25 * fractal->zoom);
	else if (XK_Up == button || XK_w == button)
		fractal->shift_y += (0.25 * fractal->zoom);
	else if (XK_Down == button || XK_s == button)
		fractal->shift_y -= (0.25 * fractal->zoom);
	return (0);
}

int	key_handler(int button, t_fractal *fractal)
{
	key_handler_move(button, fractal);
	key_handler_other(button, fractal);
	fractal_render(fractal);
	return (0);
}
