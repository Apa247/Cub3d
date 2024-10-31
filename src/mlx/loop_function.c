/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:09:37 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/29 01:27:59 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Handles the game rendering loop by checking if the player has moved and
	rendering the game state accordingly.
	 -> ft_player_move() updates the player's position and returns whether the
		player has moved.
	 -> data->player.has_moved tracks the player's movement to determine if
		rendering is needed.
	 -> ft_render_img() renders the updated game state if the player has moved.
	Returns: EXIT_SUCCESS when the loop completes.	*/
int	ft_render_loop(t_data *data)
{
	int	moved;

	moved = ft_player_move(data);
	data->player.has_moved = data->player.has_moved + moved;
	if (data->player.has_moved == 0)
		return (EXIT_SUCCESS);
	ft_render_img(data);
	return (EXIT_SUCCESS);
}
