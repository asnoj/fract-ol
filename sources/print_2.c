/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:05:19 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/13 01:24:12 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_header(void)
{
	ft_printf("\n╔══════════════════════════════════════════════════════╗\n");
	ft_printf("║                   🌀  FRACT'OL  🌀                   ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║                  🦔  by jcrochet  🦔                 ║\n");
	ft_printf("╠══════════════════════════════════════════════════════╣\n");
}

void	print_controls(void)
{
	ft_printf("║                                                      ║\n");
	ft_printf("║  🎮  CONTROLS:                                       ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║     ⬆️ ⬇️ ⬅️ ➡️  Arrows/WASD →  Move View            ║\n");
	ft_printf("║     🖱️  Mouse Scroll    →  Zoom In/Out               ║\n");
	ft_printf("║     🖱️  Right-click     →  Show coordinates          ║\n");
	ft_printf("║     ➕  Plus (+)        →  Increase Iterations       ║\n");
	ft_printf("║     ➖  Minus (-)       →  Decrease Iterations       ║\n");
	ft_printf("║     🔍  Z Key           →  Display Zoom Level        ║\n");
	ft_printf("║     🎨  C Key           →  Change Color Palette      ║\n");
	ft_printf("║     🎨  F Key           →  Change Color Fractal      ║\n");
	ft_printf("║     ℹ️  H Key           →  Show Help                 ║\n");
	ft_printf("║     ❌  ESC             →  Exit Program              ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("╠══════════════════════════════════════════════════════╣\n");
}

void	print_fractals(void)
{
	ft_printf("║                                                      ║\n");
	ft_printf("║  🔮  AVAILABLE FRACTALS:                             ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║     • Mandelbrot    →  ./fractol mandelbrot          ║\n");
	ft_printf("║     • Julia         →  ./fractol julia <x> <y>       ║\n");
	ft_printf("║     • Collatz       →  ./fractol collatz             ║\n");
	ft_printf("║     • Burning Ship  →  ./fractol burning_ship        ║\n");
	ft_printf("║     • Celtic        →  ./fractol celtic              ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("╚══════════════════════════════════════════════════════╝\n");
	ft_printf("\n🦔  Rendering fractal... Please wait... \n\n");
}

int	mouse_handler_other_ship(int button, int x, int y, t_fractal *fractal)
{
	double	x_fract;
	double	y_fract;

	if (3 == button)
	{
		x_fract = (map(x, ifm(-2, 1, 0, WIDTH)) * fractal->zoom
				+ fractal->shift_x);
		y_fract = (map(y, ifm(-2, 1, 0, HEIGHT)) * fractal->zoom
				+ fractal->shift_y);
		ft_printf("\n🦔  📍  Click position:\n");
		ft_printf("    Pixel: [%d, %d]\n", x, y);
		ft_printf("    Fractal: [%D, %D]\n", x_fract, y_fract);
	}
	return (0);
}
