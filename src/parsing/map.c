/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:31:48 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/21 01:31:01 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void ft_upper_map_line(t_data *data, const char *line,
            const int start, const int end)
{
    int i;

    i = start;
    while (line [i] && i < end)
    {
        if (line[i] == '\n')
            break;
        else if (line[i] != '1' && line[i] != ' ')
            ft_exit(data, "Error: Invalid upper edge in map!!\n");
        else
        {
            data->map[0][i] = line[i];
            i++;
        }
    }
    data->map[0][i] = '\0';
    return ;
}

static void ft_bottom_map_line(t_data *data, const char *line,
            const int start, const int end)
{
    int i;

    i = start;
    while (line [i] && i < end)
    {
        if (line[i] == '\n')
            break ;
        else if (line[i] != '1' && line[i] != ' ')
            ft_exit(data, "Error: Invalid bottom edge in map!!\n");
        else
        {
            if (ft_is_space(line[i]) && !ft_vertical_last(data, i))
                ft_exit(data, "Error: Map not closed!!\n");
            data->map[data->map_height - 1][i] = line[i];
            i++;
        }
    }
    data->map[data->map_height - 1][i] = '\0';
    return ;
}

static void ft_map_line(t_data *data, const char *line,
            const int start, const int end)
{
    int     i;

    i = start;
    while (line[i] && i < end && line[i] != '\n')
    {
        while (ft_is_space(line[i]))
        {
            data->map[data->map_height - 1][i] = line[i];
            i++;
        }
        if (line[i] != '1')
            ft_exit(data, "Error: Invalid edge in map!!\n");
        while (line[i] != ' ' && line[i] != '\n')
        {
            if (ft_horizontal_left_last(line, i) ||
                ft_horizontal_right_last(line, i) ||
                !ft_vertical_last(data, i))
                ft_exit(data, "Error: Invalid edge in map!!\n");
            data->map[data->map_height - 1][i] = line[i];
            i++;
        }
    }
    data->map[data->map_height - 1][i] = '\0';
    return ;
}

static void ft_read_map(t_data *data, t_list **temp, const int start,
            const int end)
{
    char    *line;

    ft_check_invalid_chars(data, temp);
    line = (char*)(*temp)->content;
    ft_upper_map_line(data, line, start, end);
    data->map_height = 1;
    while ((*temp)->next)
    {
        (*temp) = (*temp)->next;
        line = (char*)(*temp)->content;
        if (ft_empty_line(line))
            break ;
        data->map_height++;
        if (data->map_height >= 100)
            ft_exit(data, "Error: Map too high\n");
        if ((*temp)->next && !ft_empty_line((char*)(*temp)->next->content))
            ft_map_line(data, line, start, end);
        else
            ft_bottom_map_line(data, line, start, end);
    }
    return ;
}

int  ft_check_if_map(t_data *data, t_list **temp)
{
    int     i;
    int     start;
    int     end;
    char    *line;

    i = 0;
    line = (char*)(*temp)->content;
    while (ft_is_space(line[i]))
        i++;
    if (line[i] == '1')
    {
        ft_get_map_edges(data, temp, &start, &end);
        if (data->map_width < 0)
            ft_exit(data, "Error: Invalid map!!\n");
        ft_read_map(data, temp, start, end);
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
}
