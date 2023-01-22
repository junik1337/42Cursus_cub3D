/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:14:42 by aalazhar          #+#    #+#             */
/*   Updated: 2023/01/17 12:35:09 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	leftcheckbetweenwalls(double x, double y, t_data *data)
{
	t_vars	vars;

	vars.imap_x = floor(x / TILE_SIZE);
	vars.imap_y = floor(y / TILE_SIZE);
	vars.ox = floor(data->p.pos_x / TILE_SIZE);
	vars.oy = floor(data->p.pos_y / TILE_SIZE);
	if (data->p.rotation_angle > (270 * (M_PI / 180))
		&& data->p.rotation_angle <= (360 * (M_PI / 180)) && vars.imap_y > 0)
		if (left_condition_1(data, &vars))
			return (1);
	if (data->p.rotation_angle > 0 && data->p.rotation_angle <= (M_PI / 2)
		&& vars.imap_y > 0)
		if (left_condition_2(data, &vars))
			return (1);
	if (data->p.rotation_angle > (M_PI / 2)
		&& data->p.rotation_angle <= M_PI && vars.imap_y > 0)
		if (left_condition_3(data, &vars))
			return (1);
	if (data->p.rotation_angle > M_PI && data->p.rotation_angle
		<= (270 * (M_PI / 180)) && vars.imap_y > 0)
		if (left_condition_4(data, &vars))
			return (1);
	return (0);
}

int	right_condition_1(t_data *data, t_vars *vars)
{
	if (data->mymap.map[vars->imap_y + 1][vars->imap_x] == '1'
		&& data->mymap.map[vars->imap_y][vars->imap_x + 1] == '1'
		&& data->mymap.map[vars->oy - 1][vars->ox] == '1'
		&& data->mymap.map[vars->oy][vars->ox - 1] == '1')
		return (1);
	return (0);
}

int	right_condition_2(t_data *data, t_vars *vars)
{
	if (data->mymap.map[vars->imap_y + 1][vars->imap_x] == '1'
		&& data->mymap.map[vars->imap_y][vars->imap_x - 1] == '1'
		&& data->mymap.map[vars->oy - 1][vars->ox] == '1'
		&& data->mymap.map[vars->oy][vars->ox + 1] == '1')
		return (1);
	return (0);
}

int	right_condition_3(t_data *data, t_vars *vars)
{
	if (data->mymap.map[vars->imap_y + 1][vars->imap_x] == '1'
		&& data->mymap.map[vars->imap_y][vars->imap_x + 1] == '1'
		&& data->mymap.map[vars->oy - 1][vars->ox] == '1'
		&& data->mymap.map[vars->oy][vars->ox - 1] == '1')
		return (1);
	return (0);
}

int	rightcheckbetweenwalls(double x, double y, t_data *data)
{
	t_vars	vars;

	vars.imap_x = floor(x / TILE_SIZE);
	vars.imap_y = floor(y / TILE_SIZE);
	vars.ox = floor(data->p.pos_x / TILE_SIZE);
	vars.oy = floor(data->p.pos_y / TILE_SIZE);
	if (data->p.rotation_angle > (270 * (M_PI / 180))
		&& data->p.rotation_angle <= (360 * (M_PI / 180))
		&& vars.imap_y > 0 && vars.imap_y < data->mymap.map_height - 1)
		if (right_condition_1(data, &vars))
			return (1);
	if (data->p.rotation_angle > 0 && data->p.rotation_angle <= (M_PI / 2)
		&& vars.imap_y < data->mymap.map_height - 1)
		if (right_condition_2(data, &vars))
			return (1);
	if (data->p.rotation_angle > (M_PI / 2) && data->p.rotation_angle <= M_PI
		&& vars.imap_y < data->mymap.map_height - 1)
		if (right_condition_3(data, &vars))
			return (1);
	if (data->p.rotation_angle > M_PI && data->p.rotation_angle
		<= (270 * (M_PI / 180)) && vars.imap_y > 0
		&& vars.imap_y < data->mymap.map_height - 1)
		if (right_condition_4(data, &vars))
			return (1);
	return (0);
}
