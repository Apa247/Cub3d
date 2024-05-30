/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:55:05 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/30 21:41:51 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_get_map_edges(t_data *data, t_list **temp, int *start, int *end)
{
	int		i;
	char	*line;
	t_list	*aux;

	*start = INT32_MAX;
	*end = 0;
	aux = *temp;
	while (aux->next)
	{
		i = 0;
		line = (char *)aux->content;
		if (ft_empty_line(line))
			break ;
		while (ft_is_space(line[i]))
			i++;
		if (i < *start)
			*start = i;
		i = ft_strlen(line) - 1;
		while (ft_is_space(line[i]))
			i--;
		if (i > *end)
			*end = i;
		aux = aux->next;
	}
	data->map_width = *end - *start + 1;
	if (data->map_width >= 100)
		ft_exit(data, "Error: Map too wide!!\n");
}

void	ft_save_path(t_data *data, char *path, char *cardinal)
{
	if (!ft_strncmp(path, data->north_path, ft_strlen(path)))
		ft_exit(data, "Error: Duplicate texture!!\n");
	else if (!ft_strncmp(path, data->south_path, ft_strlen(path)))
		ft_exit(data, "Error: Duplicate texture!!\n");
	else if (!ft_strncmp(path, data->east_path, ft_strlen(path)))
		ft_exit(data, "Error: Duplicate texture!!\n");
	else if (!ft_strncmp(path, data->west_path, ft_strlen(path)))
		ft_exit(data, "Error: Duplicate texture!!\n");
	if (!ft_strncmp(cardinal, "NO", 2))
		data->north_path = ft_strdup(path);
	else if (!ft_strncmp(cardinal, "SO", 2))
		data->south_path = ft_strdup(path);
	else if (!ft_strncmp(cardinal, "EA", 2))
		data->east_path = ft_strdup(path);
	else if (!ft_strncmp(cardinal, "WE", 2))
		data->west_path = ft_strdup(path);
	return ;
}

int	ft_vertical_last(t_data *data, int i)
{
	int	j;

	j = data->map_height - 1;
	while (ft_is_space(data->map[j][i]))
		j--;
	if (data->map[j + 1][i] == '1')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ft_horizontal_left_last(const char *line, int i)
{
	int	j;

	j = i;
	while (j > 0 && !ft_is_space(line[j - 1]))
		j--;
	if (line[j] == '1')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ft_horizontal_right_last(const char *line, int i)
{
	int	j;

	j = i;
	while (!ft_is_space(line[j + 1]) && line[j + 1] != '\n')
		j++;
	if (line[j] == '1')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}