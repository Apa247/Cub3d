/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:35:44 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/01 18:50:11 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Allocates memory for the map array in the t_data structure.	*/
static void	ft_calloc_map(t_data *data)
{
	int	i;

	i = 0;
	data->map = ft_calloc(100, sizeof(char *));
	if (!data->map)
		ft_exit(data, "Error: Malloc failed!!\n");
	while (i < 100)
	{
		data->map[i] = ft_calloc(100, sizeof(char));
		if (!data->map[i])
			ft_exit(data, "Error: Malloc failed!!\n");
		i++;
	}
	data->mlx = NULL;
	data->window = NULL;
	return ;
}

/*	Initializes all relevant fields in the t_data structure.	*/
void	ft_data_init(t_data *data)
{
	data->mouse_old_x = WINDOW_HEIGHT / 2;
	data->map_width = -1;
	data->map_height = -1;
	data->window_height = WINDOW_HEIGHT;
	data->window_width = WINDOW_WIDTH;
	data->floor = NULL;
	data->ceiling = NULL;
	data->north_path = NULL;
	data->south_path = NULL;
	data->east_path = NULL;
	data->west_path = NULL;
	ft_calloc_map(data);
	data->mlx = NULL;
	data->window = NULL;
	ft_texture_init(data);
	return ;
}
