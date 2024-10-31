/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:59:01 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/01 12:39:26 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Attempts to move the player forward based on the current direction and
	MOVE_SPEED, it means calculates the new x and y positions, and validates
	the move (ft_move_validation() function).
	 -> If the move is valid, returns 1 indicating the player has moved.
	 -> If the move is not valid, returns 0 in dicating no moves.
	Returns: 1 if the move is successful, otherwise 0.	*/
static int	ft_move_player_front(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * MOVE_SPEED;
	new_y = data->player.pos_y + data->player.dir_y * MOVE_SPEED;
	if (ft_move_validation(data, new_x, new_y) == EXIT_SUCCESS)
		return (1);
	return (0);
}

/*	Attempts to move the player backward based on the current direction and
	MOVE_SPEED, it means calculates the new x and y positions, and validates
	the move (ft_move_validation() function).
	 -> If the move is valid, returns 1 indicating the player has moved.
	 -> If the move is not valid, returns 0 in dicating no moves.
	Returns: 1 if the move is successful, otherwise 0.	*/
static int	ft_move_player_back(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_x * MOVE_SPEED;
	new_y = data->player.pos_y - data->player.dir_y * MOVE_SPEED;
	if (ft_move_validation(data, new_x, new_y) == EXIT_SUCCESS)
		return (1);
	return (0);
}

/*	Attempts to move the player to the left based on the current direction and
	MOVE_SPEED, it means calculates the new x and y positions, and validates
	the move (ft_move_validation() function).
	 -> If the move is valid, returns 1 indicating the player has moved.
	 -> If the move is not valid, returns 0 in dicating no moves.
	Returns: 1 if the move is successful, otherwise 0.	*/
static int	ft_move_player_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_y * MOVE_SPEED;
	new_y = data->player.pos_y - data->player.dir_x * MOVE_SPEED;
	if (ft_move_validation(data, new_x, new_y) == EXIT_SUCCESS)
		return (1);
	return (0);
}

/*	Attempts to move the player to the right based on the current direction
	and MOVE_SPEED, it means calculates the new x and y positions, and
	validates the move (ft_move_validation() function).
	 -> If the move is valid, returns 1 indicating the player has moved.
	 -> If the move is not valid, returns 0 in dicating no moves.
	Returns: 1 if the move is successful, otherwise 0.	*/
static int	ft_move_player_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_y * MOVE_SPEED;
	new_y = data->player.pos_y + data->player.dir_x * MOVE_SPEED;
	if (ft_move_validation(data, new_x, new_y) == EXIT_SUCCESS)
		return (1);
	return (0);
}

/*	Handles the player's movement and rotation based on the current input
	states:
	The ft_render_loop() function is continuously calling this function, and
	each time this function is called, it checks if a movement has occurred,
	i. e., if the user has pressed a key and therefore the
	ft_key_press() function has modified some data->player.move_?. 
	If so, it updates the position accordingly calling the apropietate funcion
	ft_move_player_dir?() or ft_move_player_rotate().
	Returns: The total number of movements made.	*/
int	ft_player_move(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved = moved + ft_move_player_front(data);
	if (data->player.move_y == -1)
		moved = moved + ft_move_player_back(data);
	if (data->player.move_x == -1)
		moved = moved + ft_move_player_left(data);
	if (data->player.move_x == 1)
		moved = moved + ft_move_player_right(data);
	if (data->player.rotate != 0)
		moved = moved + ft_player_rotate(&data);
	return (moved);
}
