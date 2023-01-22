/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:13:48 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/20 13:39:24 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	_forward(t_data *data)
{
	double	mstep;

	mstep = data->p._forward * data->p.move_speed;
	data->p.new_px = (data->p.pos_x + cos(data->p.rotation_angle) * mstep);
	data->p.new_py = (data->p.pos_y + sin(data->p.rotation_angle) * mstep);
	if (checkbetweenwalls(data->p.new_px, data->p.new_py, data)
		|| revcheckbetweenwalls(data->p.new_px, data->p.new_py, data))
		return (1);
	else if (iswallhited(data->p.new_px, data->p.new_py, data) == 0)
	{
		data->p.pos_x = data->p.new_px;
		data->p.pos_y = data->p.new_py;
	}
	return (0);
}

int	_backward(t_data *data)
{
	double	mstep;

	mstep = data->p._backward * data->p.move_speed;
	data->p.new_px = (data->p.pos_x + cos(data->p.rotation_angle) * mstep);
	data->p.new_py = (data->p.pos_y + sin(data->p.rotation_angle) * mstep);
	if (checkbetweenwalls(data->p.new_px, data->p.new_py, data)
		|| revcheckbetweenwalls(data->p.new_px, data->p.new_py, data))
		return (1);
	else if (iswallhited(data->p.new_px, data->p.new_py, data) == 0)
	{
		data->p.pos_x = data->p.new_px;
		data->p.pos_y = data->p.new_py;
	}
	return (0);
}

int	_right(t_data *data)
{
	double	mstep;

	mstep = data->p._right * data->p.move_speed;
	data->p.new_px = (data->p.pos_x + cos(data->p.rotation_angle
				+ (M_PI / 2)) * mstep);
	data->p.new_py = (data->p.pos_y + sin(data->p.rotation_angle
				+ (M_PI / 2)) * mstep);
	if (leftcheckbetweenwalls(data->p.new_px, data->p.new_py, data)
		|| rightcheckbetweenwalls(data->p.new_px, data->p.new_py, data))
		return (1);
	if (iswallhited(data->p.new_px, data->p.new_py, data) == 0)
	{
		data->p.pos_x = data->p.new_px;
		data->p.pos_y = data->p.new_py;
	}
	return (0);
}

int	_left(t_data *data)
{
	double	mstep;

	mstep = data->p._left * data->p.move_speed;
	data->p.new_px = (data->p.pos_x + cos(data->p.rotation_angle
				+ (M_PI / 2)) * mstep);
	data->p.new_py = (data->p.pos_y + sin(data->p.rotation_angle
				+ (M_PI / 2)) * mstep);
	if (leftcheckbetweenwalls(data->p.new_px, data->p.new_py, data)
		|| rightcheckbetweenwalls(data->p.new_px, data->p.new_py, data))
		return (1);
	if (iswallhited(data->p.new_px, data->p.new_py, data) == 0)
	{
		data->p.pos_x = data->p.new_px;
		data->p.pos_y = data->p.new_py;
	}
	return (0);
}
