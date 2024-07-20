/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabyed <mlabyed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:05:04 by mlabyed           #+#    #+#             */
/*   Updated: 2024/06/01 21:56:40 by mlabyed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_valid_in(int argc, char *argv[])
{
	if (!((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11)) || (argc == 4
				&& !ft_strncmp(argv[1], "julia", 6) && ((is_valid(argv[2])
						&& is_valid(argv[3]))))))
	{
		ft_putstr("invalid input !\ninput must be :\n");
		ft_putstr("for mandelbrot : ./fractol mandelbrot\n");
		ft_putstr("for julia : ./fractol julia");
		ft_putstr(" <double c.real> <double  c.imag>\n");
		exit(0);
	}
	return (1);
}

void	draw_mandelbort_julia(t_fractal *fractal)
{
	mlx_clear_window(fractal->mlx, fractal->win);
	if (!ft_strncmp(fractal->name, "mandelbrot", 11))
		draw_mandelbort(fractal);
	else
		draw_julia(fractal);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (is_valid_in(argc, argv))
	{
		fractal.name = argv[1];
		init_connection(&fractal);
		if (!ft_strncmp(fractal.name, "julia", 6))
		{
			fractal.cr = ft_atof(argv[2]);
			fractal.ci = ft_atof(argv[3]);
		}
		draw_mandelbort_julia(&fractal);
		mlx_key_hook(fractal.win, key_handler, &fractal);
		mlx_mouse_hook(fractal.win, mous, &fractal);
		mlx_hook(fractal.win, 17, 0, ft_closer, &fractal);
		mlx_loop(fractal.mlx);
	}
	return (0);
}
