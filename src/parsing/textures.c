/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 00:53:42 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/02 14:52:09 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Counts the words of a line and finishes the program if there are more or
	less words than expected.*/
static int	ft_count_words(t_data *data, const char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!ft_is_space(str[i]))
		{
			words++;
			while (str[i] && !ft_is_space(str[i]))
				i++;
		}
		else
			i++;
	}
	if (words != 2)
		ft_exit(data, "Error: Texture line with many elements!!\n");
	return (EXIT_SUCCESS);
}

/*	Checks the path passed as argument to validate it is a valid file.	*/
static int	ft_check_path(t_data *data, char *path, char cardinal)
{
	if (open(path, R_OK) < 0)
	{
		if (cardinal == 'N')
			perror("Error: North texture can't be opened!!\n");
		else if (cardinal == 'S')
			perror("Error: South texture can't be opened!!\n");
		else if (cardinal == 'E')
			perror("Error: East texture can't be opened!!\n");
		else if (cardinal == 'W')
			perror("Error: West texture can't be opened!!\n");
		else if (cardinal == 'F')
			perror("Error: Floor texture can't be opened!!\n");
		else if (cardinal == 'C')
			perror("Error: Ceiling texture can't be opened!!\n");
		ft_free_mem(data);
		exit(EXIT_FAILURE);
	}
	close(open(path, R_OK));
	return (EXIT_SUCCESS);
}

/*	Checks and saves the paths for the different textures.	*/
int	ft_check_texture(t_data *data, const char *line, char *cardinal)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i] == cardinal[0] && line[i + 1] == cardinal[1])
	{
		ft_count_words(data, line);
		i = i + 2;
		while (line[i] && ft_is_space(line[i]))
			i++;
		path = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
		if (!path)
			ft_exit(data, "Error: Malloc failed!!\n");
		while (line[i] && !ft_is_space(line[i]))
			path[j++] = line[i++];
		path[j] = '\0';
		ft_save_path(data, path, cardinal);
		ft_check_path(data, path, cardinal[0]);
		return (free(path), EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/*	Checks if the line are the RGB floor values and calls the 
	corresponding function to manage them.*/
int	ft_check_floor(t_data *data, const char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i] == 'F' && line[i + 1] == ' ')
	{
		if (ft_floor_rgb(data, line))
			ft_exit(data, "Error: Invalid RGB values!!\n");
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/*	Checks if the line are the RGB ceiling values and calls the 
	corresponding function to manage them.*/
int	ft_check_ceiling(t_data *data, const char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i] == 'C' && line[i + 1] == ' ')
	{
		if (ft_ceiling_rgb(data, line))
			ft_exit(data, "Error: Invalid RGB values!!\n");
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
