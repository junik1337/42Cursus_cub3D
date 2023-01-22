/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:38:57 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/20 15:08:03 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_texture_v(t_data *data)
{
	if (data->p.ray_angle > M_PI && data->p.ray_angle <= (270 * (M_PI / 180)))
	{
		data->ray_west = 1;
		data->ray_east = 0;
	}
	else if (data->p.ray_angle > (270 * (M_PI / 180))
		&& data->p.ray_angle <= (2 * M_PI))
	{
		data->ray_west = 0;
		data->ray_east = 1;
	}
	else if (data->p.ray_angle > 0 && data->p.ray_angle <= (M_PI / 2))
	{
		data->ray_west = 0;
		data->ray_east = 1;
	}
	else if (data->p.ray_angle > (M_PI / 2) && data->p.ray_angle <= M_PI)
	{
		data->ray_west = 1;
		data->ray_east = 0;
	}
}

void	check_texture_h(t_data *data)
{
	if (data->p.ray_angle > M_PI && data->p.ray_angle <= (2 * M_PI))
		data->ray_north = 1;
	else if (data->p.ray_angle > 0 && data->p.ray_angle <= M_PI)
		data->ray_south = 1;
}

void	raydis_h(int i, t_data *data)
{
	usedraydistance_h(data, i);
	check_texture_h(data);
}

void	raydis_v(int i, t_data *data)
{
	usedraydistance_v(data, i);
	check_texture_v(data);
}

void	topbotwallcoord(t_data *data, int i)
{
	double	d_ray;

	d_ray = 0;
	d_ray = data->p.rays_distance[i]
		* cos(data->p.ray_angle - data->p.rotation_angle);
	data->p.distance_project_plane = (data->win_width / 2)
		/ fabs(tan(data->p.field_angle / 2));
	data->p.wall_streapheight = (int)((TILE_SIZE / d_ray)
			* data->p.distance_project_plane);
	data->p.top_wallcoord = (data->win_height / 2)
		- (data->p.wall_streapheight / 2);
	if (data->p.top_wallcoord < 0)
		data->p.top_wallcoord = 0;
	data->p.bot_wallcoord = (data->win_height / 2)
		+ (data->p.wall_streapheight / 2);
	if (data->p.bot_wallcoord > data->win_height)
		data->p.bot_wallcoord = data->win_height;
}
