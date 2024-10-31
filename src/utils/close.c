/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:06:31 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/06 10:47:30 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Exits the application with an error message.
	 -> Prints the error message using perror().
	 -> If minimap image and mlx instance are present, destroys the minimap
	 	image.
	 -> If window and mlx instance are present, destroys the window.
	 -> If mlx instance is present, destroys the display, ends the loop, and
	 	frees mlx.
	 -> Frees all allocated memory and exits the program with EXIT_FAILURE
	 	status.	*/
void	ft_exit(t_data *data, char *error)
{
	perror(error);
	if (data->minimap_img.img && data->mlx)
		mlx_destroy_image(data->mlx, data->minimap_img.img);
	if (data->window && data->mlx)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	ft_free_mem(data);
	free(data);
	exit(EXIT_FAILURE);
}

/*	Closes the application gracefully.
	 -> Prints a goodbye message to the console.
	 -> If window and mlx instance are present, destroys the window.
	 -> If mlx instance is present, destroys the display, ends the loop, and
	 	frees mlx.
	 -> Frees all allocated memory and exits the program with EXIT_SUCCESS
	 	status.	*/
int	ft_close(t_data *data)
{
	printf(WHITE "\nGame closed!! Come to play again soon :)\n\n");
	if (data->window && data->mlx)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	ft_free_mem(data);
	free(data);
	exit(EXIT_SUCCESS);
}
