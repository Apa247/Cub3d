/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:03:07 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/04 01:09:26 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Creates a new MLX image and initializes the image structure for rendering.
	 -> ft_img_init(image): initializes the image structure to default values.
	 -> mlx_new_image() creates a new image with the specified width and height.
	 -> mlx_get_data_addr() retrieves the address of the image data and other
		image properties.	*/
void	ft_mlx_img(t_data *data, t_img *image, int width, int height)
{
	ft_img_init(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
		ft_exit(data, "Error: not possible to create mlx image!!\n");
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

/*	Loads a XPM file to an image:
	First at all it initializes the fields of the image structure to default
	values via ft_img_init(). Then loads a texture image from a file (path)
	and initializes the image structure for rendering.
	 -> ft_img_init(image): initializes the image structure.
	 -> mlx_xpm_file_to_image() loads the XPM file specified by path and
		creates an MLX image.
	 -> mlx_get_data_addr() retrieves the address of the image data and other
		image properties.	*/
void	ft_texture_img(t_data *data, t_img *image, char *path)
{
	ft_img_init(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->texture.size,
			&data->texture.size);
	if (image->img == NULL)
		ft_exit(data, "Error: not possible to create mlx texture!!\n");
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

/*	Initializes the MLX library and creates a new window with the specified
	width and height for rendering the game.
	 -> ft_mlx_mouse() sets up mouse-related functionality if the BONUS_FLAG
		is set.
	Parameters:
	 -> data: A pointer to the game's data structure, which includes MLX and
		window handles.	*/
void	ft_mlx_start(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_exit(data, "Error: mlx_init failed!!\n");
	data->window = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Cube");
	if (!data->window)
		ft_exit(data, "Error: mlx_new_window failed!!\n");
	if (BONUS_FLAG)
		ft_mlx_mouse(data);
	return ;
}
