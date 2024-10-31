/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:20:07 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/01 18:56:45 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Sets a pixel in the image at the specified coordinates to the given color.
	 -> image->size_line / 4: the size of the line is divided by 4 to get the
		number of pixels in a line. This is because each pixel uses 4 bytes. */
void	ft_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

/*	Initializes the t_img structure fields to default values.	*/
void	ft_img_init(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}
