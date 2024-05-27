# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 17:03:15 by jolopez-          #+#    #+#              #
#    Updated: 2024/05/09 02:38:16 by Ardeiro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath 			%.o	obj

SRCS			= ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c \
				  ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c \
				  ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c \
				  ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c \
				  ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c \
				  ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c \
				  ft_putstr_fd.c ft_strjoin.c ft_strtrim.c ft_strlcpy.c \
				  ft_isalpha.c ft_strrchr.c ft_memset.c ft_striteri.c \
				  ft_strmapi.c get_next_line.c get_next_line_utils.c \
				  ft_split.c ft_strstr.c ft_lstadd_front_bonus.c \
				  ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
				  ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
				  ft_lstsize_bonus.c ft_is_space.c ft_lstadd_back_bonus.c \
				  ft_strarraylen.c ft_clear_strarray.c ft_strchr_pos.c \
				  ft_lstclear_nodes.c ft_lstinsert.c ft_lstcopy.c \
				  ft_chrcount.c ft_strequal.c ft_strstrip.c ft_cutstr.c \
				  ft_startswith.c ft_concat_strarray.c ft_countalpha.c \
				  ft_endswith.c ft_strclean_withspaces.c ft_strarr_add.c \
				  ft_strcontains.c 


OBJ_DIR			= obj

OBJS			= $(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(@D)
	$(COMPILE.c) $< -o $@

CC				= gcc

RM				= rm -rf

CFLAGS			= -Wall -Wextra -Werror -I -g

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
