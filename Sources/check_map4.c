/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalazhar <aalazhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:47:22 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/20 16:53:25 by aalazhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_colors(char **str)
{
	int		i;
	int		j;
	int		f_color;
	int		c_color;

	c_color = 0;
	f_color = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == 'F')
				f_color++;
			if (str[i][j] == 'C')
				c_color++;
		}
	}
	if (f_color > 1 || c_color > 1 || f_color < 1 || c_color < 1)
		return (1);
	return (0);
}

void	init_textures(t_texture *texture)
{
	texture->north_texture = 0;
	texture->south_texture = 0;
	texture->east_texture = 0;
	texture->west_texture = 0;
	texture->i = -1;
	texture->j = -1;
	texture->check = NULL;
}

int	check_textures(char **str)
{
	t_texture	t;

	init_textures(&t);
	while (str[++(t.i)])
	{
		t.check = ft_strtrim(str[t.i], "\t ");
		t.j = -1;
		while (t.check[++t.j])
		{
			if (t.check[t.j] == 'E' && t.check[t.j + 1] == 'A')
				t.east_texture++;
			else if (t.check[t.j] == 'W' && t.check[t.j + 1] == 'E')
				t.west_texture++;
			else if (t.check[t.j] == 'N' && t.check[t.j + 1] == 'O')
				t.north_texture++;
			else if (t.check[t.j] == 'S' && t.check[t.j + 1] == 'O')
				t.south_texture++;
		}
		free(t.check);
	}
	if (t.east_texture > 1 || t.west_texture > 1 || t.north_texture > 1
		|| t.south_texture > 1)
		return (1);
	return (0);
}

void	get_data_address(t_data *data)
{
	data->img_south.d_adress = (int *)mlx_get_data_addr(data->img_south.ptr,
			&data->img_south.bpp, &data->img_south.s_line,
			&data->img_south.endian);
	data->img_north.d_adress = (int *)mlx_get_data_addr(data->img_north.ptr,
			&data->img_north.bpp, &data->img_north.s_line,
			&data->img_north.endian);
	data->img_east.d_adress = (int *)mlx_get_data_addr(data->img_east.ptr,
			&data->img_east.bpp, &data->img_east.s_line,
			&data->img_east.endian);
	data->img_west.d_adress = (int *)mlx_get_data_addr(data->img_west.ptr,
			&data->img_west.bpp, &data->img_west.s_line,
			&data->img_west.endian);
}
