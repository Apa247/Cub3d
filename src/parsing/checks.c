/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:22:54 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/02 01:47:00 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Sets the initial player position on the map.	*/
static void	ft_get_player(t_data *data, char dir, int i, double *y)
{
	if (dir == 'N')
	{
		data->player.dir = 'N';
		data->player.pos_y = *y + 0.5;
		data->player.pos_x = i + 0.5;
	}
	else if (dir == 'S')
	{
		data->player.dir = 'S';
		data->player.pos_y = *y + 0.5;
		data->player.pos_x = i + 0.5;
	}
	else if (dir == 'E')
	{
		data->player.dir = 'E';
		data->player.pos_y = *y + 0.5;
		data->player.pos_x = i + 0.5;
	}
	else if (dir == 'W')
	{
		data->player.dir = 'W';
		data->player.pos_y = *y + 0.5;
		data->player.pos_x = i + 0.5;
	}
	return ;
}

/*	Checks if there are invalid characters on the map or if there are more
	than one player.	*/
static void	ft_invalid_chars(t_data *data, char *line, int *count, double *y)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && !ft_is_space(line[i]) && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != '0')
			ft_exit(data, "Error: Invalid character in map!!\n");
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
		{
			(*count)++;
			ft_get_player(data, line[i], i, y);
		}
		if (*count > 1)
			ft_exit(data, "Error: More than one player!!\n");
		i++;
	}
	return ;
}

/*	Reads all the lines to check if there are invalid chars using the
	ft_invalid_chars() function.	*/
void	ft_check_invalid_chars(t_data *data, t_list **temp)
{
	int		count;
	double	y;
	char	*line;
	t_list	*aux;

	count = 0;
	aux = *temp;
	line = (char *)aux->content;
	y = 0;
	ft_invalid_chars(data, line, &count, &y);
	while (aux->next)
	{
		aux = aux->next;
		line = (char *)aux->content;
		y++;
		ft_invalid_chars(data, line, &count, &y);
	}
	return ;
}

/*	Checks if some texture is defined more than once in the .cub file.	*/
int	ft_check_textures_dup(t_data *data, const char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if ((line[i] == 'N' && data->north_path != NULL)
		|| (line[i] == 'S' && data->south_path != NULL)
		|| (line[i] == 'E' && data->east_path != NULL)
		|| (line[i] == 'W' && data->west_path != NULL)
		|| (line[i] == 'F' && data->floor != NULL)
		|| (line[i] == 'C' && data->ceiling != NULL))
	{
		perror("Error: Some texture is defined more than once!!\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*	Checks if there are more than one map in the .cub file.	*/
int	ft_check_map_dup(t_data *data, const char *line)
{
	int	i;

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
