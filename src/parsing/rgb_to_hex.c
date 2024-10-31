/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:02:59 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/02 01:54:08 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
/*	Converts RGB values to an hexadecimal value.	*/
unsigned long	ft_rgb_to_hex(int *rgb)
{
	int				r;
	int				g;
	int				b;
	unsigned long	result;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}
