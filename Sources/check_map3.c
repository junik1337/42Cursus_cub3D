/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:39:40 by ayassir           #+#    #+#             */
/*   Updated: 2023/01/16 20:22:59 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	one_before_space(char *str, int j)
{
	int		i;

	i = j - 1;
	while (str[i] && i >= 0)
	{
		if (str[i] && str[i] == '0')
			return (0);
		else if (str[i] && str[i] == '1')
			break ;
		i--;
	}
	return (1);
}

int	one_after_space(char *str, int j)
{
	int		i;

	i = j + 1;
	while (str[i])
	{
		if (str[i] && str[i] == '0')
			return (0);
		else if (str[i] && str[i] == '1')
			break ;
		i++;
	}
	return (1);
}

int	one_up_space(char **str, int i, int j)
{
	if (i == 0)
		return (1);
	while (str[i] && i >= 0)
	{
		if (str[i][j] && str[i][j] == '0')
			return (0);
		else if (str[i][j] && str[i][j] == '1')
			break ;
		i++;
	}
	return (1);
}

int	one_down_space(char **str, int i, int j)
{
	while (str[i])
	{
		if (str[i][j] && str[i][j] == '0')
			return (0);
		else if (str[i][j] && str[i][j] == '1')
			break ;
		i++;
	}
	return (1);
}

int	ft_close(t_data *data)
{
	destroy_imgs(data);
	exit(0);
}
