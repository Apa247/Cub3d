/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:22:08 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/06 21:17:38 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    ft_print_file(t_list *file)
{
    t_list  *temp;

    temp = file;
    while (temp->next)
    {
        printf("%s\n", (char *)temp->content);
        temp = temp->next;

    }
    printf("%s\n", (char *)temp->content);
    return ;
}

void    ft_print_info(t_data *data)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    printf("\nMap width: %d\n", data->map_width);
    printf("Map height: %d\n", data->map_height);
    printf("\nFloor: %d, %d, %d\n", data->floor[0], data->floor[1], data->floor[2]);
    printf("Ceiling: %d, %d, %d\n", data->ceiling[0], data->ceiling[1], data->ceiling[2]);
    printf("\nNorth path: %s\n", data->north_path);
    printf("South path: %s\n", data->south_path);
    printf("East path: %s\n", data->east_path);
    printf("West path: %s\n", data->west_path);
    printf("\nMap:\n");
    while (data->map[i][0])
    {
        while (data->map[i][j])
        {
            printf("%c", data->map[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
    return ;
}
