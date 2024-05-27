/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:32:40 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/20 21:13:02 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int  ft_read_file(t_data *data, char *map_path)
{
    int     fd;
    char    *line;
    t_list   *new_line;

    fd = open(map_path, R_OK);
	if (fd < 0)
		return (EXIT_FAILURE);
	if (read(fd, &line, 0) < 0)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	data->file = ft_lstnew(line);
	line = get_next_line(fd);
	while (line)
    {
        new_line = ft_lstnew(line);
		ft_lstadd_back(&(data->file), new_line);
        line = get_next_line(fd);
    }
    //ft_print_file(data->file);
	close(fd);
    return (EXIT_SUCCESS);
}

static int  ft_check_lines(t_data *data, const char *line, t_list **temp)
{
    if (ft_check_textures_dup(data, line) == EXIT_FAILURE)
    {
        perror("Error: Some texture is defined more than once!!\n");
        return (EXIT_FAILURE);
    }
    else if (ft_check_map_dup(data, line) == EXIT_FAILURE)
    {
        perror("Error: More than one map in file!!\n");
        return (EXIT_FAILURE);
    }
    else if (ft_check_texture(data, line, "NO") == EXIT_FAILURE &&
        ft_check_texture(data, line, "SO") == EXIT_FAILURE &&
        ft_check_texture(data, line, "EA") == EXIT_FAILURE &&
        ft_check_texture(data, line, "WE") == EXIT_FAILURE &&
        ft_check_floor(data, line) == EXIT_FAILURE &&
        ft_check_ceiling(data, line) == EXIT_FAILURE &&
        ft_check_if_map(data,temp) == EXIT_FAILURE)
    {
        perror("Error: Invalid line!!\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int  ft_empty_line(const char *line)
{
    int     i;

    i = 0;
    while (ft_is_space(line[i]))
        i++;
    if (line[i] == '\0' || line[i] == '\n')
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int ft_parsing(t_data *data, char *map_path)
{
    char    *line;
    t_list  *temp;

    if (ft_read_file(data, map_path))
    {
        perror("Error: File can't be readed!!\n");
        return (EXIT_FAILURE);
    }
    temp = data->file;
    line = (char *)temp->content;
    while (temp->next)
    {
        if (ft_empty_line((line)))
            temp = temp->next;
        else if (ft_check_lines(data, line, &temp))
            return (EXIT_FAILURE);
        else
            temp = temp->next;
        if (temp)
            line = (char *)temp->content;
        else
            break ;
    }
    ft_print_info(data);
    return (EXIT_SUCCESS);
}