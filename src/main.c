/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrankly <rfrankly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:53:30 by rfrankly          #+#    #+#             */
/*   Updated: 2019/10/20 21:16:29 by rfrankly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		check_input(int argc, char **argv, t_all *all)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fractol fractal_name");
		ft_putstr("Choose fractal: julia | mandelbrot | burning_ship | \
celtic_mandelbrot\n");
		exit(-1);
	}
	else
	{
		if (ft_strcmp(argv[1], "julia") && ft_strcmp(argv[1], "mandelbrot") &&\
		ft_strcmp(argv[1], "burning_ship") &&\
		ft_strcmp(argv[1], "celtic_mandelbrot"))
		{
			ft_putstr("Choose fractal: julia | mandelbrot | burning_ship | \
celtic_mandelbrot\n");
			exit(-1);
		}
	}
	if (WIN_HEIGHT != WIN_WIDTH)
	{
		ft_putstr("Height should be equally width!\n");
		exit(-1);
	}
	all->fract_name = argv[1];
	all->color_key = 1;
}

int				main(int argc, char **argv)
{
	t_all *all;

	all = (t_all *)malloc(sizeof(t_all));
	check_input(argc, argv, all);
	init_fract(all);
	all->mlx = mlx_init();
	all->window = mlx_new_window(all->mlx, WIN_WIDTH, WIN_HEIGHT, "fractal");
	all->image = mlx_new_image(all->mlx, WIN_WIDTH, WIN_HEIGHT);
	all->pixels = (int *)mlx_get_data_addr(all->image, &all->img_inf[0],\
					&all->img_inf[1], &all->img_inf[2]);
	create_fract(all);
	mlx_hook(all->window, 2, 0, process_key_press, all);
	mlx_hook(all->window, 4, 0, for_mouse_press, all);
	mlx_hook(all->window, 6, 0, for_mouse_move, all);
	mlx_hook(all->window, 17, 0, process_exit, all);
	mlx_loop(all->mlx);
	return (0);
}
