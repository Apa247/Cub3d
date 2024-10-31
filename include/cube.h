/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:54:00 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/07/06 10:49:14 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# ifndef BONUS_FLAG
#  define BONUS_FLAG 1
# endif

//	INCLUDES:
////////////////////////////////////////////////////////////////////////////////

# include "../mlx_linux/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

//	KEYS:
////////////////////////////////////////////////////////////////////////////////

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_FORWARD 	126
# define KEY_BACKWARD	125

//	STRUCTS:EVENTS
////////////////////////////////////////////////////////////////////////////////

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_RELEASE	5
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_EXIT			17

//	CONSTANTS:
////////////////////////////////////////////////////////////////////////////////

# define TEST_FLAG				0
# define PI 					3.14159265359
# define WINDOW_WIDTH 			960
# define WINDOW_HEIGHT 			720
# define TEXTURE_SIZE 			64
# define MOVE_SPEED 			0.10
# define ROT_SPEED 				0.05
# define MOUSE_WINDOW_LIMIT		20	
//	Minimap:
# define MINIMAP_PXL_SIZE 		128
# define MINIMAP_DISTANCE 		5
# define MINIMAP_PLAYER_COLOR 	0x0000FF
# define MINIMAP_WALL_COLOR		0x990000
# define MINIMAP_FLOOR_COLOR 	0xdddddd
# define MINIMAP_SPACE_COLOR 	0x000000

//	ENUMS:
////////////////////////////////////////////////////////////////////////////////

enum e_texture_index
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3
};

//	STRUCTS:
////////////////////////////////////////////////////////////////////////////////

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}				t_player;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_texture
{
	int				x;
	int				y;
	int				size;
	int				index;
	double			step;
	double			pos;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				**texture_pixels;
	int				**texture;
}				t_texture;

typedef struct s_minimap
{
	int		size;
	int		tile_size;
	int		distance;
	int		offset_x;
	int		offset_y;
	char	**map;
	t_img	*img;
}				t_minimap;

typedef struct s_map
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			index_end_of_map;
}				t_map;

typedef struct s_data
{
	int			mouse_old_x;
	int			map_width;
	int			map_height;
	int			window_height;
	int			window_width;
	int			*floor;
	int			*ceiling;
	char		*north_path;
	char		*south_path;
	char		*east_path;
	char		*west_path;
	char		**map;
	void		*mlx;
	void		*window;
	t_list		*file;
	t_player	player;
	t_ray		ray;
	t_texture	texture;
	t_img		minimap_img;
	t_map		map_data;
}				t_data;

//  File src/main.c
int				main(int argc, char **argv);

//	File src/bonus/menu_bonus.c
void			ft_print_menu_bonus(void);

//	File src/bonus/minimap_image_bonus.c
void			ft_render_minimap_img(t_data *data, t_minimap *minimap);

//	File src/bonus/mlx_start__bonus.c
int				ft_mouse_motion(int x, int y, t_data *data);
void			ft_mlx_mouse(t_data *data);

//	File src/bonus/render_bonus.c
void			ft_render_minimap(t_data *data);

//  File src/mlx/loop_function.c
int				ft_render_loop(t_data *data);

//  File src/mlx/mlx_start.c
void			ft_mlx_img(t_data *data, t_img *image, int width, int height);
void			ft_texture_img(t_data *data, t_img *image, char *path);
void			ft_mlx_start(t_data *data);

//  File src/moves/input_handler.c
void			ft_user_input(t_data *data);

//  File src/moves/player_dir.c
void			ft_initial_player_dir(t_data *data);

//  File src/moves/player_move.c
int				ft_player_move(t_data *data);

//  File src/moves/player_pos.c
int				ft_move_validation(t_data *data, double new_x, double new_y);

//  File src/moves/player_rotate.c
int				ft_player_rotate(t_data **data);

//  File src/parsing/checks.c
int				ft_check_textures_dup(t_data *data, const char *line);
int				ft_check_map_dup(t_data *data, const char *line);
void			ft_check_invalid_chars(t_data *data, t_list **temp);

//  File src/parsing/colors_aux.c
char			*ft_read_number(const char *str, int *i);
void			ft_check_comma(t_data *data, const char *str, int *i);
void			ft_check_end(t_data *data, const char *str, int *i);

//  File src/parsing/colors.c
int				ft_floor_rgb(t_data *data, const char *str);
int				ft_ceiling_rgb(t_data *data, const char *str);

//  File src/parsing/map.c
int				ft_check_if_map(t_data *data, t_list **temp);

//  File src/parsing/parse.c
int				ft_empty_line(const char *line);
int				ft_parsing(t_data *data, char *map_path);

//  File src/parsing/rgb_to_hex.c
unsigned long	ft_rgb_to_hex(int *rgb);

//  File src/parsing/textures.c
int				ft_check_texture(t_data *data, const char *line,
					char *cardinal);
int				ft_check_floor(t_data *data, const char *line);
int				ft_check_ceiling(t_data *data, const char *line);

//  File src/parsing/utils.c
void			ft_get_map_edges_2(t_data *data, int *start, int *end);
void			ft_get_map_edges(t_data *data, t_list **temp, int *start,
					int *end);
void			ft_save_path(t_data *data, char *path, char *cardinal);

//  File src/parsing/utils2.c
int				ft_vertical_last(t_data *data, int i);
int				ft_horizontal_left_last(const char *line, int i);
int				ft_horizontal_right_last(const char *line, int i);

//  File src/render/raycasting.c
int				ft_raycasting(t_player *player, t_data *data);

//	File src/render/render.c
void			ft_render_img(t_data *data);

//	File src/render/texture.c
void			ft_texture_pixels_update(t_data *data, t_texture *tex,
					t_ray *ray, int x);

//  File src/utils/close.c
void			ft_exit(t_data *data, char *error);
int				ft_close(t_data *data);

//  File src/utils/free_mem.c
void			ft_free_matrix(void **tab);
void			ft_free_mem(t_data *data);

//  File src/utils/menu.c
void			ft_print_menu(void);

//  File src/utils/struct_data.c
void			ft_texture_img(t_data *data, t_img *image, char *path);
void			ft_data_init(t_data *data);

//  File src/utils/struct_img.c
void			ft_image_pixel(t_img *image, int x, int y, int color);
void			ft_img_init(t_img *img);

//  File src/utils/struct_ray.c
void			ft_ray_init(t_ray *ray);

//  File src/utils/struct_texture.c
void			ft_texture_pixels_init(t_data *data);
void			ft_texture_init(t_data *data);
void			ft_texture_start(t_data *data);

//  File tests/print_info.c
void			ft_print_file(t_list *file);
void			ft_print_info(t_data *data);

//	COLORS:
////////////////////////////////////////////////////////////////////////////////

# define RESET	"\e[0m"

# define BOLD	"\e[1m"
# define DIM	"\e[2m"
# define ITAL	"\e[3m"
# define ULINE	"\e[4m"

# define BLACK	"\e[30m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"
# define WHITE	"\e[37m"

# define BG_BLACK	"\e[40m"
# define BG_RED		"\e[41m"
# define BG_GREEN	"\e[42m"
# define BG_YELLOW	"\e[43m"
# define BG_BLUE	"\e[44m"
# define BG_PURPLE	"\e[45m"
# define BG_CYAN	"\e[46m"
# define BG_WHITE	"\e[47m"

#endif