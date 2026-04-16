/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:03:47 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/13 00:15:41 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_palette(t_fractal *fractal)
{
	if (fractal->c == 1)
		ft_printf("\n🦔  🎨  Fluorescent Electric 💚\n");
	else if (fractal->c == 2)
		ft_printf("\n🦔  🎨  Metallic Steel 🔷\n");
	else if (fractal->c == 3)
		ft_printf("\n🦔  🎨  Fire Gradient 🔥\n");
	else if (fractal->c == 4)
		ft_printf("\n🦔  🎨  Purple Dream 💜\n");
	else if (fractal->c == 5)
		ft_printf("\n🦔  🎨  Psychedelic Trip 🌀\n");
	else if (fractal->c == 6)
		ft_printf("\n🦔  🎨  Acid Rainbow 🎨\n");
	else if (fractal->c == 7)
		ft_printf("\n🦔  🎨  Sunset Dream 🌸\n");
	else if (fractal->c == 8)
		ft_printf("\n🦔  🎨  Neon City 🎭\n");
}

void	print_color(t_fractal *fractal, int n)
{
	if (n == 1)
	{
		print_palette(fractal);
	}
	if (n == 2)
	{
		if (fractal->f_color == COLOR_WHITE)
		{
			fractal->f_color = COLOR_BLACK;
			ft_printf("\n🦔  🎨  Color Fractal: BLACK 🖤\n");
		}
		else if (fractal->f_color == COLOR_BLACK)
		{
			fractal->f_color = COLOR_WHITE;
			ft_printf("\n🦔  🎨  Color Fractal: WHITE 🤍\n");
		}
	}
}

void	print_start(void)
{
	print_header();
	print_controls();
	print_fractals();
}

void	print_error(void)
{
	ft_printf("\n╔══════════════════════════════════════════════════════╗\n");
	ft_printf("║                   🌀  FRACT'OL  🌀                   ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║                  🦔  by jcrochet  🦔                 ║\n");
	ft_printf("╠══════════════════════════════════════════════════════╣\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║  ❌  ERROR: Invalid parameters!                      ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║  🔮  AVAILABLE FRACTALS:                             ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║     • Mandelbrot    →  ./fractol mandelbrot          ║\n");
	ft_printf("║     • Julia         →  ./fractol julia <x> <y>       ║\n");
	ft_printf("║     • Collatz       →  ./fractol collatz             ║\n");
	ft_printf("║     • Burning Ship  →  ./fractol burning_ship        ║\n");
	ft_printf("║     • Celtic        →  ./fractol celtic              ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("╚══════════════════════════════════════════════════════╝\n\n");
}
