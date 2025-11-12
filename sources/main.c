/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:46:17 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/13 00:23:31 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_help_header(void)
{
	ft_printf("\n");
	ft_printf("╔══════════════════════════════════════════════════════╗\n");
	ft_printf("║                   📖  HELP MENU  📖                  ║\n");
	ft_printf("╠══════════════════════════════════════════════════════╣\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║  🎮  NAVIGATION:                                     ║\n");
	ft_printf("║     ⬆️ ⬇️ ⬅️ ➡️  / W A S D  →  Move the view         ║\n");
	ft_printf("║     🖱️  Scroll Up/Down    →  Zoom In/Out             ║\n");
	ft_printf("║     🖱️  Right Click       →  Display coordinates     ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║  🎨  RENDERING:                                      ║\n");
	ft_printf("║     + / =  →  Increase iterations (more detail)      ║\n");
	ft_printf("║     -      →  Decrease iterations (faster render)    ║\n");
	ft_printf("║     C      →  Cycle through color palettes           ║\n");
	ft_printf("║     F      →  Toggle fractal background (B/W)        ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║  ℹ️  INFO:                                           ║\n");
	ft_printf("║     Z      →  Display current zoom level             ║\n");
	ft_printf("║     H      →  Show this help menu                    ║\n");
	ft_printf("║                                                      ║\n");
}

void	print_help_footer(void)
{
	ft_printf("║  🔮  FRACTALS AVAILABLE:                             ║\n");
	ft_printf("║     • Mandelbrot    • Julia (needs x y params)       ║\n");
	ft_printf("║     • Collatz       • Burning Ship                   ║\n");
	ft_printf("║     • Celtic                                         ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║  💡  TIPS:                                           ║\n");
	ft_printf("║     • Increase iterations when zooming for details   ║\n");
	ft_printf("║     • Try different palettes for best view           ║\n");
	ft_printf("║     • Right-click to get Julia set coordinates       ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("║  ❌  EXIT:                                           ║\n");
	ft_printf("║     ESC    →  Close the program                      ║\n");
	ft_printf("║                                                      ║\n");
	ft_printf("╚══════════════════════════════════════════════════════╝\n");
	ft_printf("\n");
}

void	print_help(void)
{
	print_help_header();
	print_help_footer();
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (4 == ac && !ft_strncmp(av[1], "julia", 5))
		|| (2 == ac && !ft_strncmp(av[1], "collatz", 7))
		|| (2 == ac && !ft_strncmp(av[1], "burning_ship", 11))
		|| (2 == ac && !ft_strncmp(av[1], "celtic", 6)))
	{
		print_start();
		fractal.name = av[1];
		if (ac == 4)
		{
			fractal.julia_x = char_to_double(av[2]);
			fractal.julia_y = char_to_double(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		print_error();
		exit(EXIT_FAILURE);
	}
}
