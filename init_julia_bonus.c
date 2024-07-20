/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabyed <mlabyed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:29:04 by mlabyed           #+#    #+#             */
/*   Updated: 2024/06/07 21:02:22 by mlabyed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <string.h>

void	julia(t_fractal *fractal)
{
	double	zr;
	double	zi;

	fractal->iteration = 0;
	zr = (fractal->x / WIDTH) * (fractal->max_re - fractal->min_re)
		+ fractal->min_re + fractal->offset_x;
	zi = (-fractal->y / HEIGHT) * (fractal->max_i - fractal->min_i)
		+ fractal->max_i + fractal->offset_y;
	while (zr * zr + zi * zi < 4)
	{
		fractal->tmp = -zi * zi + zr * zr + fractal->cr;
		zi = 2 * zr * zi + fractal->ci;
		zr = fractal->tmp;
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

void	draw_julia_bonus(t_fractal *fractal)
{
	fractal->y = 0;
	while (fractal->y < 1000)
	{
		fractal->x = 0;
		while (fractal->x < 1000)
		{
			julia(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
