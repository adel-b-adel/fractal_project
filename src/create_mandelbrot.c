/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:45:59 by rfrankly          #+#    #+#             */
/*   Updated: 2019/10/20 20:33:49 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_all *all)
{
	all->curr_fract = 1;
	all->fract.start.re = (long double)-2.0;
	all->fract.end.re = (long double)2.0;
	all->fract.start.im = (long double)-2.0;
	all->fract.end.im = (long double)2.0;
	all->fract.iter = 30;
	all->fract.zoom.re = (all->fract.end.re - all->fract.start.re) * 0.5;
	all->fract.zoom.im = (all->fract.end.im - all->fract.start.im) * 0.5;
}

void	draw_mandelbrot(t_all *all)
{
	int			x;
	int			y;
	long double step_x;
	long double step_y;

	y = 0;
	step_x = (all->fract.end.re - all->fract.start.re) / WIN_WIDTH;
	step_y = (all->fract.end.im - all->fract.start.im) / WIN_HEIGHT;
	all->fract.c.im = all->fract.start.im;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		all->fract.c.re = all->fract.start.re;
		while (x < WIN_WIDTH)
		{
			all->pixels[x + y * WIN_WIDTH] = check_mbr_point(all);
			x++;
			all->fract.c.re += step_x;
		}
		y++;
		all->fract.c.im += step_y;
	}
	mlx_put_image_to_window(all->mlx, all->window, all->image, 0, 0);
}

int		check_mbr_point(t_all *all)
{
	int			i;
	long double tmp_z_re;
	t_point		z;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (z.re * z.re + z.im * z.im < 4 && i < all->fract.iter)
	{
		tmp_z_re = z.re;
		z.re = all->fract.c.re + z.re * z.re - z.im * z.im;
		z.im = all->fract.c.im + 2 * tmp_z_re * z.im;
		i++;
	}
	return (color(i, all));
}
