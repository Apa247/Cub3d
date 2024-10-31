/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:59:20 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/01 12:47:02 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Validates the passed player's position within the map boundaries:
	 -> If BONUS_FLAG is not set, checks if the new position is within the
	 	map width and height constraints, returning EXIT_FAILURE if it is not.
	 -> If BONUS_FLAG is set, checks if the new position does not contain
	 	a wall ('1'), returning EXIT_SUCCESS if valid.
	 -> Returns EXIT_SUCCESS if position is valid, otherwise EXIT_FAILURE.	*/
static bool	ft_valid_pos(t_data *data, double x, double y)
{
	if (!BONUS_FLAG)
	{
		if (x < 0.50 || x >= data->map_width - 1.25)
			return (EXIT_FAILURE);
		if (y < 0.25 || y >= data->map_height -0.25)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	if (BONUS_FLAG)
	{
		if (data->map[(int)y][(int)x] != '1')
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/*	Validates AND updates the player's position if the new coordinates are
	valid:
	 -> Calls ft_valid_pos() to check if the new x coordinate is valid.
	 	If valid, updates the player's x position and sets variable moved
		to EXIT_SUCCESS.
	 -> Calls ft_valid_pos() to check if the new y coordinate is valid.
	 	If valid, updates the player's y position and sets variable moved
		to EXIT_SUCCESS.
	 -> Returns variable moved to indicate if any movement was successful
	 	(EXIT_SUCCESS) or not (EXIT_FAILURE).	*/
int	ft_move_validation(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = EXIT_FAILURE;
	if (ft_valid_pos(data, new_x, data->player.pos_y) == EXIT_SUCCESS)
	{
		data->player.pos_x = new_x;
		moved = EXIT_SUCCESS;
	}
	if (ft_valid_pos(data, data->player.pos_x, new_y) == EXIT_SUCCESS)
	{
		data->player.pos_y = new_y;
		moved = EXIT_SUCCESS;
	}
	return (moved);
}
