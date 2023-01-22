/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:46:42 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/08 17:23:12 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	left_condition_1(t_data *data, t_vars *vars)
{
	if (data->mymap.map[vars->imap_y - 1][vars->imap_x] == '1'
		&& data->mymap.map[vars->imap_y][vars->imap_x - 1] == '1'
		&& data->mymap.map[vars->oy + 1][vars->ox] == '1'
		&& data->mymap.map[vars->oy][vars->ox + 1] == '1')
		return (1);
	return (0);
}

int	left_condition_2(t_data *data, t_vars *vars)
{
	if (data->mymap.map[vars->imap_y - 1][vars->imap_x] == '1'
		&& data->mymap.map[vars->imap_y][vars->imap_x + 1] == '1'
		&& data->mymap.map[vars->oy][vars->ox - 1] == '1'
		&& data->mymap.map[vars->oy + 1][vars->ox] == '1')
		return (1);
	return (0);
}

int	left_condition_3(t_data *data, t_vars *vars)
{
	if (data->mymap.map[vars->imap_y - 1][vars->imap_x] == '1'
		&& data->mymap.map[vars->imap_y][vars->imap_x - 1] == '1'
		&& data->mymap.map[vars->oy + 1][vars->ox] == '1'
		&& data->mymap.map[vars->oy][vars->ox + 1] == '1')
		return (1);
	return (0);
}

int	left_condition_4(t_data *data, t_vars *vars)
{
	if (data->mymap.map[vars->imap_y - 1][vars->imap_x] == '1'
		&& data->mymap.map[vars->imap_y][vars->imap_x + 1] == '1'
		&& data->mymap.map[vars->oy][vars->ox - 1] == '1'
		&& data->mymap.map[vars->oy + 1][vars->ox] == '1')
		return (1);
	return (0);
}

int	right_condition_4(t_data *data, t_vars *vars)
{
	if (data->mymap.map[vars->imap_y + 1][vars->imap_x] == '1'
		&& data->mymap.map[vars->imap_y][vars->imap_x - 1] == '1'
		&& data->mymap.map[vars->oy - 1][vars->ox] == '1'
		&& data->mymap.map[vars->oy][vars->ox + 1] == '1')
		return (1);
	return (0);
}
