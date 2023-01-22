/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:33:19 by aalazhar          #+#    #+#             */
/*   Updated: 2023/01/19 12:38:05 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	close_window(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(1);
	}
	return (0);
}

int	release(int key, t_data *data)
{
	if (key == KEY_RIGHT)
		data->p.turn_right = 0;
	else if (key == KEY_LEFT)
		data->p.turn_left = 0;
	else if (key == KEY_W)
		data->p._forward = 0;
	else if (key == KEY_S)
		data->p._backward = 0;
	else if (key == KEY_A)
		data->p._left = 0;
	else if (key == KEY_D)
		data->p._right = 0;
	return (0);
}

void	destroy_imgs(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_west.ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_east.ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_south.ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_north.ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_cel.ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_flo.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

int	press(int key, t_data *data)
{
	if (key == KEY_ESC)
		return (destroy_imgs(data), exit(0), 0);
	else if (key == KEY_RIGHT)
		data->p.turn_right = 1;
	else if (key == KEY_LEFT)
		data->p.turn_left = -1;
	else if (key == KEY_W)
		data->p._forward = 1;
	else if (key == KEY_S)
		data->p._backward = -1;
	else if (key == KEY_D)
		data->p._right = 1;
	else if (key == KEY_A)
		data->p._left = -1;
	return (0);
}

int	render(t_data *data)
{
	if (data->p.turn_left)
		data->p.rotation_angle += 0.1 * data->p.turn_left;
	else if (data->p.turn_right)
		data->p.rotation_angle += 0.1 * data->p.turn_right;
	if (data->p._forward)
	{
		if (_forward(data))
			return (1);
	}
	else if (data->p._backward)
		if (_backward(data))
			return (1);
	if (data->p._left)
	{
		if (_left(data))
			return (1);
	}
	else if (data->p._right)
		if (_right(data))
			return (1);
	mlx_clear_put(data);
	render3d(data);
	return (0);
}
