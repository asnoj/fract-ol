/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:07:21 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/12 06:30:09 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	color_init(t_fractal *fractal)
{
	if (fractal->c == 1)
		color_init_2(fractal);
	else if (fractal->c == 2)
		color_init_3(fractal);
	else if (fractal->c == 3)
		color_init_4(fractal);
	else if (fractal->c == 4)
		color_init_5(fractal);
	else if (fractal->c == 5)
		color_init_6(fractal);
	else if (fractal->c == 6)
		color_init_7(fractal);
	else if (fractal->c == 7)
		color_init_8(fractal);
	else if (fractal->c == 8)
		color_init_1(fractal);
}

// 🌈 PALETTE 1 - Fluorescent Electric (12 couleurs)
#define C1_1  0xFF00FF  // Magenta fluo
#define C1_2  0x00FFFF  // Cyan électrique
#define C1_3  0x00FF00  // Vert néon
#define C1_4  0xFFFF00  // Jaune vif
#define C1_5  0xFF6600  // Orange fluo
#define C1_6  0xFF0000  // Rouge intense
#define C1_7  0x0000FF  // Bleu électrique
#define C1_8  0xFF1493  // Rose vif
#define C1_9  0x7FFF00  // Chartreuse
#define C1_10 0xFF00AA  // Rose shocking
#define C1_11 0x00AAFF  // Bleu ciel fluo
#define C1_12 0xAAFF00  // Vert lime électrique

// 🔷 PALETTE 2 - Metallic Steel (12 couleurs)
#define C2_1  0x0D1B2A  // Bleu nuit
#define C2_2  0x1B263B  // Bleu acier
#define C2_3  0x415A77  // Gris bleuté
#define C2_4  0x778DA9  // Bleu argenté
#define C2_5  0xA9BCD0  // Gris clair
#define C2_6  0xE0E1DD  // Blanc cassé
#define C2_7  0x1E90FF  // Bleu vif
#define C2_8  0x4682B4  // Bleu acier doux
#define C2_9  0x5F9EA0  // Cadet blue
#define C2_10 0x87CEEB  // Sky blue
#define C2_11 0xB0C4DE  // Light steel blue
#define C2_12 0xC0C0C0  // Argent

// 🔥 PALETTE 3 - Fire Gradient (12 couleurs)
#define C3_1  0x330000  // Rouge sombre
#define C3_2  0x661111  // Rouge profond
#define C3_3  0x993300  // Brique chaude
#define C3_4  0xCC6600  // Orange brûlé
#define C3_5  0xFF9900  // Orange vif
#define C3_6  0xFFCC00  // Jaune chaud
#define C3_7  0xFFFF66  // Jaune clair
#define C3_8  0xFFFFFF  // Blanc intense
#define C3_9  0xFF3300  // Rouge orangé
#define C3_10 0xFF6633  // Orange flamme
#define C3_11 0xFFAA00  // Ambre
#define C3_12 0xFFDD88  // Crème dorée

// 💜 PALETTE 4 - Purple Dream (12 couleurs)
#define C4_1  0x4B0082  // Indigo profond
#define C4_2  0x8B00FF  // Violet électrique
#define C4_3  0xDA70D6  // Orchidée
#define C4_4  0xFF00FF  // Magenta pur
#define C4_5  0xFF1493  // Rose profond
#define C4_6  0xFF69B4  // Rose chaud
#define C4_7  0xFFB6C1  // Rose clair
#define C4_8  0xE6E6FA  // Lavande
#define C4_9  0x9370DB  // Violet medium
#define C4_10 0xBA55D3  // Orchidée medium
#define C4_11 0xEE82EE  // Violet clair
#define C4_12 0xDDA0DD  // Prune

// 🌀 PALETTE 5 - Psychedelic Trip (TOTAL PSYCHÉ!)
#define C5_1  0xFF00FF  // Magenta intense
#define C5_2  0x00FF00  // Vert néon
#define C5_3  0xFF0080  // Rose shocking
#define C5_4  0x0080FF  // Bleu électrique
#define C5_5  0xFFFF00  // Jaune laser
#define C5_6  0xFF6600  // Orange radioactif
#define C5_7  0x00FFFF  // Cyan fluo
#define C5_8  0xFF00AA  // Fuchsia explosif
#define C5_9  0x80FF00  // Vert acide
#define C5_10 0xAA00FF  // Violet psyché
#define C5_11 0xFF0040  // Rouge néon
#define C5_12 0x00AAFF  // Bleu azur fluo

// 🎨 PALETTE 6 - Acid Rainbow (ULTRA PSYCHÉ!)
#define C6_1  0xFF1493  // Rose shocking
#define C6_2  0xFF00FF  // Magenta pur
#define C6_3  0xAA00FF  // Violet intense
#define C6_4  0x0000FF  // Bleu pur
#define C6_5  0x00FFFF  // Cyan explosif
#define C6_6  0x00FF00  // Vert laser
#define C6_7  0xFFFF00  // Jaune néon
#define C6_8  0xFF6600  // Orange fluo
#define C6_9  0xFF0000  // Rouge intense
#define C6_10 0xFF0080  // Rose électrique
#define C6_11 0x7FFF00  // Chartreuse acide
#define C6_12 0xFF00AA  // Fuchsia fluo

// 🌸 PALETTE 7 - Sunset Dream (12 couleurs)
#define C7_1  0x2B0A3D  // Violet nuit
#define C7_2  0x59057B  // Violet profond
#define C7_3  0x8B1E3F  // Bordeaux
#define C7_4  0xC73E1D  // Rouge orangé
#define C7_5  0xF26430  // Orange sunset
#define C7_6  0xFF8C42  // Orange pêche
#define C7_7  0xFFB997  // Rose saumon
#define C7_8  0xFFDCCC  // Rose pâle
#define C7_9  0xA0153E  // Bourgogne
#define C7_10 0xE85D75  // Rose corail
#define C7_11 0xFFAA80  // Pêche
#define C7_12 0xFFE5E0  // Rose nude

// 🎭 PALETTE 8 - Neon City (12 couleurs)
#define C8_1  0x0A0E27  // Bleu nuit urbain
#define C8_2  0x1B1464  // Bleu électrique sombre
#define C8_3  0x7209B7  // Violet néon
#define C8_4  0xB5179E  // Magenta néon
#define C8_5  0xF72585  // Rose néon
#define C8_6  0xFF006E  // Rose shocking
#define C8_7  0xFF4D8A  // Rose fluo
#define C8_8  0xFFB3D9  // Rose pastel néon
#define C8_9  0x560BAD  // Violet profond
#define C8_10 0x9D4EDD  // Violet néon clair
#define C8_11 0xFF5FAA  // Rose bubble gum
#define C8_12 0xFFC0E5  // Rose candy

void	color_init_1(t_fractal *fractal)
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
	fractal->color_psy->tab_psy[i++] = C1_1;
	fractal->color_psy->tab_psy[i++] = C1_2;
	fractal->color_psy->tab_psy[i++] = C1_3;
	fractal->color_psy->tab_psy[i++] = C1_4;
	fractal->color_psy->tab_psy[i++] = C1_5;
	fractal->color_psy->tab_psy[i++] = C1_6;
	fractal->color_psy->tab_psy[i++] = C1_7;
	fractal->color_psy->tab_psy[i++] = C1_8;
	fractal->color_psy->tab_psy[i++] = C1_9;
	fractal->color_psy->tab_psy[i++] = C1_10;
	fractal->color_psy->tab_psy[i++] = C1_11;
	fractal->color_psy->tab_psy[i++] = C1_12;
	fractal->c = 1;
}

void	color_init_2(t_fractal *fractal)
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
	fractal->color_psy->tab_psy[i++] = C2_1;
	fractal->color_psy->tab_psy[i++] = C2_2;
	fractal->color_psy->tab_psy[i++] = C2_3;
	fractal->color_psy->tab_psy[i++] = C2_4;
	fractal->color_psy->tab_psy[i++] = C2_5;
	fractal->color_psy->tab_psy[i++] = C2_6;
	fractal->color_psy->tab_psy[i++] = C2_7;
	fractal->color_psy->tab_psy[i++] = C2_8;
	fractal->color_psy->tab_psy[i++] = C2_9;
	fractal->color_psy->tab_psy[i++] = C2_10;
	fractal->color_psy->tab_psy[i++] = C2_11;
	fractal->color_psy->tab_psy[i++] = C2_12;
	fractal->c = 2;
}

void	color_init_3(t_fractal *fractal)
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
	fractal->color_psy->tab_psy[i++] = C3_1;
	fractal->color_psy->tab_psy[i++] = C3_2;
	fractal->color_psy->tab_psy[i++] = C3_3;
	fractal->color_psy->tab_psy[i++] = C3_4;
	fractal->color_psy->tab_psy[i++] = C3_5;
	fractal->color_psy->tab_psy[i++] = C3_6;
	fractal->color_psy->tab_psy[i++] = C3_7;
	fractal->color_psy->tab_psy[i++] = C3_8;
	fractal->color_psy->tab_psy[i++] = C3_9;
	fractal->color_psy->tab_psy[i++] = C3_10;
	fractal->color_psy->tab_psy[i++] = C3_11;
	fractal->color_psy->tab_psy[i++] = C3_12;
	fractal->c = 3;
}

void	color_init_4(t_fractal *fractal)
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
	fractal->color_psy->tab_psy[i++] = C4_1;
	fractal->color_psy->tab_psy[i++] = C4_2;
	fractal->color_psy->tab_psy[i++] = C4_3;
	fractal->color_psy->tab_psy[i++] = C4_4;
	fractal->color_psy->tab_psy[i++] = C4_5;
	fractal->color_psy->tab_psy[i++] = C4_6;
	fractal->color_psy->tab_psy[i++] = C4_7;
	fractal->color_psy->tab_psy[i++] = C4_8;
	fractal->color_psy->tab_psy[i++] = C4_9;
	fractal->color_psy->tab_psy[i++] = C4_10;
	fractal->color_psy->tab_psy[i++] = C4_11;
	fractal->color_psy->tab_psy[i++] = C4_12;
	fractal->c = 4;
}
