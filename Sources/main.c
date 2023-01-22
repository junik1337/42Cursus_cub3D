/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalazhar <aalazhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:46:32 by aalazhar          #+#    #+#             */
/*   Updated: 2023/01/20 16:55:37 by aalazhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_data(t_data *data)
{
	int		i;

	data->win_width = WIDTH;
	data->win_height = HEIGHT;
	data->img_south.height = TILE_SIZE;
	data->img_south.width = TILE_SIZE;
	init_player(data);
	init_mlx(data);
	init_img(data);
	data->img_cel.ptr = mlx_new_image(data->mlx_ptr, data->win_width,
			data->win_height / 2);
	data->img_flo.ptr = mlx_new_image(data->mlx_ptr, data->win_width,
			data->win_height / 2);
	data->img_cel.d_adress = (int *)mlx_get_data_addr(data->img_cel.ptr,
			&data->img_cel.bpp, &data->img_cel.s_line, &data->img_cel.endian);
	data->img_flo.d_adress = (int *)mlx_get_data_addr(data->img_flo.ptr,
			&data->img_flo.bpp, &data->img_flo.s_line, &data->img_flo.endian);
	i = -1;
	while (++i < (data->win_width * (data->win_height / 2)))
		data->img_cel.d_adress[i] = data->sides.ceilingcolor;
	i = -1;
	while (++i < (data->win_width * (data->win_height / 2)))
		data->img_flo.d_adress[i] = data->sides.floorcolor;
}

void	usedraydistance_h(t_data *data, int i)
{
	data->p.ray_y = data->p.h_rayy;
	data->p.ray_x = data->p.h_rayx;
	data->p.rays_distance[i] = data->p.h_dist;
	data->p.horizontal_hit = 1;
	data->p.vertical_hit = 0;
}

int	checkbetweenwalls(double x, double y, t_data *data)
{
	t_vars	vars;

	vars.imap_x = floor(x / TILE_SIZE);
	vars.imap_y = floor(y / TILE_SIZE);
	vars.ox = floor(data->p.pos_x / TILE_SIZE);
	vars.oy = floor(data->p.pos_y / TILE_SIZE);
	if (data->p.rotation_angle > (270 * (M_PI / 180))
		&& data->p.rotation_angle <= (360 * (M_PI / 180))
		&& vars.imap_y < data->mymap.map_height - 1)
		if (forward_condition_1(data, &vars))
			return (1);
	if (data->p.rotation_angle > 0 && data->p.rotation_angle <= (M_PI / 2))
		if (vars.imap_x > 0 && vars.imap_y > 0)
			if (forward_condition_2(data, &vars))
				return (1);
	if (data->p.rotation_angle > (M_PI / 2)
		&& data->p.rotation_angle <= M_PI && vars.imap_y > 0)
		if (forward_condition_3(data, &vars))
			return (1);
	if (data->p.rotation_angle > M_PI
		&& data->p.rotation_angle <= (270 * (M_PI / 180))
		&& vars.imap_y < data->mymap.map_height - 1)
		if (forward_condition_4(data, &vars))
			return (1);
	return (0);
}

int	revcheckbetweenwalls(double x, double y, t_data *data)
{
	t_vars	vars;

	vars.imap_x = floor(x / TILE_SIZE);
	vars.imap_y = floor(y / TILE_SIZE);
	vars.ox = floor(data->p.pos_x / TILE_SIZE);
	vars.oy = floor(data->p.pos_y / TILE_SIZE);
	if (data->p.rotation_angle > (270 * (M_PI / 180))
		&& data->p.rotation_angle <= (360 * (M_PI / 180)) && vars.imap_y > 0)
		if (reverse_condition_1(data, &vars))
			return (1);
	if (data->p.rotation_angle > 0 && data->p.rotation_angle <= (M_PI / 2)
		&& vars.imap_y < data->mymap.map_height - 1)
		if (vars.imap_x > 0 && vars.imap_y > 0)
			if (reverse_condition_2(data, &vars))
				return (1);
	if (data->p.rotation_angle > (M_PI / 2) && data->p.rotation_angle
		<= M_PI && vars.imap_y < data->mymap.map_height - 1)
		if (reverse_condition_3(data, &vars))
			return (1);
	if (data->p.rotation_angle > M_PI && data->p.rotation_angle
		<= (270 * (M_PI / 180)) && vars.imap_y > 0)
		if (reverse_condition_4(data, &vars))
			return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (WIDTH <= 0 || HEIGHT <= 0)
		return (ft_putendl_fd("Error : W or H is invalid", 2), 1);
	else if (ac != 2)
		return (ft_putendl_fd("Error : Invalid arguments!!", 2), 1);
	get_map(av[1], &data);
	data.mymap.fname = av[1];
	if (!collect_data(&data))
		return (1);
	data.mymap.map = stor_tab(data.mymap.map2);
	if (!check_tab(&data))
		return (1);
	check_width_height(&data);
	init_data(&data);
	mlx_hook(data.win_ptr, 3, 0, release, &data);
	mlx_hook(data.win_ptr, 2, 0, press, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_close, &data);
	mlx_hook(data.win_ptr, 6, 0, mouse_move, &data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
