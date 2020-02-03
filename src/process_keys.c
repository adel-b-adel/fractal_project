/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:45:05 by rfrankly          #+#    #+#             */
/*   Updated: 2019/10/20 20:49:52 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		process_key_press(int key, t_all *all)
{
	if (key == 53)
		process_exit(all);
	if (key == 49)
		all->stop_jul = all->stop_jul ? 0 : 1;
	if (key == NUM_PLUS_ITER && all->fract.iter < 300)
		all->fract.iter += 10;
	if (key == NUM_MINUS_ITER && all->fract.iter >= 30)
		all->fract.iter -= 10;
	if (key == NULL_START)
		init_fract(all);
	if (key == UP_OFFSET_Y || key == DOWN_OFFSET_Y ||\
			key == LEFT_OFFSET_X || key == RIGHT_OFFSET_X)
		process_offset_keys(key, all);
	if (key == NUM_1 || key == NUM_2 || key == NUM_3 || key == NUM_4 ||\
	key == NUM_5)
		process_color_key(key, all);
	create_fract(all);
	return (0);
}

void	process_offset_keys(int key, t_all *all)
{
	all->fract.offset.re = (all->fract.end.re - all->fract.start.re) * 0.05;
	all->fract.offset.im = (all->fract.end.im - all->fract.start.im) * 0.05;
	if (key == UP_OFFSET_Y)
	{
		all->fract.start.im += all->fract.offset.im;
		all->fract.end.im += all->fract.offset.im;
	}
	if (key == DOWN_OFFSET_Y)
	{
		all->fract.start.im -= all->fract.offset.im;
		all->fract.end.im -= all->fract.offset.im;
	}
	if (key == RIGHT_OFFSET_X)
	{
		all->fract.start.re -= all->fract.offset.re;
		all->fract.end.re -= all->fract.offset.re;
	}
	if (key == LEFT_OFFSET_X)
	{
		all->fract.start.re += all->fract.offset.re;
		all->fract.end.re += all->fract.offset.re;
	}
}

void	process_color_key(int key, t_all *all)
{
	if (key == NUM_1)
		all->color_key = 1;
	if (key == NUM_2)
		all->color_key = 2;
	if (key == NUM_3)
		all->color_key = 3;
	if (key == NUM_4)
		all->color_key = 4;
	if (key == NUM_5)
		all->color_key = 5;
}
