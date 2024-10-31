/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:55:05 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/25 12:21:47 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_get_map_edges_2(t_data *data, int *start, int *end)
{
	data->map_width = *end - *start + 1;
	if (data->map_width >= 100)
		ft_exit(data, "Error: Map too wide!!\n");
}

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
	ft_get_map_edges_2(data, start, end);
}

void	ft_save_path(t_data *data, char *path, char *cardinal)
{
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
