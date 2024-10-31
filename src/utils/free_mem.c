/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:02:42 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/01 18:48:33 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Frees a given variable if it is not NULL.	*/
static void	ft_free_var(void *var)
{
	if (var)
		free(var);
	return ;
}

/*	Frees all textures and and texture_pixels in the t_data structure.	*/
static void	ft_free_texture(t_data *data)
{
	if (data->texture.texture[NORTH])
		free(data->texture.texture[NORTH]);
	if (data->texture.texture[EAST])
		free(data->texture.texture[EAST]);
	if (data->texture.texture[SOUTH])
		free(data->texture.texture[SOUTH]);
	if (data->texture.texture[WEST])
		free(data->texture.texture[WEST]);
	if (data->texture.texture)
		free(data->texture.texture);
	if (data->texture.texture_pixels)
		ft_free_matrix((void **)data->texture.texture_pixels);
	return ;
}

/*	Frees a 2D array (matrix) and the array itself, and sets the pointer
	to NULL.	*/
void	ft_free_matrix(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
	return ;
}

/*	Frees all allocated memory in the t_data structure.	*/
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
	ft_free_texture(data);
	ft_lstclear(&(data->file), &free);
	return ;
}
