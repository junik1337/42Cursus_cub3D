/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:58:51 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/11 17:03:31 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_lines_no(t_data *data, char *str)
{
	if (check_path(str))
	{
		data->sides.north_path = get_path(str);
		if (open(data->sides.north_path, O_RDONLY) < 0)
		{
			ft_putendl_fd("Error : North texture is invalid", 2);
			free (data->sides.north_path);
			exit (1);
		}
	}
	else
		return (0);
	return (1);
}

int	check_lines_so(t_data *data, char *str)
{
	if (check_path(str))
	{
		data->sides.south_path = get_path(str);
		if (open(data->sides.south_path, O_RDONLY) < 0)
		{
			ft_putendl_fd("Error : South texture is invalid", 2);
			free (data->sides.south_path);
			exit (1);
		}
	}
	else
	{
		free (str);
		return (0);
	}
	return (1);
}

int	check_lines_ea(t_data *data, char *str)
{
	if (check_path(str))
	{
		data->sides.east_path = get_path(str);
		if (open(data->sides.east_path, O_RDONLY) < 0)
		{
			ft_putendl_fd("Error : East texture is invalid", 2);
			free (data->sides.east_path);
			exit (1);
		}
	}
	else
		return (0);
	return (1);
}

int	check_lines_we(t_data *data, char *str)
{
	if (check_path(str))
	{
		data->sides.west_path = get_path(str);
		if (open(data->sides.west_path, O_RDONLY) < 0)
		{
			ft_putendl_fd("Error : West texture is invalid", 2);
			free (data->sides.west_path);
			exit (1);
		}
	}
	else
		return (0);
	return (1);
}

int	check_lines_c(t_data *data, char *str)
{
	data->sides.ceiling = ft_strtrim(str, "C \n");
	if (!check_doubles(data->sides.ceiling))
	{
		free (data->sides.ceiling);
		return (0);
	}
	return (1);
}
