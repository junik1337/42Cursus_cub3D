/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalazhar <aalazhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:38:22 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/20 16:55:40 by aalazhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_img(t_data *data)
{
	data->img_south.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sides.south_path, &data->img_south.width,
			&data->img_south.height);
	data->img_north.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sides.north_path, &data->img_south.width,
			&data->img_south.height);
	data->img_west.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sides.west_path, &data->img_south.width,
			&data->img_south.height);
	data->img_east.ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			data->sides.east_path, &data->img_south.width,
			&data->img_south.height);
	if (!data->img_south.ptr || !data->img_north.ptr
		|| !data->img_west.ptr || !data->img_east.ptr)
		return (ft_putendl_fd("Error : texture is invalid", 2), exit(1));
	get_data_address(data);
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "cub3d");
	data->var.flag = 0;
}

void	init_player(t_data *data)
{
	data->p.turn_left = 0;
	data->p.turn_right = 0;
	data->p._forward = 0;
	data->p._backward = 0;
	data->p._left = 0;
	data->p._right = 0;
	data->p.wall_streapheight = 0;
	data->p.distance_project_plane = 0;
	data->p.vertical_hit = 0;
	data->p.horizontal_hit = 0;
	data->p.top_wallcoord = 0;
	data->p.bot_wallcoord = 0;
	data->p.move_speed = 5;
	data->p.field_angle = 60 * (M_PI / 180);
	data->p.wall_streapwidth = 1;
	data->p.rays_number = WIDTH / data->p.wall_streapwidth;
	data->p.rays_distance = malloc(sizeof(double) * data->p.rays_number);
	if (!data->p.rays_distance)
		return (ft_putendl_fd("Error : Malloc failed", 1), exit(1));
}

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = (int) ft_strlen(str);
	if (!str)
		return (0);
	while (i >= 0)
	{
		if (str[i] == (unsigned char )c)
			return ((char *) str + i);
		i--;
	}
	return (NULL);
}

int	check_lines_f(t_data *data, char *str)
{
	data->sides.floor = ft_strtrim(str, "F \n");
	if (!check_doubles(data->sides.floor))
	{
		free (data->sides.floor);
		return (0);
	}
	return (1);
}
