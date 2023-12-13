/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:26:59 by abel-hid          #+#    #+#             */
/*   Updated: 2023/12/13 21:33:46 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../../MLX42/include/MLX42/MLX42.h"
# include <string.h>
# define ESC 256
# define W 87
# define S 83
# define A 65
# define D 68
# define LEFT 263
# define RIGHT 262
# define DOWN 264
# define UP 265
# define WIDTH 800
# define HEIGHT 800
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define TEXTURE_NO 0
# define TEXTURE_SO 1
# define TEXTURE_WE 2
# define TEXTURE_EA 3

typedef struct s_ray
{
	double	ray_angle;
	double	wall_hit_x;
	double	ray_distance;
	double	wall_hit_xt;
	double	wall_hit_yt;
	double	wall_hit_y;
	int		was_hit_vertical;
	int		is_ray_facing_up;
	int		is_ray_facing_down;
	int		is_ray_facing_left;
	int		is_ray_facing_right;
	int		wall_hit_content;
}				t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	double	fov;
	double	angle;
	double	number_rays;
}				t_player;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_map_2d
{
	int	xmin;
	int	ymin;
	int	x;
	int	y;
}				t_map_2d;
typedef struct s_map
{
	char		**map;
	int			map_width;
	int			map_height;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_color		floor;
	t_color		ceiling;
	t_player	*player;
}				t_map;

typedef struct s_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*img1;
	t_map			*map;
	t_ray			ray[WIDTH];
	mlx_texture_t	*texture;
	mlx_texture_t	*ptr[4];
	t_map_2d		map_2d;
	double			correct_distance;
	double			projection_distance;
	int				texture_index;
	int				i;
	double			wall_strip_heightt;
	int				y;
	int				y1;
	int				s[64][64];
}				t_mlx;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_get_line(char **str, char **line, int new_line);
char	*get_rest(char **str, int new_line);
int		ft_check_new_line(char *str);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_free(char **s);
int		size_line(char *line);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_file(char *file);
int		is_space(char c);
char	*skip_space(char *line);
int		is_digit(char c);
int		init_floor(t_map *map, char *ptr);
int		parsing_coma(char *line);
int		valid_range(int r, int g, int b);
int		init_ceiling(t_map *map, char *line);
int		size_line(char *line);
int		get_height(t_map *map);
int		get_width(char *line);
double	ft_sqrt(t_mlx *win, int x, int y, int i);
double	x_step_checker(double ray_angle, double x_step);
double	y_step_checker(double ray_angle, double ystep);
double	horizget_the_distance(t_mlx *win, double ray_angle, int i);
double	vertget_the_distance(t_mlx *win, double ray_angle, int i);
int		has_wall(t_mlx *win, double x, double y);
void	init_map(t_map *map, int size);
int		count_lines(char *str);
int		parsing_floor_ceiling(char **line);
int		is_empty(char *line);
char	*my_strdup(char *line);
int		get_floor(char *line, int *k, t_map *map);
int		get_east_texture(char *line, int *k, t_map *map);
int		get_west_texture(char *line, int *k, t_map *map);
int		get_south_texture(char *line, int *k, t_map *map);
int		get_north_texture(char *line, int *k, t_map *map);
int		check_empty_line(char *line, t_map *map);
void	all_texture(t_map *map, char *line, int *k);
int		get_ceiling(char *line, int *k, t_map *map);
void	get_map(t_map *map, int *k, int *i, char *line);
int		init_all(t_map *map, int fd, char *str);
char	*next_line(int *cout, char *line, int fd);
void	ft_free_map(t_map **map);
void	free_empty_line(t_map *map, int *i);
int		get_longest_line(t_map *map);
int		check_valid_map(t_map *map);
int		valid_position(t_map *map);
int		check_player_position(t_map *map);
int		update_map(t_map *map);
void	init_widht_height(t_map *map);
int		check_wall(t_map *map);
int		valid_walls(t_map *map);
int		valid_wall_help(t_map *map, int i, int j);
int		front_wall(char *line);
int		back_wall(char *line);
int		wall_check(t_map *map);
int		get_player_position(t_map *map);
int		open_texture(t_map *map);
int		parsing_map(t_map *map, int fd, char *str);
void	init__map(t_map *map);
void	moveright(t_mlx *mlx, double speed);
void	moveleft(t_mlx *mlx, double speed);
void	movebackward(t_mlx *mlx, double speed);
void	moveforward(t_mlx *mlx, double speed);
void	hook_stuff(void *params);
double	radians_to_degrees(double radians);
double	degrees_to_radians(double degrees);
int		check_wall_collision(t_mlx *win, double xx, double yy);
void	re_draw(t_mlx *win);
void	render_3d(t_mlx *win);
void	raycast(t_mlx *win);
void	adraw(t_mlx *win);
int		has_wall(t_mlx *win, double x, double y);
int		check_whichside(t_mlx *win);
void	set_the_vision_angle(t_mlx *win, int side);
void	init_params(t_mlx *win);
int		check_intersection(t_mlx *win, int x, int y);
int		check_upordown(double ray_angle);
int		check_leftorrigh( double ray_angle);
int		has_wall(t_mlx *win, double x, double y);
double	compare_distance(double a, double b, t_mlx *win, int i);
size_t	get_color(int r, int g, int b, int a);
size_t	texture_color(t_mlx *win, int w);
size_t	floor_color(t_mlx *win);
size_t	ceiling_color(t_mlx *win);
int		check_whichtexture(t_mlx *win, int i);
void	init_texture(t_mlx *win);
double	ft_sqrt1(t_mlx *win, int xinter, int yinter, int i);
void	ft_free_window(t_mlx **window);
void	_close_win(void *param);
void	mlx(t_mlx *window);
int		check_map(int ac, char **av);
int		init_mlx(t_mlx *window, int fd, char **av);
#endif
