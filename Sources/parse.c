/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:57:12 by aalazhar          #+#    #+#             */
/*   Updated: 2023/01/11 12:26:41 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*check_path(char *str)
{
	char	*ext;
	char	*tmp;

	tmp = ft_strtrim(str, " \n");
	ext = ft_strrchr(tmp, '.');
	free(tmp);
	if (ext)
	{
		if (ft_strncmp(".xpm", ext, 4) == 0 && ft_strlen(ext) == 4)
			return (ext);
		else
			return (NULL);
	}
	else
		return (NULL);
	return (ext);
}

char	*get_path(char *str)
{
	int		fd;
	char	*path;

	path = ft_strtrim(str, "SOAWEN \n");
	if (!path)
	{
		free (path);
		return (NULL);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	return (path);
}

int	commas_count(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == ' ' || ft_isdigit(str[i]))
			i++;
		else if (str[i] == ',')
		{
			counter++;
			i++;
		}
		else
			return (0);
	}
	if (counter != 2)
		return (0);
	return (counter);
}

int	check_doubles(char *str)
{
	int	i;
	int	last;

	i = 0;
	last = ft_strlen(str) - 1;
	if (str[0] == ',' || str[last] == ',' || !commas_count(str))
		return (0);
	while (str[i])
	{
		if (str[i] == ',')
		{
			i++;
			if (str[i] == ' ' || ft_isdigit(str[i]))
				i++;
			else
				return (0);
		}
		else if (str[i] == ' ')
			i++;
		else if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_lines(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32)
			i++;
		else if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
			return (check_lines_no(data, str));
		else if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
			return (check_lines_so(data, str));
		else if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
			return (check_lines_ea(data, str));
		else if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
			return (check_lines_we(data, str));
		else if (str[i] == 'C' && str[i + 1] == ' ')
			return (check_lines_c(data, str));
		else if (str[i] == 'F' && str[i + 1] == ' ')
			return (check_lines_f(data, str));
		else
			break ;
	}
	return (1);
}
