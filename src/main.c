/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:53:00 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/19 19:33:13 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void ft_init_data(t_data *data)
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

int	main(int argc, char **argv)
{
    t_data  *data;

    data = ft_calloc(sizeof(t_data), 1);
    if (!data)
        return (perror("error in malloc"), free(data), EXIT_FAILURE);
    ft_init_data(data);
    if (ft_check_args(argc, (const char **)argv))
    {
        ft_free_mem(data);
        free(data);
        return (EXIT_FAILURE);
    }
    if (ft_parsing(data, argv[1]))
    { 
        //printf("************************\n");  
        ft_free_mem(data);
        free(data);
        return (EXIT_FAILURE);
    }
    ft_free_mem(data);
    free(data);
    return (EXIT_SUCCESS);
}