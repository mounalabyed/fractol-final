/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabyed <mlabyed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:27:36 by mlabyed           #+#    #+#             */
/*   Updated: 2024/06/07 15:28:18 by mlabyed          ###   ########.fr       */
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
	fractal->color.r = 10;
	fractal->color.g = 5;
	fractal->color.b = 1;
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
	{
		free(fractal->mlx);
		exit(1);
	}
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "bonus");
	if (!fractal->win)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(1);
	}
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->data = mlx_get_data_addr(fractal->img, &fractal->bpp,
			&fractal->size_line, &fractal->endian);
}
