/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:05:35 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/20 15:07:43 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	usedraydistance_v(t_data *data, int i)
{
	data->p.ray_x = data->p.v_rayx;
	data->p.ray_y = data->p.v_rayy;
	data->p.rays_distance[i] = data->p.v_dist;
	data->p.horizontal_hit = 0;
	data->p.vertical_hit = 1;
}

void	check_width_height(t_data *data)
{
	int		i;
	size_t	k;

	i = 0;
	k = 0;
	while (data->mymap.map[i])
	{
		if (k < ft_strlen(data->mymap.map[i]))
			data->mymap.map_width = ft_strlen(data->mymap.map[i]);
		i++;
	}
	data->mymap.map_height = i;
}

int	iswallhited(double x, double y, t_data *data)
{
	int		imap_x;
	int		imap_y;

	imap_x = floor(x / TILE_SIZE);
	imap_y = floor(y / TILE_SIZE);
	if (x >= 0 && x < data->win_width && y >= 0
		&& imap_y < data->mymap.map_height && imap_y >= 0)
	{
		if (data->mymap.map[imap_y] && (data->mymap.map[imap_y][imap_x] == '0'
			|| data->mymap.map[imap_y][imap_x] == 'N'
			|| data->mymap.map[imap_y][imap_x] == 'S'
			|| data->mymap.map[imap_y][imap_x] == 'W'
			|| data->mymap.map[imap_y][imap_x] == 'E'))
			return (0);
	}
	return (2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	i = 0;
	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && check_set(s1[start], set))
		start++;
	while (end > start && check_set(s1[end - 1], set))
		end--;
	str = (char *)malloc((end - start) + 1);
	if (str == NULL)
		return (NULL);
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

double	distancebetweenpoints(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
