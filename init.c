/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabyed <mlabyed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:04:48 by mlabyed           #+#    #+#             */
/*   Updated: 2024/06/07 16:56:38 by mlabyed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractal *fractal, int color, int iter)
{
	unsigned int	*dest;

	dest = fractal->data + ((int)fractal->y * fractal->size_line
			+ (int)fractal->x * (fractal->bpp / 8));
	*dest = color * iter;
}

void	init_connection(t_fractal *fractal)
{
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->max_re = 2;
	fractal->min_re = -2;
	fractal->max_i = 2;
	fractal->min_i = -2;
	fractal->zoom = 1;
	fractal->color.r = 9;
	fractal->color.g = 2;
	fractal->color.b = 9;
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
	{
		free(fractal->mlx);
		exit(1);
	}
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "fractal");
	if (!fractal->win)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(1);
	}
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->data = mlx_get_data_addr(fractal->img, &fractal->bpp,
			&fractal->size_line, &fractal->endian);
}

void	mondelbort(t_fractal *fractal)
{
	fractal->iteration = 0;
	fractal->zr = 0;
	fractal->zi = 0;
	fractal->cr = (fractal->x / WIDTH) * (fractal->max_re - fractal->min_re)
		+ fractal->min_re ;
	fractal->ci = (fractal->y / HEIGHT) * (fractal->min_i - fractal->max_i)
		+ fractal->max_i ;
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

void	draw_mandelbort(t_fractal *fractal)
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
