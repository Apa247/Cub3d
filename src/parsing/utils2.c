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
