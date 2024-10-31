/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:53:00 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/07/03 12:33:13 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	In the ft_game() function:
        -> ft_initial_player_dir() will init the player's initial direction.
        -> ft_mlx_start() will start the mlx graphics library.
        -> ft_texture_start() will start the walls textures.
        -> ft_render_img)() will render the first image.
        -> ft_user_input() manages the user inputs (moves and rotations).	*/
static void	ft_game(t_data *data)
{
	ft_initial_player_dir(data);
	ft_mlx_start(data);
	ft_texture_start(data);
	ft_render_img(data);
	ft_user_input(data);
	mlx_loop(data->mlx);
	return ;
}

/* ft_check_args() function checks the number of arguments and the 
	extension. */
static int	ft_check_args(const int argc, const char **argv)
{
	int		i;
	int		ext_len;
	char	*ext;

	ext = ".cub";
	if (argc != 2)
	{
		perror("Error: Invalid number of arguments!!\n");
		return (EXIT_FAILURE);
	}
	else
	{
		ext_len = ft_strlen(argv[1]);
		i = ext_len - 4;
		while (i < ext_len)
		{
			if (argv[1][i] != ext[i - ext_len + 4])
			{
				perror("Error: Wrong file extension!!\n");
				return (EXIT_FAILURE);
			}
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

/*	The main() function:
		->	Initializes the principal t_data structure.
		->	Checks the arguments passed to the program.
		->	Reads the .cub file and save data to main structure.
		->	Prints the start menu.
		->	Starts the game.	*/
int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
	{
		perror("Error: error allocating memory!!\n");
		return (free(data), EXIT_FAILURE);
	}
	ft_data_init(data);
	if (ft_check_args(argc, (const char **)argv))
		return (ft_free_mem(data), free(data), EXIT_FAILURE);
	if (ft_parsing(data, argv[1]))
		return (ft_free_mem(data), free(data), EXIT_FAILURE);
	if (BONUS_FLAG)
		ft_print_menu_bonus();
	else
		ft_print_menu();
	ft_game(data);
	return (ft_free_mem(data), free(data), EXIT_SUCCESS);
}
