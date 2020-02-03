/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:55:00 by rfrankly          #+#    #+#             */
/*   Updated: 2019/10/20 20:08:46 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

typedef enum	e_key
{
	NUM_PLUS_ITER = 69,
	NUM_MINUS_ITER = 78,
	UP_OFFSET_Y = 126,
	DOWN_OFFSET_Y = 125,
	LEFT_OFFSET_X = 123,
	RIGHT_OFFSET_X = 124,
	NULL_START = 82,
	NUM_1 = 83,
	NUM_2 = 84,
	NUM_3 = 85,
	NUM_4 = 86,
	NUM_5 = 87
}				t_key;

typedef struct	s_point
{
	long double re;
	long double im;
}				t_point;

typedef struct	s_mouse
{
	int			x;
	int			y;
}				t_mouse;

typedef struct	s_fract
{
	t_point		start;
	t_point		end;
	t_point		c;
	t_point		z;
	t_point		zoom;
	t_point		offset;
	long double min;
	long double max;
	int			iter;

}				t_fract;
typedef struct	s_all
{
	char		*fract_name;
	int			curr_fract;
	void		*mlx;
	void		*window;
	void		*image;
	int			img_inf[3];
	int			*pixels;
	t_fract		fract;
	t_mouse		mouse;
	int			stop_jul;
	int			color_key;
}				t_all;

/*
**	for_all_fractals.c
*/

void			init_fract(t_all *all);
void			create_fract(t_all *all);
int				color(int i, t_all *all);

/*
**	exit.c
*/

int				process_exit(t_all *all);

/*
**	process_keys.c
*/

int				process_key_press(int key, t_all *all);
void			process_offset_keys(int key, t_all *all);
void			process_color_key(int key, t_all *all);

/*
**	mouse.c
*/

int				for_mouse_press(int button, int x, int y, t_all *all);
void			for_mouse_zoom(int button, t_all *all);
int				for_mouse_move(int x, int y, t_all *all);

/*
**	create_mandelbrot.c
*/
void			init_mandelbrot(t_all *all);
void			draw_mandelbrot(t_all *all);
int				check_mbr_point(t_all *all);

/*
**	create_julia.c
*/

void			init_julia(t_all *all);
void			draw_julia(t_all *all);
int				check_julia_point(t_all *all, t_point z);
void			find_c_for_julia\
				(t_all *all, long double step_x, long double step_y);

/*
**	create_burning_ship.c
*/

void			init_burning_ship(t_all *all);
void			draw_burning_ship(t_all *all);
int				check_bship_point(t_all *all);

/*
**	create_celtic_mandelbrot.c
*/

void			init_celtic_mandelbrot(t_all *all);
void			draw_celtic_mandelbrot(t_all *all);
int				check_celt_mbr_point(t_all *all);

#endif
