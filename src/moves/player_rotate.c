/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:59:35 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/01 18:41:20 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	First at all:
	 -> rotspeed = ROT_SPEED * (*data)->player.rotate, it means if player.rotate
		is 0, there will be no rotation. If it is 1, we'll have the current 
		ROT_SPEED.
	We calculate the new direction in each axis such that the magnitude of the
	direction remains the same.
	Demo:
	
	dir_x ^ 2 + dir_y ^ 2 = h ^ 2
	(dir_x * cos rotspeed - dir_y * sin rotspeed) ^ 2 +   
	(dir_x * sin rotspeed + dir_y * cos rotspeed) ^ 2 = h ^ 2

	so:

	dir_x ^ 2 + dir_y ^ 2 = (dir_x * cos rotspeed - dir_y * sin rotspeed) ^ 2
	+ (dir_x * sin rotspeed + dir_y * cos rotspeed) ^ 2
	
	so:
	
	dir_x ^ 2 + dir_y ^ 2 = 
	dir_x ^ 2 * ((sin rotspeed) ^ 2 + (cos rotspeed) ^ 2) + 
	dir_y ^ 2 * ((cos rotspeed) ^ 2 + (sin rotspeed) ^ 2) =
	dir_x ^ 2 * 1 + dir_y ^ 2 * 1 = dir_x ^ 2 + dir_y ^ 2
	
	Then we make the same for the plane direction.
*/
int	ft_player_rotate(t_data **data)
{
	double		rotspeed;
	double		temp;

	rotspeed = ROT_SPEED * (*data)->player.rotate;
	(*data)->player.rotate = 0;
	temp = (*data)->player.dir_x;
	(*data)->player.dir_x = (*data)->player.dir_x * cos(rotspeed)
		- (*data)->player.dir_y * sin(rotspeed);
	(*data)->player.dir_y = temp * sin(rotspeed)
		+ (*data)->player.dir_y * cos(rotspeed);
	temp = (*data)->player.plane_x;
	(*data)->player.plane_x = (*data)->player.plane_x * cos(rotspeed)
		- (*data)->player.plane_y * sin(rotspeed);
	(*data)->player.plane_y = temp * sin(rotspeed)
		+ (*data)->player.plane_y * cos(rotspeed);
	return (1);
}
