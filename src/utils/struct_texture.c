/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:04:45 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/04 01:21:07 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/* Converts an XPM image to an image buffer.
	 -> Calls ft_texture_img() to load the XPM image into the image structure.
	 -> Allocates memory for the buffer and copies the pixel data from the
	 	image structure to the buffer.
	 -> Frees the image structure from memory and returns the buffer containing
	 	the image pixels. This returned buffer will be saved to
		data->texture.texture[CARDINAL]*/
static int	*ft_xpm_to_img(t_data *data, char *path)
{
	int		x;
	int		y;
	int		*buffer;
	t_img	image;

	ft_texture_img(data, &image, path);
	buffer = ft_calloc(1,
			sizeof(buffer) * data->texture.size * data->texture.size);
	if (!buffer)
		ft_exit(data, "Error: Malloc failed!!\n");
	y = 0;
	while (y < data->texture.size)
	{
		x = 0;
		while (x < data->texture.size)
		{
			buffer[y * data->texture.size + x]
				= image.addr[y * data->texture.size + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, image.img);
	return (buffer);
}

/* Initializes the texture pixel array in the t_data structure. */
void	ft_texture_pixels_init(t_data *data)
{
	int	i;

	i = 0;
	if (data->texture.texture_pixels)
		ft_free_matrix((void **)data->texture.texture_pixels);
	data->texture.texture_pixels = ft_calloc(data->window_height + 1,
			sizeof(data->texture.texture_pixels));
	if (!data->texture.texture_pixels)
		ft_exit(data, "Error: Malloc failed!!\n");
	while (i < data->window_height)
	{
		data->texture.texture_pixels[i] = ft_calloc(data->window_width + 1,
				sizeof(data->texture.texture_pixels));
		if (!data->texture.texture_pixels[i])
			ft_exit(data, "Error: Malloc failed!!\n");
		i++;
	}
}

/* Initializes the texture structure in the t_data structure. */
void	ft_texture_init(t_data *data)
{
	data->texture.x = 0;
	data->texture.y = 0;
	data->texture.size = TEXTURE_SIZE;
	data->texture.index = 0;
	data->texture.step = 0.0;
	data->texture.pos = 0.0;
	data->texture.hex_floor = 0x0;
	data->texture.hex_ceiling = 0x0;
	data->texture.texture = ft_calloc(5, sizeof(data->texture.texture));
	if (!data->texture.texture)
		ft_exit(data, "Error: Malloc failed!!\n");
	return ;
}

/*	Loads the textures from the file paths specified in the char **
	t_data->texture.texture, calling ft_xpm_to_img() to load 
	each texture image.*/
void	ft_texture_start(t_data *data)
{
	data->texture.texture[NORTH] = ft_xpm_to_img(data, data->north_path);
	data->texture.texture[EAST] = ft_xpm_to_img(data, data->east_path);
	data->texture.texture[SOUTH] = ft_xpm_to_img(data, data->south_path);
	data->texture.texture[WEST] = ft_xpm_to_img(data, data->west_path);
}
