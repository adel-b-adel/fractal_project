/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:52:44 by rfrankly          #+#    #+#             */
/*   Updated: 2019/10/20 20:46:40 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		for_mouse_press(int button, int x, int y, t_all *all)
{
	for_mouse_zoom(button, all);
	create_fract(all);
	y += 0;
	x += 0;
	return (1);
}

void	for_mouse_zoom(int button, t_all *all)
{
	if (button == 4 || button == 1)
	{
		all->fract.zoom.re = (all->fract.end.re - all->fract.start.re) * 0.05;
		all->fract.zoom.im = (all->fract.end.im - all->fract.start.im) * 0.05;
		all->fract.start.re -= all->fract.zoom.re;
		all->fract.end.re += all->fract.zoom.re;
		all->fract.start.im -= all->fract.zoom.im;
		all->fract.end.im += all->fract.zoom.im;
	}
	if (button == 5 || button == 2)
	{
		all->fract.zoom.re = (all->fract.end.re - all->fract.start.re) * 0.05;
		all->fract.zoom.im = (all->fract.end.im - all->fract.start.im) * 0.05;
		all->fract.start.re += all->fract.zoom.re;
		all->fract.end.re -= all->fract.zoom.re;
		all->fract.start.im += all->fract.zoom.im;
		all->fract.end.im -= all->fract.zoom.im;
	}
}

int		for_mouse_move(int x, int y, t_all *all)
{
	if (all->curr_fract == 2 && !all->stop_jul)
	{
		all->mouse.x = x;
		all->mouse.y = y;
		create_fract(all);
	}
	return (0);
}
