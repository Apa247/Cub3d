/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:01:49 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/05 19:15:31 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Initializes ray parameters based on the current column index:
	* x -> Represents the current column index on the screen where raycasting
		   calculations are performed. It determines the horizontal position of
		   the ray as it scans across the screen from left to right.
	* camera_x -> Where is the camera. From -1 for left to 1 for right (0 is
				  center).		 
	* dir_x/y -> the initial direction of the ray, adjusted by the player's
				orientation.
	* map_x/y -> current square of the ray.
	* deltadist_x/y -> distance to go to the next x or y.	*/
static void	ft_raycasting_info(int x, t_ray *ray, t_player *player)
{
	ft_ray_init(ray);
	ray->camera_x = (2 * x / (double)WINDOW_WIDTH) - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

/*	Sets up the parameters for the Digital Differential Analyzer (DDA)
	algorithm:
	 -> ray->sidedist_? is the distance from the ray start position to the
		next x or y position
	So we do:
	 -> Determines the step direction in x and y based on the ray's direction.
	 -> Calculates the initial side distance (distance to the next x or y
		boundary) for both directions.
	These calculations prepare the ray for stepping through the grid cells
	during the raycasting process.	*/
static void	ft_set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

/*
- We implement the DDA algorithm -> the loop will increment 1 square
-   until we hit a wall
- If the sidedistx < sidedisty, x is the closest point from the ray
*/

/*	Implements the Digital Differential Analyzer (DDA) algorithm to trace the
	path of the ray:
	 -> The loop continues incrementing by one grid square until it encounters
	 	a wall using sidedist_x and sidedist_y.
	 -> Updates ray->map_x and ray->map_y accordingly based on the step
	 	direction (step_x and step_y).
	 -> Sets ray->side to 0 for horizontal intersections and 1 for vertical
	 	intersections.
	Additional checks:
	 -> Breaks the loop if the ray moves out of the map boundaries.
	 -> Terminates the loop if a wall ('1') is hit in the map data.	*/
static void	ft_run_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x = ray->sidedist_x + ray->deltadist_x;
			ray->map_x = ray->map_x + ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y = ray->sidedist_y + ray->deltadist_y;
			ray->map_y = ray->map_y + ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > data->map_height - 0.25
			|| ray->map_x > data->map_width - 1.25)
			break ;
		else if (data->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

/*	Calculates various parameters related to the ray's interaction with walls:
	 -> Computes ray->wall_dist based on the distance to the nearest wall.
	 -> Determines ray->line_height using the window height and ray->wall_dist,
		line_height represents the height in pixels of the wall that will be
		drawn on the screen for a specific column. This height depends on the
		distance from the player's camera to the point where the ray intersects
		the wall.
	 -> Sets ray->draw_start and ray->draw_end to define the vertical extents
		of the wall slice to be drawn.
	 -> Adjusts ray->draw_start and ray->draw_end to ensure they do not exceed
	 	the window boundaries.
	 -> Computes ray->wall_x to determine the exact x-coordinate of the wall hit,
	 	adjusting for fractional parts.
	These calculations prepare the ray's properties for rendering the 3D
	projection of walls onto the screen.
*/
static void	ft_line_length(t_ray *ray, t_data *data, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->wall_dist = ray->sidedist_y - ray->deltadist_y;
	ray->line_height = (int)(data->window_height / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + data->window_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->window_height / 2;
	if (ray->draw_end >= data->window_height)
		ray->draw_end = data->window_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

/*	Raycasting will be calculated in 5 steps;
	1. Initialize raycasting info for the current column.
	2. Set up the Digital Differential Analyzer (DDA) for the ray.
	3. Run the DDA to find the intersection point with a wall.
	4. Calculate the line length and other relevant data.
	5. Update the texture pixels for the current column based on the
	ray. */
int	ft_raycasting(t_player *player, t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = data->ray;
	while (x < data->window_width)
	{
		ft_raycasting_info(x, &ray, player);
		ft_set_dda(&ray, player);
		ft_run_dda(data, &ray);
		ft_line_length(&ray, data, player);
		ft_texture_pixels_update(data, &data->texture, &ray, x);
		x++;
	}
	return (EXIT_SUCCESS);
}
