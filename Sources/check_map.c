/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:58:45 by aalazhar          #+#    #+#             */
/*   Updated: 2023/01/20 11:47:42 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*fct2(char *s, int size)
{
	char	*rs;
	char	*check;
	int		i;

	check = ft_strtrim(s, "\t ");
	rs = malloc (sizeof(char) * (size + 1));
	if (!rs)
		return (ft_putendl_fd("Error : allocation failed", 2), exit(1), NULL);
	if (check[0] != '1' || check[ft_strlen(check) - 1] != '1')
		return (ft_putendl_fd("Error : Invalid map", 1), exit(1), NULL);
	free(check);
	i = -1;
	while (s[++i])
		rs[i] = s[i];
	while (i < size)
	{
		rs[i] = ' ';
		i++;
	}
	rs[i] = '\0';
	return (rs);
}

char	**fct(char **str, int start, int end, int size)
{
	int		i;
	int		s;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * (end - start + 1));
	if (!tmp)
		return (ft_putendl_fd("Error : Allocation failed!", 2), exit(1), NULL);
	s = start - 1;
	i = -1;
	while (++i < (end - start))
		tmp[i] = fct2(str[++s], size);
	tmp[i] = NULL;
	return (tmp);
}

char	**stor_tab(char **str)
{
	int		i;
	int		j;
	size_t	k;
	char	*check;

	i = -1;
	k = 0;
	while (str[++i])
	{
		check = ft_strtrim(str[i], "\t ");
		if (ft_isdigit(check[0]))
			break ;
		free(check);
		check = NULL;
	}
	free(check);
	j = i;
	while (str[i] != NULL)
	{
		if (ft_strlen(str[i]) > k)
			k = ft_strlen(str[i]);
		i++;
	}
	return (fct(str, j, i, k));
}

void	get_map(char *str, t_data *data)
{
	check_file(str);
	data->var.line = "";
	data->var.all_lines = NULL;
	data->mymap.map2 = store_map(str, data);
	if (data->mymap.map2 == NULL)
		return (ft_putendl_fd("Error : Map is empty!", 2), exit(1));
	else if (check_colors(data->mymap.map2))
		return (ft_putendl_fd("Error : Invalid colors!", 2), exit(1));
	else if (check_textures(data->mymap.map2))
		return (ft_putendl_fd("Error : Invalid textures!", 2), exit(1));
}
