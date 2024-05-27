# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daparici <daparici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 01:04:09 by Ardeiro           #+#    #+#              #
#    Updated: 2024/05/27 17:33:53 by daparici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	cube

vpath 			%.h	include : mlx
vpath 			%.c	mlx : src : src/parsing : src/utils : tests
vpath 			%.o	obj

USER			=	$(shell whoami)
INCLUDE 		=	-Iinclude/
INC_LIB 		=	-Iinclude/libft
SANITIZER		=	-g3 -fsanitize=address -g
LIBFT			= 	include/libft/libft.a
LIBFTDIR		= 	include/libft
OBJ_DIR			=	obj
RM 				=	/bin/rm -rf  
CC 				= 	gcc
CFLAGS 			= 	-Wall -Werror -Wextra $(INCLUDE) $(SANITIZER)

#-------------------------- C Files -------------------------------------
PARSING			=	checks.c colors.c map.c parse.c textures.c utils.c

UTILS			=	free_mem.c

TESTS			=	printing.c

SRC 			=	$(PARSING) $(UTILS) $(TESTS) main.c

OBJS			=	$(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(@D)
	$(COMPILE.c) $< -o $@

all: $(NAME)

$(NAME): 	$(LIBFT) $(OBJS)
			@echo "$(YELLOW) ...Creating Cube3D... $(WHITE)\n"
			$(CC) $(CFLAGS) $(OBJS) $(INC_READLINE)\
			 $(READLINE_FLAGS) $(LIBFT) -o $(NAME)
			@echo "\n$(LIGHT_GRAY)---------- MiniShell Ready ------------\n"

.SILENT:
$(LIBFT):
			echo "$(LIGHT_RED) ...Creating libft files... $(WHITE)\n"
			$(MAKE) -C $(LIBFTDIR)
			@echo "$(GREEN) ...libft created... $(WHITE)\n"
	
clean:
		@echo "$(LIGHT_RED) Cleaning libft files... $(WHITE)\n"
		$(MAKE) clean -C $(LIBFTDIR) 
		/bin/rm -rf $(OBJS)

fclean: clean
		$(MAKE) fclean -C $(LIBFTDIR)
		$(RM) $(NAME) $(OBJ_DIR)
		@echo "$(GREEN) *** **** DONE **** *** $(WHITE)\n"
				

re: 	fclean all

.PHONY: all clean fclean re

# COLORS
RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
LIGHT_GRAY		= \033[0;37m
DARK_GRAY		= \033[0;90m
LIGHT_RED		= \033[0;91m
WHITE			= \033[0;97m

#SETS
BOLD			= \e[0;1m
UNDERLINED		= \e[0;4m
BLINK			= \e[0;5m