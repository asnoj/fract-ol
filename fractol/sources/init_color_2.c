/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 06:11:16 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/12 06:26:58 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	color_init_5(t_fractal *fractal)
{
	int	i;

	if (fractal->color_psy != NULL)
		ft_free_tab(fractal->color_psy);
	fractal->color_psy = malloc(sizeof(t_color_psy));
	if (fractal->color_psy == NULL)
		malloc_error();
	i = 0;
	fractal->color_psy->len = 12;
	fractal->color_psy->tab_psy = malloc(12 * sizeof(int));
	if (fractal->color_psy->tab_psy == NULL)
		malloc_error();
	fractal->color_psy->tab_psy[i++] = C5_1;
	fractal->color_psy->tab_psy[i++] = C5_2;
	fractal->color_psy->tab_psy[i++] = C5_3;
	fractal->color_psy->tab_psy[i++] = C5_4;
	fractal->color_psy->tab_psy[i++] = C5_5;
	fractal->color_psy->tab_psy[i++] = C5_6;
	fractal->color_psy->tab_psy[i++] = C5_7;
	fractal->color_psy->tab_psy[i++] = C5_8;
	fractal->color_psy->tab_psy[i++] = C5_9;
	fractal->color_psy->tab_psy[i++] = C5_10;
	fractal->color_psy->tab_psy[i++] = C5_11;
	fractal->color_psy->tab_psy[i++] = C5_12;
	fractal->c = 5;
}

void	color_init_6(t_fractal *fractal)
{
	int	i;

	if (fractal->color_psy != NULL)
		ft_free_tab(fractal->color_psy);
	fractal->color_psy = malloc(sizeof(t_color_psy));
	if (fractal->color_psy == NULL)
		malloc_error();
	i = 0;
	fractal->color_psy->len = 12;
	fractal->color_psy->tab_psy = malloc(12 * sizeof(int));
	if (fractal->color_psy->tab_psy == NULL)
		malloc_error();
	fractal->color_psy->tab_psy[i++] = C6_1;
	fractal->color_psy->tab_psy[i++] = C6_2;
	fractal->color_psy->tab_psy[i++] = C6_3;
	fractal->color_psy->tab_psy[i++] = C6_4;
	fractal->color_psy->tab_psy[i++] = C6_5;
	fractal->color_psy->tab_psy[i++] = C6_6;
	fractal->color_psy->tab_psy[i++] = C6_7;
	fractal->color_psy->tab_psy[i++] = C6_8;
	fractal->color_psy->tab_psy[i++] = C6_9;
	fractal->color_psy->tab_psy[i++] = C6_10;
	fractal->color_psy->tab_psy[i++] = C6_11;
	fractal->color_psy->tab_psy[i++] = C6_12;
	fractal->c = 6;
}

void	color_init_7(t_fractal *fractal)
{
	int	i;

	if (fractal->color_psy != NULL)
		ft_free_tab(fractal->color_psy);
	fractal->color_psy = malloc(sizeof(t_color_psy));
	if (fractal->color_psy == NULL)
		malloc_error();
	i = 0;
	fractal->color_psy->len = 12;
	fractal->color_psy->tab_psy = malloc(12 * sizeof(int));
	if (fractal->color_psy->tab_psy == NULL)
		malloc_error();
	fractal->color_psy->tab_psy[i++] = C7_1;
	fractal->color_psy->tab_psy[i++] = C7_2;
	fractal->color_psy->tab_psy[i++] = C7_3;
	fractal->color_psy->tab_psy[i++] = C7_4;
	fractal->color_psy->tab_psy[i++] = C7_5;
	fractal->color_psy->tab_psy[i++] = C7_6;
	fractal->color_psy->tab_psy[i++] = C7_7;
	fractal->color_psy->tab_psy[i++] = C7_8;
	fractal->color_psy->tab_psy[i++] = C7_9;
	fractal->color_psy->tab_psy[i++] = C7_10;
	fractal->color_psy->tab_psy[i++] = C7_11;
	fractal->color_psy->tab_psy[i++] = C7_12;
	fractal->c = 7;
}

void	color_init_8(t_fractal *fractal)
{
	int	i;

	if (fractal->color_psy != NULL)
		ft_free_tab(fractal->color_psy);
	fractal->color_psy = malloc(sizeof(t_color_psy));
	if (fractal->color_psy == NULL)
		malloc_error();
	i = 0;
	fractal->color_psy->len = 12;
	fractal->color_psy->tab_psy = malloc(12 * sizeof(int));
	if (fractal->color_psy->tab_psy == NULL)
		malloc_error();
	fractal->color_psy->tab_psy[i++] = C8_1;
	fractal->color_psy->tab_psy[i++] = C8_2;
	fractal->color_psy->tab_psy[i++] = C8_3;
	fractal->color_psy->tab_psy[i++] = C8_4;
	fractal->color_psy->tab_psy[i++] = C8_5;
	fractal->color_psy->tab_psy[i++] = C8_6;
	fractal->color_psy->tab_psy[i++] = C8_7;
	fractal->color_psy->tab_psy[i++] = C8_8;
	fractal->color_psy->tab_psy[i++] = C8_9;
	fractal->color_psy->tab_psy[i++] = C8_10;
	fractal->color_psy->tab_psy[i++] = C8_11;
	fractal->color_psy->tab_psy[i++] = C8_12;
	fractal->c = 8;
}
