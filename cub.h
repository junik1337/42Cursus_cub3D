/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalazhar <aalazhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:46:54 by aalazhar          #+#    #+#             */
/*   Updated: 2023/01/20 16:53:33 by aalazhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stddef.h>

# define WIDTH		640
# define HEIGHT		480

# define TILE_SIZE	16
# define BUFF_SIZE 	1

# define KEY_RIGHT	124
# define KEY_LEFT	123
# define KEY_ESC	53
# define KEY_W		13
# define KEY_D		2
# define KEY_S		1
# define KEY_A		0

typedef struct s_texture {
	int		east_texture;
	int		west_texture;
	int		north_texture;
	int		south_texture;
	char	*check;
	int		i;
	int		j;
}	t_texture;

typedef struct s_vars {
	int		imap_x;
	int		imap_y;
	int		ox;
	int		oy;
	double	x_inc;
	double	y_inc;
	double	win_x;
	double	win_y;
	double	y;
	double	x;
	int		i;
	int		j;
}	t_vars;

typedef struct s_store {
	int		fd;
	char	*line;
	char	*all_lines;
	char	**res;
	int		flag;
}	t_store;

typedef struct s_player {
	double	pos_x;
	double	pos_y;
	double	radius;
	double	field_angle;
	double	wall_streapwidth;
	double	ray_angle;
	double	rotation_angle;
	double	move_speed;
	double	new_px;
	double	new_py;
	double	new_ppx;
	double	new_ppy;
	double	ray_x;
	double	ray_y;
	double	h_dist;
	double	v_dist;
	double	v_rayx;
	double	v_rayy;
	double	h_rayx;
	double	h_rayy;
	double	*rays_distance;
	double	distance_project_plane;
	double	wall_streapheight;
	double	top_wallcoord;
	double	bot_wallcoord;
	int		rays_number;
	int		turn_left;
	int		turn_right;
	int		_forward;
	int		_backward;
	int		_left;
	int		_right;
	int		vertical_hit;
	int		horizontal_hit;

}		t_player;

typedef struct s_inter {
	double		xstep;
	double		ystep;
	double		x_intersect;
	double		y_intersect;
	double		first_x;
	double		first_y;
}		t_inter;

typedef struct s_img {
	void	*ptr;
	int		*d_adress;
	int		width;
	int		height;
	int		bpp;
	int		s_line;
	int		endian;
}			t_img;

typedef struct s_map {
	char	*fname;
	char	**map;
	char	**map2;
	int		map_width;
	int		map_height;
}			t_map;

typedef struct s_sides{
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
	char	*ceiling;
	char	*floor;
	int		ceilingcolor;
	int		floorcolor;
	char	*text_path;
}	t_sides;

typedef struct s_data{
	int			win_width;
	int			win_height;
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		mymap;
	t_img		img_south;
	t_img		img_north;
	t_img		img_east;
	t_img		img_west;
	t_img		img_cel;
	t_img		img_flo;
	t_img		img_walls;
	t_player	p;
	t_inter		inter_h;
	t_inter		inter_v;
	int			ray_east;
	int			ray_west;
	int			ray_north;
	int			ray_south;
	t_sides		sides;
	t_store		var;
}	t_data;

void	init_player(t_data *data);
void	init_mlx(t_data *data);
void	init_img(t_data *data);
char	**ft_free(char **copy, int j);
void	ft_putendl_fd(char *s, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
void	check_file(char *s);
char	**store_map(char *map, t_data *data);
char	**ft_split(char const *s, char c);
size_t	check_set(char c, char const *set);
char	*ft_strtrim(char const *s1, char const *set);
void	get_map(char *str, t_data *data);
void	ft_playerdirection(t_data *data, char c);
void	check_width_height(t_data *data);
char	*ft_strrchr(const char *str, int c);
void	raydis_h(int i, t_data *data);
void	raydis_v(int i, t_data *data);
int		ft_isdigit(int d);

// exit

int		free_number(char **rgb_c, char **rgb_f);
int		free_interval(char **rgb_c, char **rgb_f);
void	free_tabs(char **str);
void	exit_with_error(char *str);
void	free_and_close(t_store *var);
void	destroy_imgs(t_data *data);
int		mouse_move(int x, int y, t_data *ray);
int		ft_close(t_data *data);

// walls check

void	check_texture_h(t_data *data);
void	check_texture_v(t_data *data);
int		left_condition_1(t_data *data, t_vars *vars);
int		left_condition_2(t_data *data, t_vars *vars);
int		left_condition_3(t_data *data, t_vars *vars);
int		left_condition_4(t_data *data, t_vars *vars);
int		right_condition_4(t_data *data, t_vars *vars);
int		forward_condition_1(t_data *data, t_vars *vars);
int		forward_condition_2(t_data *data, t_vars *vars);
int		forward_condition_3(t_data *data, t_vars *vars);
int		forward_condition_4(t_data *data, t_vars *vars);
int		reverse_condition_1(t_data *data, t_vars *vars);
int		reverse_condition_2(t_data *data, t_vars *vars);
int		reverse_condition_3(t_data *data, t_vars *vars);
int		reverse_condition_4(t_data *data, t_vars *vars);

// lines check

int		check_lines_no(t_data *data, char *str);
int		check_lines_so(t_data *data, char *str);
int		check_lines_ea(t_data *data, char *str);
int		check_lines_we(t_data *data, char *str);
int		check_lines_c(t_data *data, char *str);
int		check_lines_f(t_data *data, char *str);

// map

char	**stor_tab(char **str);
int		check_tab(t_data *data);
int		checkmap_element(t_data *data);

// Hooks

int		close_window(int key, t_data *data);
int		_left(t_data *data);
int		_right(t_data *data);
int		_forward(t_data *data);
int		_backward(t_data *data);
int		release(int key, t_data *data);
int		press(int key, t_data *data);
int		render(t_data *data);
void	mlx_clear_put(t_data *data);

// libft

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	horizontal_intersection(t_data *data);
void	vertical_intersection(t_data *data);
double	distancebetweenpoints(double x1, double y1, double x2, double y2);
double	normalizeangle(double angle);

// horizontal intersection

void	upright_hintersect(t_data *data);
void	downright_hintersect(t_data *data);
void	downleft_hintersect(t_data *data);
void	upleft_hintersect(t_data *data);

// vertical intersection

void	upright_vintersect(t_data *data);
void	downright_vintersect(t_data *data);
void	downleft_vintersect(t_data *data);
void	upleft_vintersect(t_data *data);

// 3D render

void	topbotwallcoord(t_data *data, int i);
void	render3d(t_data *data);
void	usedraydistance_h(t_data *data, int i);
void	usedraydistance_v(t_data *data, int i);
void	draw_everything(t_data *data, int i, int textoffset_x);
int		checkbetweenwalls(double x, double y, t_data *data);
int		revcheckbetweenwalls(double x, double y, t_data *data);
int		leftcheckbetweenwalls(double x, double y, t_data *data);
int		rightcheckbetweenwalls(double x, double y, t_data *data);
void	draw_walls_west(t_data *data, int i, int xOffset);
void	draw_walls_east(t_data *data, int i, int x_offset);
void	draw_walls_north(t_data *data, int i, int x_offset);
void	draw_walls_south(t_data *data, int i, int x_offset);
int		iswallhited(double x, double y, t_data *data);
void	render3d(t_data *data);

// parse

void	check_newline_in_map(char *line, int *flag);
void	free_strings(char *tmp, t_store	*var);
void	init_textures(t_texture *texture);
char	*check_path(char *str);
char	*get_path(char *str);
int		commas_count(char *str);
int		check_doubles(char *str);
int		check_lines(char *str, t_data *data);
int		check_numbers(char *str);
int		check_interval(int nbr);
int		collect_data(t_data *data);
int		is_map(char *line);
int		check_textures(char **str);
int		check_colors(char **str);
int		one_before(char *str, int j);
int		one_after(char *str, int j);
int		one_up(char **str, int i, int j);
int		one_down(char **str, int i, int j);
int		one_before_space(char *str, int j);
int		one_after_space(char *str, int j);
int		one_up_space(char **str, int i, int j);
int		one_down_space(char **str, int i, int j);
void	get_data_address(t_data *data);

#endif
