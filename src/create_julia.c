/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:49:29 by rfrankly          #+#    #+#             */
/*   Updated: 2019/10/20 21:30:16 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_all *all)
{
	all->curr_fract = 2;
	all->fract.start.re = (long double)-2.0;
	all->fract.end.re = (long double)2.0;
	all->fract.start.im = (long double)-2.0;
	all->fract.end.im = (long double)2.0;
	all->fract.iter = 30;
	all->fract.zoom.re = (all->fract.end.re - all->fract.start.re) * 0.5;
	all->fract.zoom.im = (all->fract.end.im - all->fract.start.im) * 0.5;
	all->mouse.x = 0;
	all->mouse.y = 0;
	all->stop_jul = 0;
}

void	draw_julia(t_all *all)
{
	int			x;
	int			y;
	long double step_x;
	long double step_y;
	t_point		z;

	z.re = 0;
	z.im = 0;
	y = -1;
	step_x = (all->fract.end.re - all->fract.start.re) / WIN_WIDTH;
	step_y = (all->fract.end.im - all->fract.start.im) / WIN_HEIGHT;
	find_c_for_julia(all, step_x, step_y);
	z.im = all->fract.start.im;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		z.re = all->fract.start.re;
		while (++x < WIN_WIDTH)
		{
			all->pixels[x + y * WIN_WIDTH] = check_julia_point(all, z);
			z.re += step_x;
		}
		z.im += step_y;
	}
	mlx_put_image_to_window(all->mlx, all->window, all->image, 0, 0);
}

int		check_julia_point(t_all *all, t_point z)
{
	int			i;
	long double tmp_z_re;

	i = 0;
	while (z.re * z.re + z.im * z.im < 4 && i < all->fract.iter)
	{
		tmp_z_re = z.re;
		z.re = all->fract.c.re + z.re * z.re - z.im * z.im;
		z.im = all->fract.c.im + 2 * tmp_z_re * z.im;
		i++;
	}
	return (color(i, all));
}

void	find_c_for_julia(t_all *all, long double step_x, long double step_y)
{
	if (!all->stop_jul)
	{
		all->fract.c.re = all->fract.start.re + all->mouse.x * step_x;
		all->fract.c.im = all->fract.start.im + all->mouse.y * step_y;
	}
}
