/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:53:00 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/28 03:14:44 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    ft_init_game(t_data *data)
{
    data->game = ft_calloc(sizeof(t_game), 1);
    if (!data->game)
        ft_exit(data, "error in memory");
    data->game->mlx = NULL;
    data->game->mlx_window = NULL;
    data->game->win_size_y = 10;
    data->game->win_size_x = 0;
}

void    ft_init_data(t_data *data)
{
    int i;

    i = 0;
    data->map_width = -1;
    data->map_height = -1;
    data->floor = NULL;
    data->ceiling = NULL;
    data->north_path = NULL;
    data->south_path = NULL;
    data->east_path = NULL;
    data->west_path = NULL;
    data->map = ft_calloc(sizeof(char *),  100);
    if (!data->map)
        ft_exit(data, "Error: Malloc failed!!\n");
    while (i < 100)
    {
        data->map[i] = ft_calloc(sizeof(char), 100);
        if (!data->map[i])
            ft_exit(data, "Error: Malloc failed!!\n");
        i++;
    }
    return ;
}

static int  ft_check_args(const int argc, const char **argv)
{
    int     i;
    int     ext_len;
    char    *ext;

    ext = ".cub";
    if (argc != 2)
    {
        perror("Error: Invalid number of arguments!!\n");
        return (EXIT_FAILURE);
    }
    else
    {
        ext_len = ft_strlen(argv[1]);
        i = ext_len - 4;
        while (i < ext_len)
        {
            if (argv[1][i] != ext[i - ext_len + 4])
            {
                perror("Error: Wrong file extension!!\n");
                return (EXIT_FAILURE);
            }
            i++;
        }
    }
    return (EXIT_SUCCESS);
}

void    get_screen_size(t_data *data)
{
    Display *display;
    Screen  *screen;

    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        perror("Can't open fullscreen: ");
        data->game->win_size_x = 800;
        data->game->win_size_y = 800;
        return;
    }
    screen = DefaultScreenOfDisplay(display);
    data->game->win_size_x = screen->width;
    data->game->win_size_y = screen->height;
    XCloseDisplay(display);
}

void    start_game(t_data *data)
{
    t_game  *aux;

    aux = data->game;
    aux->mlx = mlx_init();
    if (!aux->mlx)
        ft_exit(data, "Error in mlx_init");
    get_screen_size(data);
    aux->mlx_window = mlx_new_window(aux->mlx, aux->win_size_x, aux->win_size_y, "Cub3d");
    if (!aux->mlx_window)
        ft_exit(data, "Error in mlx_window");
    mlx_loop(aux->mlx);
}

int	main(int argc, char **argv)
{
    t_data  *data;

    data = ft_calloc(sizeof(t_data), 1);
    if (!data)
        return (perror("error in malloc"), free(data), EXIT_FAILURE);
    ft_init_data(data);
    ft_init_game(data);
    if (ft_check_args(argc, (const char **)argv))
        return (ft_free_mem(data), free(data->game), free(data), EXIT_FAILURE);
    if (ft_parsing(data, argv[1]))
        return (ft_free_mem(data), free(data->game), free(data), EXIT_FAILURE);
    start_game(data);
    return (ft_free_mem(data), free(data), EXIT_SUCCESS);
}