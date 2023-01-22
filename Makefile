# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalazhar <aalazhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 17:45:50 by aalazhar          #+#    #+#              #
#    Updated: 2023/01/20 17:12:22 by aalazhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

SRC		= 	main.c \
			check_map.c \
			check_map1.c \
			check_map2.c \
			check_map3.c \
			check_map4.c \
			check_tab.c \
			check_tab1.c \
			ft_func.c \
			ft_func1.c \
			ft_func2.c \
			ft_func3.c \
			ft_split.c \
			get_next_line_utils.c \
			get_next_line.c \
			hooks.c \
			hooks1.c \
			v_intersect.c \
			h_intersect.c \
			draw3D.c \
			check_walls.c \
			check_walls1.c \
			check_forw_walls.c \
			check_rev_walls.c \
			check_lines.c \
			parse.c \
			parse2.c \
			free.c \
			free1.c \

MLX		=	-lmlx -framework OpenGL -framework AppKit

SRCDIR	=	Sources

RM		=	rm -rf

OBJDIR	=	Other

HEADER	=	cub.h

CFLAGS	=	-Wall -Wextra -Werror 

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))

###############################
WHITE		=	"\033[m"
RED			=	"\033[1;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[1;34m"
PURPLE		=	"\033[1;35m"
CYAN		=	"\033[1;36m"
EOC			=	"\033[0;0m"
LINE_CLEAR	=	"\x1b[1A\x1b[M"
###############################

all : $(NAME)

$(NAME) : $(OBJ)
	@echo $(GREEN) "Source files are compiled!\n" $(EOC)	
	@echo $(WHITE) "Building $(NAME) for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
	@$(CC) $(CFLAGS) $(OBJ)  $(MLX) -o $(NAME)
	@echo $(GREEN) "$(NAME) is created!\n" $(EOC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
	@mkdir -p Other
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo $(YELLOW) "Cleaning object files..." $(EOC)
	@$(RM) $(OBJ)
	@$(RM) $(OBJDIR)
	@echo $(RED) "Object files are cleaned!" $(EOC)

fclean: clean
	@echo $(YELLOW) "\n Removing $(NAME)..." $(EOC)
	@$(RM) $(NAME)
	@echo $(RED) "$(NAME) is removed!" $(EOC)

re: fclean all