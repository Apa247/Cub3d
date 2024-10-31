/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:02:15 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/05 19:44:35 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Determines the texture index based on the ray's side and direction.
	 -> If the ray hits a vertical wall (side 0), checks the x-direction of the
   		ray.
	 -> If the ray hits a horizontal wall (side 1), checks the y-direction of
	 	the ray. 
	 -> It saves the cardinal point to data->texture.index.	*/
static void	ft_texture_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->texture.index = WEST;
		else
			data->texture.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->texture.index = SOUTH;
		else
			data->texture.index = NORTH;
	}
}

/*	Updates the texture pixels for the screen column based on the ray
	properties.
	 -> Determines the texture index using ft_texture_index().
	 -> Calculates the texture's x-coordinate based on the wall hit position.
		Multiplying ray->wall_x (between 0 and 1) by texture->size gives the
		exact X coordinate within the texture where the ray hits.
     -> Adjusts the x-coordinate for texture mirroring if needed. This
		adjustment is made to mirror the texture horizontally when necessary:
			ray->side == 0 means the ray hit a vertical wall (west or east).
			ray->dir_x < 0 means the ray was moving to the left (towards the
			west).
			ray->side == 1 means the ray hit a horizontal wall (north or south).
			ray->dir_y > 0 means the ray was moving downwards (towards the
			south).
		In these cases, texture->x is adjusted to mirror the texture
		horizontally:
			texture->size - texture->x - 1
		is the calculation that performs this mirroring. If
			texture->x was 32
		then:
			texture->size - texture->x - 1 will be 31
		thus inverting the horizontal position within the texture.
	 -> Calculates the texture step for vertical scaling. Since ray->line_height
		is the height of the wall slice on the screen and texture->size is the
		size of the texture, the step size tells us how much we need to move
		vertically in the texture for each pixel we draw on the screen. For
		instance, if ray->line_height is greater than texture->size, it means
		the wall slice on the screen is taller than the texture. Therefore,
		the step size will be less than 1, ensuring that each screen pixel
		corresponds to a fraction of a texture pixel.
	 -> Initializes the texture position for the current column.
		(ray->draw_start - data->window_height / 2 + ray->line_height / 2)
		effectively calculates the offset of draw_start from the center of the
		wall slice. This gives the starting point of the wall slice relative to
		the middle of the screen.
		Multiplying by the texture->step, converting it from screen space to
		texture space. Remember texture->step is the amount we need to step
		through the texture for each pixel on the screen.
	 -> Loops through each pixel in the column within the draw range.
    	 -> Calculates the texture's y-coordinate and updates the texture
		 	position.The line:
			texture->y = (int)texture->pos & (texture->size - 1);
			ensures that the texture coordinate texture->y wraps around
			correctly, enabling texture mapping using the efficient bitwise AND
			operation, assuming the texture size is a POWER OF 2. This is a
			common technique in graphics programming to optimize performance
			and ensure accurate texture sampling. For instance, if texture->size
			is 64: texture->size - 1 is 63, which in binary is 00111111.
			Texture Wrapping: let's assume texture->pos is 130. Converting it to
			an integer gives 130. Applying the bitwise AND operation with 63
			(00111111) results in:
			130 & 63 = 2 since 130 in binary is 10000010, and:
			10000010 & 00111111 is 00000010
    	 -> Retrieves the color from the texture at the calculated coordinates.
    	 -> Darkens the color if the texture index is NORTH or EAST.
			color >> 1:
			This shifts the binary value of the color to the right by 1 bit. It
			means this operation divides the color value by 2, effectively
			reducing its intensity.
			& 8355711:
			This is a bitwise mask applied to (color >> 1). The constant 8355711
			in binary is 100000000000000111111111, which means all bits are
			active except for the 3 least significant bits. This bitwise AND
			operation preserves only the 21 most significant bits of the color,
			which can adjust the color for a shadow or transparency effect.
    	 -> Updates the pixel in the texture_pixels array if the color is valid.
		 */
void	ft_texture_pixels_update(t_data *data, t_texture *texture,
			t_ray *ray, int x)
{
	int			y;
	int			color;

	ft_texture_index(data, ray);
	texture->x = (int)(ray->wall_x * texture->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		texture->x = texture->size - texture->x - 1;
	texture->step = 1.0 * texture->size / ray->line_height;
	texture->pos = (ray->draw_start - data->window_height / 2
			+ ray->line_height / 2) * texture->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		texture->y = (int)texture->pos & (texture->size - 1);
		texture->pos = texture->pos + texture->step;
		color = data->texture.texture[texture->index]
		[texture->size * texture->y + texture->x];
		if (texture->index == NORTH || texture->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->texture.texture_pixels[y][x] = color;
		y++;
	}
}
