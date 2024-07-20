/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabyed <mlabyed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:30:00 by mlabyed           #+#    #+#             */
/*   Updated: 2024/06/07 20:42:33 by mlabyed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	mondelbort(t_fractal *fractal)
{
	fractal->iteration = 0;
	fractal->zr = 0;
	fractal->zi = 0;
	fractal->cr = (fractal->x / WIDTH) * (fractal->max_re - fractal->min_re)
		+ fractal->min_re + fractal->offset_x;
	fractal->ci = (fractal->y / HEIGHT) * (fractal->min_i - fractal->max_i)
		+ fractal->max_i + fractal->offset_y;
	while (fractal->zr * fractal->zr + fractal->zi * fractal->zi < 4)
	{
		fractal->tmp = -fractal->zi * fractal->zi + fractal->zr * fractal->zr
			+ fractal->cr;
		fractal->zi = 2 * fractal->zr * fractal->zi + fractal->ci;
		fractal->zr = fractal->tmp;
		if (fractal->iteration == 100)
			break ;
		fractal->iteration++;
	}
	if (fractal->iteration == 100)
		my_mlx_pixel_put(fractal, BLACK, fractal->iteration);
	else
	{
		fractal->i = ((fractal->color.r % 256) << 16) | ((fractal->color.g
					% 256) << 8) | (fractal->color.b % 256);
		my_mlx_pixel_put(fractal, fractal->i, fractal->iteration);
	}
}

void	draw_mandelbort_bonus(t_fractal *fractal)
{
	fractal->y = 0;
	while (fractal->y < HEIGHT)
	{
		fractal->x = 0;
		while (fractal->x < WIDTH)
		{
			mondelbort(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
