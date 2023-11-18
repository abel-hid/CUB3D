/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:26:59 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/18 12:35:03 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# include <stdio.h>
# include <stdlib.h>

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
// # include <mlx.h>
#include "./MLX42/include/MLX42/MLX42.h"
# include <string.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
#define HEIGHT 720
#define WIDTH 1080
#define KEY_ESC 256
typedef struct	s_player
{
    int	x;
    int	y;

}				t_player;

typedef struct  s_color
{
    int r;
    int g;
    int b;
}               t_color;

typedef struct	s_map
{
    char	**map;
    int	map_width;
    int	map_height;
    char     *no;
    char     *so;
    char     *we;
    char     *ea;
    t_color  floor;
    t_color  ceiling;
    t_player player;
}				t_map;

typedef struct s_win
{
    mlx_t *mlx;
    mlx_image_t *img;  
    t_player player;
}           t_win;


char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_get_line(char **str, char **line, int new_line);
char	*get_rest(char **str, int new_line);
int		ft_check_new_line(char *str);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_free(char **s);
int size_line(char *line);
char	*ft_strtrim(char const *s1, char const *set);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


#endif



// 111111
// 100101
// 101001 map[i-1][j]
// 1101N1 map[i][j - 1] | map[i][j + 1]
// 11 1111 map[i+1][j]
// 1111111