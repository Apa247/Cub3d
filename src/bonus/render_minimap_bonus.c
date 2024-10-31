/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:01:40 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/06 10:49:52 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Calculates the starting offset for the minimap rendering based on the
	player's position (x or y). This ensures that the minimap is centered
	around the player within the map bounds. Samples:
	 -> mapsize: 20
	 -> minimap->distance: 3
	 -> minimap->size: 7 (porque (2 * 3) + 1 = 7)
	 -> If the player is near the left edge, offset is 0 (e.g., pos = 2,
	 	offset = 0).
	 -> If the player is centered, offset centers the minimap (e.g., pos = 10,
	 	offset = 7).
	 -> If the player is near the right edge, offset adjusts to fit within the
	 	map (e.g., pos = 18, offset = 13).
	Returns: the calculated offset for rendering the minimap, it means the
	coordinate of the map where the minimap starts.	*/
static int	ft_minimap_offset(t_minimap *minimap, int mapsize, int pos)
{
	if (pos > minimap->distance && mapsize - pos > minimap->distance + 1)
		return (pos - minimap->distance);
	if (pos > minimap->distance && mapsize - pos <= minimap->distance + 1)
		return (mapsize - minimap->size);
	return (0);
}

/*	Returns true if size > coord, false if not.	*/
static bool	ft_valid_coordinate(int coord, int size)
{
	if (coord < size)
		return (true);
	return (false);
}

/*	Creates a single line of the minimap based on the player's position and
	the map data. It first allocates memory for a line of the minimap and
	populates it with characters representing the player, walls, and open
	spaces, taking into account the necessary offsets.
	 -> minimap->size: the total number of tiles in each dimension
		(width and height) of the minimap.
 	 -> ft_valid_coordinate() checks if the coordinate is within the bounds
	 	of the map.
 	 -> 'P' represents the player's position.
 	 -> '1' represents a wall.
 	 -> '0' represents an open space.
	 -> '\0' represents an invalid coordinate or unrecognized character.
	Returns: a pointer to the created line (char *), or NULL if memory
	allocation fails.	*/
static char	*ft_add_line(t_data *data, t_minimap *mm, int y)
{
	char	*line;
	int		x;

	line = ft_calloc(mm->size + 1, sizeof(line));
	if (!line)
		return (NULL);
	x = 0;
	while (x < mm->size && x < data->map_width)
	{
		if (!ft_valid_coordinate(y + mm->offset_y, data->map_height)
			|| !ft_valid_coordinate(x + mm->offset_x, data->map_width))
			line[x] = '\0';
		else if ((int)data->player.pos_x == (x + mm->offset_x)
			&& (int)data->player.pos_y == (y + mm->offset_y))
			line[x] = 'P';
		else if (data->map[y + mm->offset_y][x + mm->offset_x] == '1')
			line[x] = '1';
		else if (data->map[y + mm->offset_y][x + mm->offset_x] == '0')
			line[x] = '0';
		else
			line[x] = '\0';
		x++;
	}
	return (line);
}

/*	Creates a minimap based on the game map, showing walls, open spaces,
	and the player's position iterating through the y axis data to build
	the simplified horizontal lines representation (x axis) that will be
	rendered later.
 	 -> minimap.size: the total number of tiles in each dimension
	 	(width and height) of the minimap.
	 -> ft_add_line() adds a line to the minimap for each row.
	 -> ft_free_matrix() frees the allocated memory if an error occurs
	 	during creation.
	Returns: a pointer to the created minimap (char **), or NULL if memory
	allocation fails.	*/
static char	**ft_create_minimap(t_data *data, t_minimap *minimap)
{
	char	**mini_map;
	int		y;

	mini_map = ft_calloc(minimap->size + 1, sizeof(mini_map));
	if (!mini_map)
		return (NULL);
	y = 0;
	while (y < minimap->size && y < data->map_height)
	{
		mini_map[y] = ft_add_line(data, minimap, y);
		if (!mini_map[y])
		{
			ft_free_matrix((void **)mini_map);
			return (NULL);
		}
		y++;
	}
	return (mini_map);
}

/*	Renders the minimap on the screen based on a simplified representation of
	the game map, showing walls, open spaces, and the player's position. It 
	calculates the necessary offsets to ensure the minimap is centered around
	the player, then iterates through the map data to draw each element at the 
	correct position on the minimap.
	 -> distance: number of visible tiles from the player.
	 -> mimimap.size: the total number of tiles in each dimension (width and
	 	height) of the minimap.
	 -> offset: the position where the minimap starts to keep the player
	 	centered.
	 -> ft_create_minimap() will creeate the minimap.
	 -> ft_render_minimap_img() will draw the minimap on the screen.
	 -> ft_free_matrix() frees the allocated memory for the 
		char **mimimap.map.	*/
void	ft_render_minimap(t_data *data)
{
	t_minimap	minimap;

	minimap.map = NULL;
	minimap.img = &data->minimap_img;
	minimap.distance = MINIMAP_DISTANCE;
	minimap.size = (2 * minimap.distance) + 1;
	minimap.tile_size = MINIMAP_PXL_SIZE / (2 * minimap.distance);
	minimap.offset_x = ft_minimap_offset(&minimap,
			data->map_width, (int)data->player.pos_x);
	minimap.offset_y = ft_minimap_offset(&minimap,
			data->map_height, (int)data->player.pos_y);
	minimap.map = ft_create_minimap(data, &minimap);
	if (!minimap.map)
		ft_exit(data, "Error: Malloc failed!!\n");
	ft_render_minimap_img(data, &minimap);
	ft_free_matrix((void **)minimap.map);
	return ;
}
