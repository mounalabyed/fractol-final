/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabyed <mlabyed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:04:59 by mlabyed           #+#    #+#             */
/*   Updated: 2024/06/07 15:39:42 by mlabyed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_closer(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
}

int	mous(int key, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (key == 5)
	{
		fractal->zoom *= 1.1;
		fractal->max_i *= 1.1;
		fractal->max_re *= 1.1;
		fractal->min_i *= 1.1;
		fractal->min_re *= 1.1;
		draw_mandelbort_julia(fractal);
	}
	else if (key == 4)
	{
		fractal->zoom /= 1.1;
		fractal->max_i /= 1.1;
		fractal->max_re /= 1.1;
		fractal->min_i /= 1.1;
		fractal->min_re /= 1.1;
		draw_mandelbort_julia(fractal);
	}
	return (0);
}

void	change_color(int key, t_fractal *fractal)
{
	if (key == 65436)
	{
		fractal->color.r += 2;
		fractal->color.g += 10;
		fractal->color.b += 8;
	}
	if (key == 65433)
	{
		fractal->color.r += 6;
		fractal->color.g += 2;
		fractal->color.b += 2;
	}
	if (key == 65437)
	{
		fractal->color.r += 6;
		fractal->color.g += 6;
		fractal->color.b += 6;
	}
	if (key == 65430)
	{
		fractal->color.r += 10;
		fractal->color.g += 10;
		fractal->color.b += 10;
	}
}

int	key_handler(int key, t_fractal *fractal)
{
	if (key == 65307)
		ft_closer(fractal);
	if (key == 65436 || key == 65430 || key == 65433 || key == 65437)
	{
		change_color(key, fractal);
	}
	draw_mandelbort_julia(fractal);
	return (0);
}
