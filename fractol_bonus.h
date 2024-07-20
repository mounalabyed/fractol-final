/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabyed <mlabyed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:04:42 by mlabyed           #+#    #+#             */
/*   Updated: 2024/06/07 21:41:35 by mlabyed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 1000
# define HEIGHT 1000
# define BLACK 0x000000

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct s_fractal
{
	double			offset_x;
	double			offset_y;
	void			*mlx;
	void			*win;
	void			*data;
	int				iteration;
	char			*name;
	double			max_re;
	double			min_re;
	double			max_i;
	double			min_i;
	double			cr;
	double			ci;
	double			x;
	double			y;
	void			*img;
	int				bpp;
	int				size_line;
	int				endian;
	t_color			color;
	double			zoom;
	int				color_b;
	unsigned int	i;
	double			tmp;
	double			zr;
	double			zi;
}					t_fractal;

typedef struct vars
{
	int				i;
	double			nb;
	int				s;
	int				k;
}					t_vars;

int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				my_mlx_pixel_put(t_fractal *fractal, int color, int iter);
void				init_connection(t_fractal *fractal);
double				ft_atof(char *str);
int					ft_closer(t_fractal *fractal);
void				ft_putstr(char *s);
int					key_handler(int key, t_fractal *fractal);
void				initialize_variables(t_vars *vars);
int					mous(int key, int x, int y, t_fractal *fractal);
int					is_valid(char *str);
void				draw_burningship(t_fractal *fractal);
void				draw_julia_bonus(t_fractal *fractal);
void				draw_mandelbort_bonus(t_fractal *fractal);
void				draw_fractal_bonus(t_fractal *fractal);
int					valid_arg(int ac, char **av);
void				my_mlx_pixel_put(t_fractal *fractal, int color, int iter);

#endif
