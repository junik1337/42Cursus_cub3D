/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalazhar <aalazhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:39:33 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/20 17:08:26 by aalazhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{	
		if (line[i] == '0')
			i++;
		else if (line[i] == '1')
			i++;
		else if (line[i] == '\n' && (line[0] == ' ' || line[0] == '1'))
			i++;
		else if (line[i] == ' ')
			i++;
		else if (line[i] == 'N')
			i++;
		else if (line[i] == 'W')
			i++;
		else if (line[i] == 'S')
			i++;
		else if (line[i] == 'E')
			i++;
		else
			return (0);
	}
	return (1);
}

void	check_newline_in_map(char *line, int *flag)
{
	if (is_map(line))
		*flag = 1;
	else if (!is_map(line) && *flag)
	{
		ft_putendl_fd("Error : Invalid map", 2);
		free (line);
		exit (1);
	}
}

char	**store_map(char *map, t_data *data)
{
	char	**res;
	char	*tmp;

	data->var.fd = open(map, O_RDONLY);
	if (data->var.fd < 0)
		return (write(2, "Error: Invalid file descriptor\n", 31), exit(1), NULL);
	while (data->var.line)
	{
		data->var.line = get_next_line(data->var.fd);
		if (data->var.line == NULL)
			break ;
		else if (data->var.line == NULL
			&& data->var.all_lines[ft_strlen(data->var.all_lines) - 1] == '\n')
			exit_with_error(data->var.all_lines);
		check_newline_in_map(data->var.line, &data->var.flag);
		tmp = data->var.all_lines;
		data->var.all_lines = ft_strjoin(data->var.all_lines, data->var.line);
		free_strings(tmp, &data->var);
	}
	free_and_close(&data->var);
	if (!data->var.all_lines || data->var.all_lines[0] == '\0')
		return (write(2, "Error: No map readed\n", 21), exit(1), NULL);
	res = ft_split(data->var.all_lines, '\n');
	free (data->var.all_lines);
	return (res);
}

int	check_file_type(char *s, char *type)
{
	int	i;

	i = 0;
	while (type[i])
	{
		if (type[i] != s[i])
			return (0);
		i++;
	}
	if (s[i] == '\0')
		return (1);
	return (0);
}

void	check_file(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (check_file_type(s + i, ".cub"))
				return ;
		}
		i++;
	}
	ft_putendl_fd("Error : invalid file type", 2);
	exit(1);
}
