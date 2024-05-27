/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:22:54 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/20 23:59:41 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void ft_invalid_chars(t_data *data, char *line, int *count)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1' && !ft_is_space(line[i]) && line[i] != 'N'
            && line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && line[i] != '0')
            ft_exit(data, "Error: Invalid character in map!!\n");
        if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
            (*count)++;
        if (*count > 1)
            ft_exit(data, "Error: More than one player!!\n");
        i++;
    }
    return ;
}

int ft_check_textures_dup(t_data *data, const char *line)
{
    int i;

    i = 0;
    while (line[i] && ft_is_space(line[i]))
        i++;
    if ((line[i] ==  'N' && data->north_path != NULL) ||
        (line[i] ==  'S' && data->south_path != NULL) ||
        (line[i] ==  'E' && data->east_path != NULL) ||
        (line[i] ==  'W' && data->west_path != NULL) ||
        (line[i] ==  'F' && data->floor != NULL) ||
        (line[i] ==  'C' && data->ceiling != NULL))
    {
        perror("Error: Some texture is defined more than once!!\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int ft_check_map_dup(t_data *data, const char *line)
{
    int i;

    i = 0;
    while (line[i] && ft_is_space(line[i]))
        i++;
    if (line[i] == '1' && ft_strlen(data->map[0]) > 0)
    {
        perror("Error: Map is defined more than once!!\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

void    ft_check_invalid_chars(t_data *data, t_list **temp)
{
    int     count;
    char    *line;
    t_list  *aux;

    count = 0;
    aux = *temp;
    line = (char*)aux->content;
    ft_invalid_chars(data, line, &count);
    while (aux->next)
    {
        aux = aux->next;
        line = (char*)aux->content;
        ft_invalid_chars(data, line, &count);
    }
    return ;
}