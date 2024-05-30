/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 01:39:40 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/05/30 21:44:15 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_free_var(void *var)
{
	if (var)
		free(var);
	return ;
}

void	ft_free_mem(t_data *data)
{
	int	i;

	i = 0;
	ft_free_var(data->floor);
	ft_free_var(data->ceiling);
	ft_free_var(data->north_path);
	ft_free_var(data->south_path);
	ft_free_var(data->east_path);
	ft_free_var(data->west_path);
	while (i < 100)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	ft_lstclear(&(data->file), &free);
	return ;
}

void	ft_exit(t_data *data, char *error)
{
	perror(error);
	if (data->game)
		free(data->game);
	ft_free_mem(data);
	free(data);
	exit(EXIT_FAILURE);
}