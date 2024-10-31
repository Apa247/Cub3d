Minilib:

https://github.com/42Paris/minilibx-linux

Raycasting:

https://lodev.org/cgtutor/raycasting.html

The general outline of the program is as follows:

1. Arguments are checked.

2. Parsing is done:

   -> All files are in the parsing folder.

   -> There is one and only one texture for each cardinal direction.

   -> The texture files exist and are valid.

   -> There are no duplicate textures.

   -> There are correct RGB values for floor and ceiling.

   -> There is only one map, and it only contains 0, 1, and a cardinal point (N, E, S, W).

   -> There is only one initial cardinal point in the map.

   -> The map walls are closed.

3. Then ft_game() function is called, where the game runs:

   a) The initial dir and plane vectors are set depending on the initial direction of the player.

   b) ft_mlx_start() opens a new window with the dimensions specified in cube.h for the game.

   c) Through the function ft_texture_start(), the files containing the textures for the four directions are read, and their information (if correct) is stored in the main data structure char **data->texture.texture[cardinal]. This way, the four textures are stored in the main structure so they can be accessed whenever necessary.

   d) Then the function ft_render_img() is called. This function allocates memory for the texture_pixels array (which stores the color of each pixel on the screen) and initiates the raycasting process. To do this:

      * Rays are computed based on the initial parameters (position, direction, map, window sizes).
      * ft_set_dda() and ft_run_dda() are the functions in charge of managing the DDA algorithm.
      * Through the function ft_line_length(), the distance to the walls is calculated, which determines the size of objects and how many pixels they should occupy on the screen.
      * Finally, ft_texture_pixels_update() is responsible for updating each pixel based on the textures of each wall and determining their size on the screen.

   e) Once the screen is rendered, the next step is to wait for user movements. ft_user_input() listens for player actions (movements and rotations) and calculates the new position/direction of the player. Based on this, the DDA algorithm is called again to recalculate the necessary values, and the screen pixels are updated accordingly. This process continues in a loop until the user closes the window or presses the Esc key, prompting the game to exit and printing a goodbye message.
   

   
