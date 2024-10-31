/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:58:25 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/01 12:13:58 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Handles key press events for the application:
	 -> If the Escape key is released, close the application.
	 -> If the movement/rotation keys are pressed it moves/rotates the player.
	 -> Finally returns EXIT_SUCCESSS.	*/
static int	ft_key_press(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_close(data);
	else if (key == XK_Left)
		data->player.rotate -= 1;
	else if (key == XK_Right)
		data->player.rotate += 1;
	else if (key == XK_w)
		data->player.move_y = 1;
	else if (key == XK_a)
		data->player.move_x = -1;
	else if (key == XK_s)
		data->player.move_y = -1;
	else if (key == XK_d)
		data->player.move_x = 1;
	return (EXIT_SUCCESS);
}

/*	Handles key release events for the application:
	 -> If the Escape key is released, close the application.
	 -> If the movement/rotation keys are released and the player is moving
		or is rotating, stops the player's movement/rotation.
	 -> Finally returns EXIT_SUCCESSS.	*/
static int	ft_key_release(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_close(data);
	else if (key == XK_w && data->player.move_y == 1)
		data->player.move_y = 0;
	else if (key == XK_s && data->player.move_y == -1)
		data->player.move_y = 0;
	else if (key == XK_a && data->player.move_x == -1)
		data->player.move_x = 0;
	else if (key == XK_d && data->player.move_x == 1)
		data->player.move_x = 0;
	else if (key == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	else if (key == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (EXIT_SUCCESS);
}

/*	This function sets up the event handlers for user input in a graphical
	application using the MiniLibX library; when key is pressed, when key is
	released and when window is closed.
	 -> If the BONUS_FLAG is set, also register a callback for mouse motion
		events.
	 -> mlx_loop_hook() sets a function to be called repeatedly at every loop
		iteration, used for rendering.
	 -> mlx_loop() starts the event loop, blocking the program execution here
	 	until the window is closed.	*/
void	ft_user_input(t_data *data)
{
	mlx_hook(data->window, DestroyNotify, NoEventMask, ft_close, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_key_press, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_key_release, data);
	if (BONUS_FLAG)
		mlx_hook(data->window, MotionNotify, PointerMotionMask, ft_mouse_motion,
			data);
	mlx_loop_hook(data->mlx, ft_render_loop, data);
	mlx_loop(data->mlx);
	return ;
}
