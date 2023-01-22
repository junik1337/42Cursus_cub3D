/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalazhar <aalazhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:27:21 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/20 15:59:58 by aalazhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	one_before(char *str, int j)
{
	int		i;

	i = 0;
	while (str[i] && i < j)
	{
		if (str[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	one_after(char *str, int j)
{
	int		i;

	i = j + 1;
	while (str[i])
	{
		if (str[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	one_up(char **str, int i, int j)
{
	while (str[i] && i >= 0)
	{
		if (str[i][j] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	one_down(char **str, int i, int j)
{
	while (str[i])
	{
		if (str[i][j] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	mouse_move(int x, int y, t_data *ray)
{
	static int	old_x;

	if (y < 0 || y > HEIGHT)
		return (0);
	else if (x <= WIDTH && x >= 0 && x < old_x)
		ray->p.rotation_angle -= 0.05;
	else if (x >= 0 && x <= WIDTH && x > old_x)
		ray->p.rotation_angle += 0.05;
	old_x = x;
	if (!(x >= 0 && x <= WIDTH))
		old_x = WIDTH / 2;
	return (0);
}
