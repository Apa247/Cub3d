/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:58:46 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/03 22:13:08 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Sets the player's direction and plane vectors based on the initial direction
	(if it is North or South).
	 -> If the player's direction is 'S', sets direction to (0, 1) and plane
		to (-0.66, 0).
	 -> If the player's direction is 'N', sets direction to (0, -1) and plane
		to (0.66, 0).	
	These vectors are perpendicular, of course.	*/
static void	ft_north_south_axis(t_player *player)
{
	if (player->dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (player->dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	return ;
}

/*	Sets the player's direction and plane vectors based on the initial direction
	(if it is East or West).
	 -> If the player's direction is 'W', sets direction to (-1, 0) and plane
		to (0, -0.66).
	 -> If the player's direction is 'E', sets direction to (1, 0) and plane
	 	to (0, 0.66).
	These vectors are perpendicular, of course.	*/
static void	ft_east_west_axis(t_player *player)
{
	if (player->dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	return ;
}

/*	Initializes the player's direction and plane vectors based on the initial
	direction of the player specified in the map .cub (N, E, S or W) calling
	helper functions to set the vectors for North-South and East-West directions.
	Considerations:
	 -> The direction vector will be a bit longer than the camera plane, so the
		FOV will be smaller than 90° (more precisely, the FOV is:
		2 * atan(0.66/1.0)=66°
		which is perfect for a first person shooter game).
	 -> Dir vector and plane vector have to be perpendicular.
	NOTE: In most graphics libraries and game engines, the Y-axis increases
	downward on the screen and decreases upward, which is why dir_y for North
	and South appears to be "reversed." Similarly, dir_x=1 indicates that the
	player is "looking" to the right, which means East, and dir_x=-1 means West.
*/
void	ft_initial_player_dir(t_data *data)
{
	ft_north_south_axis(&data->player);
	ft_east_west_axis(&data->player);
	return ;
}
