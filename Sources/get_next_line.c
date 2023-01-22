/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:52:32 by aalazhar          #+#    #+#             */
/*   Updated: 2023/01/20 15:10:47 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	find_new_line(char *remain)
{
	int	i;

	i = 0;
	if (!remain)
		return (-1);
	while (remain[i])
	{
		if (remain[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_line(char *remain)
{
	char	*line;
	int		index;
	int		i;

	i = 0;
	if (ft_strlen(remain) <= 0)
		return (NULL);
	index = find_new_line(remain);
	if (index == -1)
	{
		line = ft_strdup(remain);
		return (line);
	}
	line = (char *)malloc((index + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (remain[i] != '\n')
	{
		line[i] = remain[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*ft_remain(char *remain)
{
	char	*tmp;
	int		len;
	int		index;

	if (!remain)
		return (NULL);
	len = ft_strlen(remain);
	index = find_new_line(remain);
	if (index != -1)
	{
		tmp = ft_substr(remain, (index + 1), (len - index - 1));
		free(remain);
		remain = tmp;
		return (remain);
	}
	free(remain);
	return (NULL);
}

char	*ft_read_line(int fd, char *buff, char *remain)
{
	char	*tmp;
	int		n;

	n = 0;
	while (find_new_line(remain) == -1)
	{
		n = read(fd, buff, BUFF_SIZE);
		if (n > 0)
		{
			buff[n] = '\0';
			tmp = ft_strjoin(remain, buff);
			if (remain)
				free(remain);
			remain = NULL;
			remain = tmp;
		}
		else
			break ;
	}
	free(buff);
	buff = NULL;
	if (n == -1)
		return (NULL);
	return (remain);
}

char	*get_next_line(int fd)
{
	static char		*remain;
	char			*line;
	char			*buff;

	if (BUFF_SIZE <= 0 || fd < 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		return (NULL);
	remain = ft_read_line(fd, buff, remain);
	line = ft_line(remain);
	remain = ft_remain(remain);
	return (line);
}
