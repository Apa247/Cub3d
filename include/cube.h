/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:54:00 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/28 02:41:30 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "stdio.h"
# include "stdlib.h"
# include "math.h"
# include "stdbool.h"
# include "../mlx_linux/mlx.h"
# include "libft/libft.h"
# include <stdint.h>
# include <X11/Xlib.h>

# define PI 3.14159265359

typedef struct s_game
{
    void    *mlx;
    void    *mlx_window;
    int     win_size_x;
    int     win_size_y;
}              t_game;

typedef struct s_data
{
    int     map_width;
    int     map_height;
    int     *floor;
    int     *ceiling;
    char    *north_path;
    char    *south_path;
    char    *east_path;
    char    *west_path;
    char    **map;
    t_list  *file;
    t_game  *game;
}               t_data;



//  File src/main.c
//static void ft_init_data(t_data *data);
//static int  ft_check_args(const int argc, const char **argv);
int	        main(int argc, char **argv);

//  File src/parsing/checks.c
//static void ft_invalid_chars(t_data *data, char *line, int *count);
int         ft_check_textures_dup(t_data *data, const char *line);
int         ft_check_map_dup(t_data *data, const char *line);
void        ft_check_invalid_chars(t_data *data, t_list **temp);

//  File src/parsing/colors.c
//static char *ft_read_number(const char *str, int *i);
//static void ft_check_comma(t_data *data, const char *str, int *i);
//static void ft_check_end(t_data *data, const char *str, int *i);
int         ft_floor_rgb(t_data *data, const char *str);
int         ft_ceiling_rgb(t_data *data, const char *str);

//  File src/parsing/map.c
//static void ft_upper_map_line(t_data *data, const char *line,
//            const int start, const int end);
//static void ft_bottom_map_line(t_data *data, const char *line,
//            const int start, const int end);
//static void ft_map_line(t_data *data, const char *line,
//            const int start, const int end);
//static void ft_read_map(t_data *data, t_list **temp, const int start,
//            const int end);
int         ft_check_if_map(t_data *data, t_list **temp);

//  File src/parsing/parse.c
//static int  ft_read_file(t_data *data, char *map_path);
//static int  ft_check_lines(t_data *data, const char *line, t_list **temp);
int         ft_empty_line(const char *line);
int         ft_parsing(t_data *data, char *map_path);

//  File src/parsing/textures.c
//static int  ft_count_words(t_data *data, const char *str);
//static int  ft_check_path(t_data *data, char *path, char cardinal);
int         ft_check_texture(t_data *data, const char *line, char *cardinal);
int         ft_check_floor(t_data *data, const char *line);
int         ft_check_ceiling(t_data *data, const char *line);

//  File src/parsing/utils.c
void        ft_get_map_edges(t_data *data, t_list **temp, int *start, int *end);
void        ft_save_path(t_data *data, char *path, char *cardinal);
int         ft_vertical_last(t_data *data, int i);
int         ft_horizontal_left_last(const char *line, int i);
int         ft_horizontal_right_last(const char *line, int i);

//  File tests/print_file.c
void        ft_print_file(t_list *file);
void        ft_print_info(t_data *data);

//  File src/utils/free_mem.c
void        ft_free_mem(t_data *data);
void        ft_exit(t_data *data, char *error);


#endif