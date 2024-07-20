/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tchek_argc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabyed <mlabyed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:40:37 by mlabyed           #+#    #+#             */
/*   Updated: 2024/06/07 21:42:12 by mlabyed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	count_point(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	if (count > 1)
		return (0);
	return (1);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (!str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != '.'))
			return (0);
		i++;
	}
	if (str[i - 1] == '.')
		return (0);
	if (!count_point(str))
		return (0);
	return (1);
}
