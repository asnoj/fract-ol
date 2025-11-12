/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:46:28 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/13 00:23:01 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "color_init.h"
# include "ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define PI 3.14159265358979323846

typedef struct s_img
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;

// color struct

typedef struct s_color_psys
{
	int			*tab_psy;
	int			len;
}				t_color_psy;

typedef struct s_fractal
{
	char		*name;
	double		shift_x;
	double		shift_y;

	t_color_psy	*color_psy;
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	double		escape_value;
	int			iterations_def;
	double		zoom;
	double		zoom_count;
	double		julia_x;
	double		julia_y;
	double		x;
	double		y;
	int			c;
	int			f_color;
}				t_fractal;

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_maparg
{
	double		new_min;
	double		new_max;
	double		old_min;
	double		old_max;
}				t_maparg;

// math //

double			map(double unscaled_num, t_maparg *arg);
t_complex		square_complex(t_complex z);
t_complex		sum_complex(t_complex z1, t_complex z2);
double			char_to_double(char *s);
t_complex		collatz_complex(t_complex z);
int				get_color_log(int i, t_fractal *fractal);

// init //

void			events_init(t_fractal *fractal);
int				close_window(int key, t_fractal *fractal);
int				mouse_zoom(int button, int x, int y, t_fractal *fractal);
int				key_event(int key, t_fractal *fractal);
void			ft_move_minmax(int val, t_fractal *fractal, int move);

void			malloc_error(void);
void			data_init(t_fractal *fractal);
void			fractal_init(t_fractal *fractal);
t_maparg		*ifm(double new_min, double new_max, double old_min,
					double old_max);

void			color_init(t_fractal *fractal);
void			color_init_1(t_fractal *fractal);
void			color_init_2(t_fractal *fractal);
void			color_init_3(t_fractal *fractal);
void			color_init_4(t_fractal *fractal);
void			color_init_5(t_fractal *fractal);
void			color_init_6(t_fractal *fractal);
void			color_init_7(t_fractal *fractal);
void			color_init_8(t_fractal *fractal);

// render //

void			handle_pixel_mandelbrot(int x, int y, t_fractal *fractal);
void			handle_pixel(int x, int y, t_fractal *fractal);
void			my_pixel_put(int x, int y, t_img *img, int color);
void			fractal_render(t_fractal *fractal);
void			handle_pixel_ship(int x, int y, t_fractal *fractal);
void			handle_pixel_celtic(int x, int y, t_fractal *fractal);

// event

int				close_handler(t_fractal *fractal);
int				key_handler(int keysym, t_fractal *fractal);
int				mouse_handler(int button, int x, int y, t_fractal *fractal);
int				mouse_handler_other_ship(int button, int x, int y,
					t_fractal *fractal);

// print

void			print_color(t_fractal *fractal, int n);
void			print_error(void);
void			print_start(void);
void			print_color(t_fractal *fractal, int n);
void			print_header(void);
void			print_controls(void);
void			print_fractals(void);
void			print_help(void);

// free

void			ft_free_tab(t_color_psy *psy);

#endif