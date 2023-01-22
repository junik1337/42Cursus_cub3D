/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_forw_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:48:10 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/20 13:36:08 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	forward_condition_1(t_data *data, t_vars *vars)
{
	if (data->mymap.map[vars->imap_y + 1][vars->imap_x] == '1'
		&& data->mymap.map[vars->imap_y][vars->imap_x - 1] == '1'
		&& data->mymap.map[vars->oy - 1][vars->ox] == '1'
		&& data->mymap.map[vars->oy][vars->ox + 1] == '1')
		return (1);
	return (0);
}

int	forward_condition_2(t_data *data, t_vars *vars)
{
	if (data->mymap.map[vars->imap_y][vars->imap_x - 1] == '1'
		&& data->mymap.map[vars->imap_y - 1][vars->imap_x] == '1'
		&& data->mymap.map[vars->oy][vars->ox + 1] == '1'
		&& data->mymap.map[vars->oy + 1][vars->ox] == '1')
		return (1);
	return (0);
}

int	forward_condition_3(t_data *data, t_vars *vars)
{
	if (data->mymap.map[vars->imap_y][vars->imap_x + 1] == '1'
		&& data->mymap.map[vars->imap_y - 1][vars->imap_x] == '1'
		&& data->mymap.map[vars->oy][vars->ox - 1] == '1'
		&& data->mymap.map[vars->oy + 1][vars->ox] == '1')
		return (1);
	return (0);
}

int	forward_condition_4(t_data *data, t_vars *vars)
{
	if (data->mymap.map[vars->imap_y][vars->imap_x + 1] == '1'
		&& data->mymap.map[vars->imap_y + 1][vars->imap_x] == '1'
		&& data->mymap.map[vars->oy][vars->ox - 1] == '1'
		&& data->mymap.map[vars->oy - 1][vars->ox] == '1')
		return (1);
	return (0);
}

void	draw_everything(t_data *data, int i, int textoffset_x)
{
	if (data->ray_west)
		draw_walls_west(data, i, textoffset_x);
	else if (data->ray_east)
		draw_walls_east(data, i, textoffset_x);
	else if (data->ray_north)
		draw_walls_north(data, i, textoffset_x);
	else if (data->ray_south)
		draw_walls_south(data, i, textoffset_x);
}
