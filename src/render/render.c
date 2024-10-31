/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:02:04 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/05 20:01:48 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Sets the color of a pixel in the image based on the raycasting results or
	ceiling/floor colors:
	 -> If data->texture.texture_pixels[y][x] > 0, sets the pixel color using
		ft_image_pixel() with the corresponding texture color.
	 -> If y < data->window_height / 2, sets the pixel color to ceiling color.
	 -> If y >= data->window_height / 2, sets the pixel color to floor color.
	Remember the origin (0, 0) is at the top-left corner of the screen. */
static void	ft_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->texture.texture_pixels[y][x] > 0)
		ft_image_pixel(image, x, y, data->texture.texture_pixels[y][x]);
	else if (y < data->window_height / 2)
		ft_image_pixel(image, x, y, data->texture.hex_ceiling);
	else
		ft_image_pixel(image, x, y, data->texture.hex_floor);
}

/*	Renders a frame of the game scene onto the screen:
	 -> Initializes an image structure (image) using ft_mlx_img() with
	 	dimensions data->window_width and data->window_height.
	 -> Iterates through each pixel in the window using nested loops.
	 -> Calls ft_frame_image_pixel() to set the color of each pixel in the image
		based on the raycasting results or background colors.
	 -> Displays the rendered image on the game window using
		mlx_put_image_to_window().
	 -> Destroys the image after rendering to free memory resources using
		mlx_destroy_image().	*/
static void	ft_render_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	ft_mlx_img(data, &image, data->window_width, data->window_height);
	y = 0;
	while (y < data->window_height)
	{
		x = 0;
		while (x < data->window_width)
		{
			ft_frame_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
	return ;
}

/*	Renders the entire game scene:
	 -> Initializes the texture pixel buffer where the raycasting results will
		be stored via ft_texture_pixels_init().
	 -> ft_ray_init() initializes the ray structure with default values.
	 -> Executes the raycasting algorithm to calculate visibility and textures
		for each column of the screen.
	 -> Renders the calculated frame onto the screen via ft_render_frame().
	 -> If the BONUS_FLAG is set, ft_render_minimap() renders an additional
		minimap overlay.	*/
void	ft_render_img(t_data *data)
{
	ft_texture_pixels_init(data);
	ft_ray_init(&data->ray);
	ft_raycasting(&data->player, data);
	ft_render_frame(data);
	if (BONUS_FLAG)
		ft_render_minimap(data);
	return ;
}
