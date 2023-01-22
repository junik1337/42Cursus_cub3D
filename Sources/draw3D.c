/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalazhar <aalazhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:33:11 by aalazhar          #+#    #+#             */
/*   Updated: 2023/01/20 16:20:14 by aalazhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_walls_west(t_data *data, int i, int x_offset)
{
	int		j;
	int		distancefromtop;
	int		y_offset;

	distancefromtop = 0;
	j = data->p.top_wallcoord;
	while (j < data->p.bot_wallcoord)
	{
		distancefromtop = j + (data->p.wall_streapheight / 2)
			- (data->win_height / 2);
		y_offset = distancefromtop
			* ((double)TILE_SIZE / data->p.wall_streapheight);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			(i * data->p.wall_streapwidth), j,
			data->img_west.d_adress[(TILE_SIZE * y_offset) + x_offset]);
		j++;
	}
}

void	draw_walls_east(t_data *data, int i, int x_offset)
{
	int		j;
	int		distancefromtop;
	int		y_offset;

	distancefromtop = 0;
	j = data->p.top_wallcoord;
	while (j < data->p.bot_wallcoord)
	{
		distancefromtop = j + (data->p.wall_streapheight / 2)
			- (data->win_height / 2);
		y_offset = distancefromtop
			* ((double)TILE_SIZE / data->p.wall_streapheight);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			(i * data->p.wall_streapwidth), j,
			data->img_east.d_adress[(TILE_SIZE * y_offset) + x_offset]);
		j++;
	}
}

void	draw_walls_north(t_data *data, int i, int x_offset)
{
	int		j;
	int		distancefromtop;
	int		y_offset;

	distancefromtop = 0;
	j = data->p.top_wallcoord;
	while (j < data->p.bot_wallcoord)
	{
		distancefromtop = j + (data->p.wall_streapheight / 2)
			- (data->win_height / 2);
		y_offset = distancefromtop
			* ((double)TILE_SIZE / data->p.wall_streapheight);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			(i * data->p.wall_streapwidth), j,
			data->img_north.d_adress[(TILE_SIZE * y_offset) + x_offset]);
		j++;
	}
}

void	draw_walls_south(t_data *data, int i, int x_offset)
{
	int		j;
	int		distancefromtop;
	int		y_offset;

	distancefromtop = 0;
	j = data->p.top_wallcoord;
	while (j < data->p.bot_wallcoord)
	{
		distancefromtop = j + (data->p.wall_streapheight / 2)
			- (data->win_height / 2);
		y_offset = distancefromtop
			* ((double)TILE_SIZE / data->p.wall_streapheight);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			(i * data->p.wall_streapwidth), j,
			data->img_south.d_adress[(TILE_SIZE * y_offset) + x_offset]);
		j++;
	}
}

void	render3d(t_data *data)
{
	int		i;
	int		textoffset_x;

	i = -1;
	data->p.ray_angle = data->p.rotation_angle - (data->p.field_angle / 2);
	while (++i < data->p.rays_number)
	{
		data->ray_west = 0;
		data->ray_north = 0;
		data->ray_south = 0;
		data->ray_east = 0;
		horizontal_intersection(data);
		vertical_intersection(data);
		if (data->p.v_dist > data->p.h_dist)
			raydis_h(i, data);
		else
			raydis_v(i, data);
		topbotwallcoord(data, i);
		if (data->p.vertical_hit)
			textoffset_x = (int)data->p.ray_y % TILE_SIZE;
		else
			textoffset_x = (int)data->p.ray_x % TILE_SIZE;
		draw_everything(data, i, textoffset_x);
		data->p.ray_angle += data->p.field_angle / data->p.rays_number;
	}
}
