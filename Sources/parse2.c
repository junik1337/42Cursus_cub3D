/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:16:40 by aalazhar          #+#    #+#             */
/*   Updated: 2023/01/11 17:14:44 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_numbers(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strtrim(str, " ");
	if (ft_strlen(tmp) > 3)
	{
		free (tmp);
		return (0);
	}
	while (tmp[i])
	{
		if (tmp[i] == ' ')
		{
			free (tmp);
			return (0);
		}
		i++;
	}
	free (tmp);
	return (1);
}

int	check_interval(int nbr)
{
	if (nbr < 0 || nbr > 255)
		return (0);
	return (1);
}

int	get_rgb(t_data *data)
{
	char	**rgb_c;
	char	**rgb_f;

	if (!data->sides.ceiling || !data->sides.floor)
		return (0);
	rgb_c = ft_split(data->sides.ceiling, ',');
	rgb_f = ft_split(data->sides.floor, ',');
	free (data->sides.ceiling);
	free (data->sides.floor);
	if (!free_number(rgb_c, rgb_f))
		return (0);
	if (!free_interval(rgb_c, rgb_f))
		return (0);
	data->sides.ceilingcolor = (ft_atoi(rgb_c[0]) << 16) + (ft_atoi(rgb_c[1])
			<< 8) + ft_atoi(rgb_c[2]);
	data->sides.floorcolor = (ft_atoi(rgb_f[0]) << 16) + (ft_atoi(rgb_f[1])
			<< 8) + ft_atoi(rgb_f[2]);
	free_tabs(rgb_c);
	free_tabs(rgb_f);
	return (1);
}

void	init_sides(t_data *data)
{
	data->sides.north_path = NULL;
	data->sides.south_path = NULL;
	data->sides.east_path = NULL;
	data->sides.west_path = NULL;
	data->sides.ceiling = NULL;
	data->sides.floor = NULL;
	data->sides.text_path = NULL;
}

int	collect_data(t_data *data)
{
	char	*line;
	int		fd;

	init_sides(data);
	fd = open(data->mymap.fname, O_RDONLY);
	if (!fd)
		return (ft_putendl_fd("Error : Cannot open the file!", 2), 0);
	line = get_next_line(fd);
	while (line)
	{
		if (!check_lines(line, data))
			return (ft_putendl_fd("Error : Invalid data!", 2), 0);
		free(line);
		line = get_next_line(fd);
	}
	if (!data->sides.ceiling || !data->sides.floor
		|| !data->sides.east_path || !data->sides.west_path
		|| !data->sides.north_path || !data->sides.south_path)
		return (ft_putendl_fd("Error : Invalid data!", 2), 0);
	if (!get_rgb(data))
		return (ft_putendl_fd("Error : Invalid data!", 2), 0);
	return (1);
}
