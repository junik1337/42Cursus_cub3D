/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:22:45 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/17 12:45:58 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_playerdirection(t_data *data, char c)
{
	if (c == 'N')
		data->p.rotation_angle = (3 * M_PI) / 2;
	else if (c == 'E')
		data->p.rotation_angle = (0 * M_PI);
	else if (c == 'W')
		data->p.rotation_angle = (1 * M_PI);
	else if (c == 'S')
		data->p.rotation_angle = (M_PI) / 2;
}

double	normalizeangle(double angle)
{
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	else if (angle > 2 * M_PI)
		angle = angle - (2 * M_PI);
	return (angle);
}
