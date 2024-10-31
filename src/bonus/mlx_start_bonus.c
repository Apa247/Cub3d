/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:06:18 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/02 19:33:03 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	This function handles mouse motion events for the game. It is designed to
	rotate the player's view based on the mouse's position relative to the
	window's width:
	- x: The current x-coordinate of the mouse.
	- y: The current y-coordinate of the mouse.
	- data: A pointer to the game's data structure.
	The function first checks if the mouse is near the edges of the window, if
	so resets the mouse's x-position to the limit (for both saides). If not, if
	the mouse's x-coordinate is fewer than the last position, it triggers a
	player rotation to the left,if the x-coordinate is higher then it
	triggers a rotation to the right. The rotation is performed by the 
	ft_player_rotate() function. */
int	ft_mouse_motion(int x, int y, t_data *data)
{
	if (x > data->window_width - MOUSE_WINDOW_LIMIT)
	{
		x = data->window_width - MOUSE_WINDOW_LIMIT;
		mlx_mouse_move(data->mlx, data->window, x, y);
	}
	else if (x < MOUSE_WINDOW_LIMIT)
	{
		x = MOUSE_WINDOW_LIMIT;
		mlx_mouse_move(data->mlx, data->window, x, y);
	}
	else if (x < data->mouse_old_x)
	{
		data->player.rotate -= 1;
		data->player.has_moved += ft_player_rotate(&data);
	}
	else if (x > data->mouse_old_x)
	{
		data->player.rotate += 1;
		data->player.has_moved += ft_player_rotate(&data);
	}
	data->mouse_old_x = x;
	return (EXIT_SUCCESS);
}

/*	This function centers the mouse cursor in the game window.
	It is typically called to reset the mouse position after processing mouse
	movement events, ensuring the cursor remains at the center of the window.
	This technique is often used in 	first-person games to allow for
	continuous mouse movement without the cursor leaving the window.
	The function uses the `mlx_mouse_move` function provided by the MLX library
	to set the mouse position. It calculates the center of the window using the
	window's width and height, then moves the mouse to this central position.
	This helps in creating a seamless experience for rotating or looking
	around in the game without the mouse cursor hitting the edges of the
	window.	*/
void	ft_mlx_mouse(t_data *data)
{
	mlx_mouse_move(data->mlx, data->window, data->window_width / 2,
		data->window_height / 2);
	return ;
}
