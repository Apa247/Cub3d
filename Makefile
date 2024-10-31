# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 01:04:09 by Ardeiro           #+#    #+#              #
#    Updated: 2024/07/06 10:46:40 by jolopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            =   cube

BONUS_FLAG      =   0

vpath			%.h include : mlx_linux
vpath			%.c mlx_linux : src : src/bonus : src/mlx : src/moves \
				: src/parsing : src/render : src/utils : tests
vpath	%.o obj

INCLUDE         =   -Iinclude/
INC_LIB         =   -Iinclude/libft
SANITIZER       =   -g3 -fsanitize=address -g
LIBFT           =   include/libft/libft.a
LIBFTDIR        =   include/libft
OBJ_DIR         =   obj
RM              =   /bin/rm -rf
CC              =   gcc
CFLAGS          =   -Wall -Werror -Wextra $(INCLUDE) $(SANITIZER)

#-------------------------- C Files -------------------------------------
BONUS       	=   menu_bonus.c minimap_image_bonus.c mlx_start_bonus.c \
					render_minimap_bonus.c

MLX             =   loop_function.c mlx_start.c

MOVES           =   input_handler.c player_dir.c player_move.c player_pos.c \
                    player_rotate.c

PARSING         =   checks.c colors_aux.c colors.c map.c parse.c rgb_to_hex.c \
                    textures.c utils.c utils2.c

RENDER          =   raycasting.c render.c texture.c

UTILS           =   close.c free_mem.c  menu.c struct_data.c struct_img.c \
                    struct_ray.c struct_texture.c

TESTS           =   print_info.c

SRC             =   $(MLX) $(MOVES) $(PARSING) $(RENDER) $(UTILS) \
					$(TESTS) main.c
SRC_BONUS       =   $(BONUS)

OBJS            =   $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS      =   $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(@D)
	$(COMPILE.c) -DBONUS_FLAG=$(BONUS_FLAG) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: 		$(NAME)

$(NAME):	$(LIBFT)  $(OBJS)
			@echo "\n$(YELLOW) ...Creating Cube3D ... $(WHITE)"
			$(CC) $(CFLAGS) -DBONUS_FLAG=0 $(OBJS) $(LIBFT) -Lmlx_linux \
			-lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
			@echo "\n\n$(LIGHT_GRAY)--- Cube3D Ready ---\n"

bonus:		BONUS_FLAG = 1
bonus:		clean $(LIBFT) $(OBJS) $(OBJS_BONUS)
			@echo "\n$(YELLOW) ...Creating Cube3D with bonus ... $(WHITE)"
			$(CC) $(CFLAGS) -DBONUS_FLAG=1 $(OBJS) $(OBJS_BONUS) $(LIBFT) \
			-Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
			@echo "\n\n$(LIGHT_GRAY)--- Cube3D with bonus Ready ---\n"


$(LIBFT):
			echo "$(LIGHT_RED) ...Creating libft files... $(WHITE)\n"
			$(MAKE) -C $(LIBFTDIR)
			@echo "$(GREEN) ...libft created... $(WHITE)\n"

clean:
			@echo "$(LIGHT_RED) Cleaning libft files... $(WHITE)\n"
			$(MAKE) clean -C $(LIBFTDIR)
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(MAKE) fclean -C $(LIBFTDIR)
			$(RM) $(NAME) $(OBJ_DIR)
			@echo "$(GREEN) *** **** DONE **** *** $(WHITE)\n"

re:			fclean all

.PHONY: 	all clean fclean re bonus

# COLORS
RED             = \033[0;31m
GREEN           = \033[0;32m
YELLOW          = \033[0;33m
BLUE            = \033[0;34m
MAGENTA         = \033[0;35m
CYAN            = \033[0;36m
LIGHT_GRAY      = \033[0;37m
DARK_GRAY       = \033[0;90m
LIGHT_RED       = \033[0;91m
WHITE           = \033[0;97m

#SETS
BOLD            = \e[0;1m
UNDERLINED      = \e[0;4m
BLINK           = \e[0;5m
