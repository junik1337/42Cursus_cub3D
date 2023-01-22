/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:55:59 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/20 15:07:38 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	mlx_clear_put(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img_cel.ptr, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_flo.ptr,
		0, data->win_height / 2);
}

void	free_strings(char *tmp, t_store	*var)
{
	free (tmp);
	free (var->line);
}

void	free_tabs(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free(str);
}

int	free_number(char **rgb_c, char **rgb_f)
{
	int		i;

	i = -1;
	if (!check_numbers(rgb_c[0]) || !check_numbers(rgb_c[1])
		|| !check_numbers(rgb_c[2]) || !check_numbers(rgb_f[0])
		|| !check_numbers(rgb_f[1]) || !check_numbers(rgb_f[2]))
	{
		while (rgb_c[++i])
			free (rgb_c[i]);
		i = -1;
		while (rgb_f[++i])
			free (rgb_f[i]);
		free (rgb_c);
		free (rgb_f);
		return (0);
	}
	return (1);
}

int	free_interval(char **rgb_c, char **rgb_f)
{
	int		i;

	i = -1;
	if (!check_interval(ft_atoi(rgb_c[0])) || !check_interval(ft_atoi(rgb_c[1]))
		|| !check_interval(ft_atoi(rgb_c[2]))
		|| !check_interval(ft_atoi(rgb_f[0]))
		|| !check_interval(ft_atoi(rgb_f[1]))
		|| !check_interval(ft_atoi(rgb_f[2])))
	{
		while (rgb_c[++i])
			free (rgb_c[i]);
		i = -1;
		while (rgb_f[++i])
			free (rgb_f[i]);
		free (rgb_c);
		free (rgb_f);
		return (0);
	}
	return (1);
}
