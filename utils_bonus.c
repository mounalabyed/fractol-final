/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabyed <mlabyed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:05:14 by mlabyed           #+#    #+#             */
/*   Updated: 2024/06/01 22:39:58 by mlabyed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*k;
	unsigned char	*y;
	size_t			i;

	k = (unsigned char *)s1;
	y = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n && (k[i] || y[i]))
	{
		if (k[i] != y[i])
			return (k[i] - y[i]);
		i++;
	}
	return (0);
}

void	initialize_variables(t_vars *vars)
{
	vars->i = 0;
	vars->nb = 0;
	vars->s = 1;
	vars->k = 0;
}

double	ft_atof(char *str)
{
	t_vars	var;

	initialize_variables(&var);
	while ((str[var.i] >= 9 && str[var.i] <= 13) || str[var.i] == ' ')
		var.i++;
	if (str[var.i] == '+' || str[var.i] == '-')
	{
		if (str[var.i] == '-')
			var.s = -1;
		var.i++;
	}
	while (str[var.i] && str[var.i] >= 48 && str[var.i] <= 57)
		var.nb = var.nb * 10 + (str[var.i++] - 48);
	if (str[var.i] == '.')
	{
		var.i++;
		while (str[var.i] && str[var.i] >= 48 && str[var.i] <= 57)
		{
			var.nb = var.nb * 10 + (str[var.i++] - 48);
			var.k++;
		}
	}
	while (var.k-- > 0)
		var.nb = var.nb / 10;
	return (var.nb * var.s);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
