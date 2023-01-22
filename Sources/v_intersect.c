/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_intersect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:22:03 by aalazhar          #+#    #+#             */
/*   Updated: 2023/01/20 13:39:28 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	upright_vintersect(t_data *data)
{
	data->inter_v.first_x = floor(data->p.pos_x / TILE_SIZE)
		* TILE_SIZE + TILE_SIZE;
	data->inter_v.first_y = data->p.pos_y
		+ ((data->inter_v.first_x - data->p.pos_x) * tan(data->p.ray_angle));
	data->inter_v.xstep = TILE_SIZE;
	data->inter_v.ystep = data->inter_v.xstep * tan(data->p.ray_angle);
	if (data->inter_v.ystep > 0)
		data->inter_v.ystep *= -1;
	data->inter_v.x_intersect = data->inter_v.first_x;
	data->inter_v.y_intersect = data->inter_v.first_y;
	while (iswallhited(data->inter_v.x_intersect + 0.00000001,
			data->inter_v.y_intersect - 0.00000001, data) == 0)
	{
		data->inter_v.x_intersect += data->inter_v.xstep;
		data->inter_v.y_intersect += data->inter_v.ystep;
	}
	data->p.v_dist = distancebetweenpoints(data->p.pos_x, data->p.pos_y,
			data->inter_v.x_intersect, data->inter_v.y_intersect);
	data->p.v_rayx = data->inter_v.x_intersect;
	data->p.v_rayy = data->inter_v.y_intersect;
}

void	downright_vintersect(t_data *data)
{
	data->inter_v.first_x = (floor(data->p.pos_x / TILE_SIZE) * TILE_SIZE)
		+ TILE_SIZE;
	data->inter_v.first_y = data->p.pos_y
		+ ((data->inter_v.first_x - data->p.pos_x) * tan(data->p.ray_angle));
	data->inter_v.xstep = TILE_SIZE;
	data->inter_v.ystep = data->inter_v.xstep * tan(data->p.ray_angle);
	if (data->inter_v.ystep < 0)
		data->inter_v.ystep *= -1;
	data->inter_v.x_intersect = data->inter_v.first_x;
	data->inter_v.y_intersect = data->inter_v.first_y;
	while (iswallhited(data->inter_v.x_intersect + 0.00000001,
			data->inter_v.y_intersect + 0.00000001, data) == 0)
	{
		data->inter_v.x_intersect += data->inter_v.xstep;
		data->inter_v.y_intersect += data->inter_v.ystep;
	}
	data->p.v_dist = distancebetweenpoints(data->p.pos_x, data->p.pos_y,
			data->inter_v.x_intersect, data->inter_v.y_intersect);
	data->p.v_rayx = data->inter_v.x_intersect;
	data->p.v_rayy = data->inter_v.y_intersect;
}

void	downleft_vintersect(t_data *data)
{
	data->inter_v.first_x = (floor(data->p.pos_x / TILE_SIZE) * TILE_SIZE);
	data->inter_v.first_y = data->p.pos_y
		+ ((data->inter_v.first_x - data->p.pos_x) * tan(data->p.ray_angle));
	data->inter_v.xstep = -TILE_SIZE;
	data->inter_v.ystep = data->inter_v.xstep * tan(data->p.ray_angle);
	if (data->inter_v.ystep < 0)
		data->inter_v.ystep *= -1;
	data->inter_v.x_intersect = data->inter_v.first_x;
	data->inter_v.y_intersect = data->inter_v.first_y;
	while (iswallhited(data->inter_v.x_intersect - 0.00000001,
			data->inter_v.y_intersect + 0.00000001, data) == 0)
	{
		data->inter_v.x_intersect += data->inter_v.xstep;
		data->inter_v.y_intersect += data->inter_v.ystep;
	}
	data->p.v_rayx = data->inter_v.x_intersect;
	data->p.v_rayy = data->inter_v.y_intersect;
	data->p.v_dist = distancebetweenpoints(data->p.pos_x, data->p.pos_y,
			data->p.v_rayx, data->p.v_rayy);
}

void	upleft_vintersect(t_data *data)
{
	data->inter_v.first_x = (floor(data->p.pos_x / TILE_SIZE) * TILE_SIZE);
	data->inter_v.first_y = data->p.pos_y
		+ ((data->inter_v.first_x - data->p.pos_x) * tan(data->p.ray_angle));
	data->inter_v.xstep = -TILE_SIZE;
	data->inter_v.ystep = data->inter_v.xstep * tan(data->p.ray_angle);
	if (data->inter_v.ystep > 0)
		data->inter_v.ystep *= -1;
	data->inter_v.x_intersect = data->inter_v.first_x;
	data->inter_v.y_intersect = data->inter_v.first_y;
	while (iswallhited(data->inter_v.x_intersect - 0.00000001,
			data->inter_v.y_intersect - 0.00000001, data) == 0)
	{
		data->inter_v.x_intersect += data->inter_v.xstep;
		data->inter_v.y_intersect += data->inter_v.ystep;
	}
	data->p.v_rayx = data->inter_v.x_intersect;
	data->p.v_rayy = data->inter_v.y_intersect;
	data->p.v_dist = distancebetweenpoints(data->p.pos_x, data->p.pos_y,
			data->p.v_rayx, data->p.v_rayy);
}

void	vertical_intersection(t_data *data)
{
	data->p.ray_angle = normalizeangle(data->p.ray_angle);
	data->p.rotation_angle = normalizeangle(data->p.rotation_angle);
	if ((data->p.ray_angle > (270 * (M_PI / 180))
			&& data->p.ray_angle <= 2 * M_PI))
		upright_vintersect(data);
	else if ((data->p.ray_angle > 0 && data->p.ray_angle <= M_PI / 2))
		downright_vintersect(data);
	else if ((data->p.ray_angle > M_PI / 2 && data->p.ray_angle <= M_PI))
		downleft_vintersect(data);
	else if ((data->p.ray_angle > M_PI && data->p.ray_angle <= 3 *(M_PI / 2)))
		upleft_vintersect(data);
}
