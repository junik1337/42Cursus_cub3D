/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:15:31 by aalazhar          #+#    #+#             */
/*   Updated: 2023/01/16 20:23:22 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	checkmap_element_2(t_data *data, int i, int j, int *counter)
{
	if (data->mymap.map[i][j] != '1'
		&& data->mymap.map[i][j] != '0'
		&& data->mymap.map[i][j] != ' '
		&& data->mymap.map[i][j] != 'F'
		&& data->mymap.map[i][j] != 'N'
		&& data->mymap.map[i][j] != 'S'
		&& data->mymap.map[i][j] != 'W'
		&& data->mymap.map[i][j] != 'E')
		return (0);
	else if (data->mymap.map[i][j] == 'N' || data->mymap.map[i][j] == 'S'
		|| data->mymap.map[i][j] == 'W'
		|| data->mymap.map[i][j] == 'E')
	{
		data->p.pos_x = (j * TILE_SIZE) + (TILE_SIZE / 2);
		data->p.pos_y = (i * TILE_SIZE) + (TILE_SIZE / 2);
		ft_playerdirection(data, data->mymap.map[i][j]);
		(*counter)++;
	}
	return (1);
}

int	checkmap_element(t_data *data)
{
	int		i;
	int		j;
	int		counter;

	i = 0;
	j = 0;
	counter = 0;
	while (data->mymap.map[i])
	{
		j = 0;
		while (data->mymap.map[i][j])
		{
			if (!checkmap_element_2(data, i, j, &counter))
				return (0);
			j++;
		}
		i++;
	}
	if (counter != 1)
		return (0);
	return (1);
}

int	check_shape(char **str)
{
	int		i;
	int		j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == '0')
			{
				if (!one_before(str[i], j) || !one_after(str[i], j)
					|| !one_up(str, i - 1, j) || !one_down(str, i + 1, j))
					return (0);
			}
			else if (str[i][j] == ' ')
			{
				if (!one_before_space(str[i], j) || !one_after_space(str[i], j)
					|| !one_up_space(str, i - 1, j)
					|| !one_down_space(str, i + 1, j))
					return (0);
			}
		}
	}
	return (1);
}

int	check_tab(t_data *data)
{
	int		i;

	i = -1;
	if (!checkmap_element(data))
		return (ft_putendl_fd("Error : Invalid map!", 2), 0);
	if (!check_shape(data->mymap.map))
		return (ft_putendl_fd("Error : Invalid map!", 2), 0);
	return (1);
}
