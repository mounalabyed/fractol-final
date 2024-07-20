/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burninship_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabyed <mlabyed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:34:03 by mlabyed           #+#    #+#             */
/*   Updated: 2024/06/06 22:17:22 by mlabyed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	valid_arg(int ac, char **av)
{
	if (!((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11)) || (ac == 4
				&& !ft_strncmp(av[1], "julia", 6)) || (ac == 2
				&& !ft_strncmp(av[1], "burningship", 12))) || (ac == 4
			&& (!is_valid(av[2]) || !is_valid(av[3]))))
	{
		ft_putstr("invalid input must be :\n");
		ft_putstr("for mandelbrot : ./fractol_bonus mandelbrot\n");
		ft_putstr("for julia : ./fractol_bonus julia");
		ft_putstr(" <float c_real> <float c_imag>\n");
		ft_putstr("for burningship : ./fractol_bonus burningship\n");
		exit(1);
	}
	return (1);
}

void	draw_fractal_bonus(t_fractal *fractal)
{
	mlx_clear_window(fractal->mlx, fractal->win);
	if (!ft_strncmp(fractal->name, "mandelbrot", 11))
		draw_mandelbort_bonus(fractal);
	else if (!ft_strncmp(fractal->name, "julia", 11))
		draw_julia_bonus(fractal);
	else
		draw_burningship(fractal);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (valid_arg(ac, av))
	{
		fractal.name = av[1];
		init_connection(&fractal);
		if (!ft_strncmp(fractal.name, "julia", 6))
		{
			fractal.cr = ft_atof(av[2]);
			fractal.ci = ft_atof(av[3]);
		}
		draw_fractal_bonus(&fractal);
		mlx_key_hook(fractal.win, key_handler, &fractal);
		mlx_mouse_hook(fractal.win, mous, &fractal);
		mlx_hook(fractal.win, 17, 0, ft_closer, &fractal);
		mlx_loop(fractal.mlx);
	}
	return (0);
}
