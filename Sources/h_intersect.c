/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_intersect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:23:27 by aalazhar          #+#    #+#             */
/*   Updated: 2023/01/20 13:39:18 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	upright_hintersect(t_data *data)
{
	data->inter_h.first_y = floor(data->p.pos_y / TILE_SIZE) * TILE_SIZE;
	data->inter_h.first_x = data->p.pos_x
		+ ((data->inter_h.first_y - data->p.pos_y) / tan(data->p.ray_angle));
	data->inter_h.ystep = -TILE_SIZE;
	data->inter_h.xstep = data->inter_h.ystep / tan(data->p.ray_angle);
	if (data->inter_h.xstep < 0)
		data->inter_h.xstep *= -1;
	data->inter_h.x_intersect = data->inter_h.first_x;
	data->inter_h.y_intersect = data->inter_h.first_y;
	while (iswallhited(data->inter_h.x_intersect + 0.00000001,
			data->inter_h.y_intersect - 0.00000001, data) == 0)
	{
		data->inter_h.x_intersect += data->inter_h.xstep;
		data->inter_h.y_intersect += data->inter_h.ystep;
	}
	data->p.h_rayx = data->inter_h.x_intersect;
	data->p.h_rayy = data->inter_h.y_intersect;
	data->p.h_dist = distancebetweenpoints(data->p.pos_x, data->p.pos_y,
			data->p.h_rayx, data->p.h_rayy);
}

void	downright_hintersect(t_data *data)
{
	data->inter_h.first_y = (floor(data->p.pos_y / TILE_SIZE) * TILE_SIZE)
		+ TILE_SIZE;
	data->inter_h.first_x = data->p.pos_x
		+ ((data->inter_h.first_y - data->p.pos_y) / tan(data->p.ray_angle));
	data->inter_h.ystep = TILE_SIZE;
	data->inter_h.xstep = data->inter_h.ystep / tan(data->p.ray_angle);
	if (data->inter_h.xstep < 0)
		data->inter_h.xstep *= -1;
	data->inter_h.x_intersect = data->inter_h.first_x;
	data->inter_h.y_intersect = data->inter_h.first_y;
	while (iswallhited(data->inter_h.x_intersect + 0.00000001,
			data->inter_h.y_intersect + 0.00000001, data) == 0)
	{
		data->inter_h.x_intersect += data->inter_h.xstep;
		data->inter_h.y_intersect += data->inter_h.ystep;
	}
	data->p.h_dist = distancebetweenpoints(data->p.pos_x, data->p.pos_y,
			data->inter_h.x_intersect, data->inter_h.y_intersect);
	data->p.h_rayx = data->inter_h.x_intersect;
	data->p.h_rayy = data->inter_h.y_intersect;
}

void	downleft_hintersect(t_data *data)
{
	data->inter_h.first_y = (floor(data->p.pos_y / TILE_SIZE) * TILE_SIZE)
		+ TILE_SIZE;
	data->inter_h.first_x = data->p.pos_x
		+ ((data->inter_h.first_y - data->p.pos_y) / tan(data->p.ray_angle));
	data->inter_h.ystep = TILE_SIZE;
	data->inter_h.xstep = data->inter_h.ystep / tan(data->p.ray_angle);
	if (data->inter_h.xstep > 0)
		data->inter_h.xstep *= -1;
	data->inter_h.x_intersect = data->inter_h.first_x;
	data->inter_h.y_intersect = data->inter_h.first_y;
	while (iswallhited(data->inter_h.x_intersect - 0.00000001,
			data->inter_h.y_intersect + 0.00000001, data) == 0)
	{
		data->inter_h.x_intersect += data->inter_h.xstep;
		data->inter_h.y_intersect += data->inter_h.ystep;
	}
	data->p.h_dist = distancebetweenpoints(data->p.pos_x, data->p.pos_y,
			data->inter_h.x_intersect, data->inter_h.y_intersect);
	data->p.h_rayx = data->inter_h.x_intersect;
	data->p.h_rayy = data->inter_h.y_intersect;
}

void	upleft_hintersect(t_data *data)
{
	data->inter_h.first_y = (floor(data->p.pos_y / TILE_SIZE) * TILE_SIZE);
	data->inter_h.first_x = data->p.pos_x
		+ ((data->inter_h.first_y - data->p.pos_y) / tan(data->p.ray_angle));
	data->inter_h.ystep = -TILE_SIZE;
	data->inter_h.xstep = data->inter_h.ystep / tan(data->p.ray_angle);
	if (data->inter_h.xstep > 0)
		data->inter_h.xstep *= -1;
	data->inter_h.x_intersect = data->inter_h.first_x;
	data->inter_h.y_intersect = data->inter_h.first_y;
	while (iswallhited(data->inter_h.x_intersect - 0.00000001,
			data->inter_h.y_intersect - 0.00000001, data) == 0)
	{
		data->inter_h.x_intersect += data->inter_h.xstep;
		data->inter_h.y_intersect += data->inter_h.ystep;
	}
	data->p.h_rayx = data->inter_h.x_intersect;
	data->p.h_rayy = data->inter_h.y_intersect;
	data->p.h_dist = distancebetweenpoints(data->p.pos_x, data->p.pos_y,
			data->p.h_rayx, data->p.h_rayy);
}

void	horizontal_intersection(t_data *data)
{
	data->p.ray_angle = normalizeangle(data->p.ray_angle);
	data->p.rotation_angle = normalizeangle(data->p.rotation_angle);
	if ((data->p.ray_angle > (270 * (M_PI / 180))
			&& data->p.ray_angle <= 2 * M_PI))
		upright_hintersect(data);
	else if ((data->p.ray_angle > 0 && data->p.ray_angle <= M_PI / 2))
		downright_hintersect(data);
	else if ((data->p.ray_angle > M_PI / 2 && data->p.ray_angle <= M_PI))
		downleft_hintersect(data);
	else if ((data->p.ray_angle > M_PI && data->p.ray_angle <= (3 *(M_PI / 2))))
		upleft_hintersect(data);
}
