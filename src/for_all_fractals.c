/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_all_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:07:48 by rfrankly          #+#    #+#             */
/*   Updated: 2019/10/20 20:39:10 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fract(t_all *all)
{
	if (ft_strcmp(all->fract_name, "mandelbrot") == 0)
		init_mandelbrot(all);
	if (ft_strcmp(all->fract_name, "julia") == 0)
		init_julia(all);
	if (ft_strcmp(all->fract_name, "burning_ship") == 0)
		init_burning_ship(all);
	if (ft_strcmp(all->fract_name, "celtic_mandelbrot") == 0)
		init_celtic_mandelbrot(all);
}

void	create_fract(t_all *all)
{
	if (all->curr_fract == 1)
		draw_mandelbrot(all);
	if (all->curr_fract == 2)
		draw_julia(all);
	if (all->curr_fract == 3)
		draw_burning_ship(all);
	if (all->curr_fract == 4)
		draw_celtic_mandelbrot(all);
}

int		color(int i, t_all *all)
{
	if (all->color_key == 1)
		return (((i * 140 / 100) << 8) + ((i * 255 / 100) << 8) +\
		i * 105 / 100);
	else if (all->color_key == 2)
		return (((i * 255 / 10) << 16) + ((i * 255 / 10) << 8) + i * 25 / 10);
	else if (all->color_key == 3)
		return (((i * 255 / 40) << 16) + ((i * 255 / 10) << 8) + i * 255 / 300);
	else if (all->color_key == 4)
		return (((i * 80 / 100) << 8) + ((i * 255 / 100) << 16) +\
		i * 145 / 100);
	else if (all->color_key == 5)
		return (((i * 255 / 100) << 2) + ((i * 255 / 100) << 16) +\
		i * 255 / 100);
	else
		return (((i * 140 / 100) << 8) + ((i * 255 / 100) << 8) +\
		i * 105 / 100);
}
