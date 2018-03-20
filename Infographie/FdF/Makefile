#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 17:45:14 by flemaist          #+#    #+#              #
#    Updated: 2015/05/16 17:45:17 by flemaist         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# MACROS
# General options
CC				= gcc
RM				= /bin/rm

# Flags
MODE			= prod
CFLAGS			= -Wall -Werror -Wextra -pedantic
ifeq ($(MODE),dev)
CFLAGS			=
endif
LDFLAGS			+= -I $(DIR_INC)
LDFLAGS			+= -I $(DIR_LIBFT)/includes
CLIBS			+= -lm
CLIBS			+= -L $(DIR_LIBFT) -lft

# MLX according to OS (Ubuntu/MacOS)
OS				= $(shell uname)
ifeq ($(OS),Darwin)
DIR_LIBMLX		= minilibx_macos
LDFLAGS			+= -I $(DIR_LIBMLX)
CLIBS			+= -L $(DIR_LIBMLX) -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(OS),Linux)
DIR_LIBMLX		= minilibx_linux
LDFLAGS			+= -I $(DIR_LIBMLX)
CLIBS			+= -L $(DIR_LIBMLX) -lmlx
CLIBS			+= -L /usr/include/X11 -lXext -lX11 -lbsd
endif

# Directories
DIR_SRC			= src
DIR_OBJ			= obj
DIR_INC			= inc
DIR_LIBFT		= libft

# Files
NAME			= fdf
LIBFT			= $(DIR_LIBFT)/libft.a
LIBMLX			= $(DIR_LIBMLX)/libmlx.a

SRC				= $(addprefix $(DIR_SRC)/,$(SRC_F))
INC				= $(addprefix $(DIR_INC)/,$(INC_F))
OBJ				= $(subst .c,.o,$(subst $(DIR_SRC), $(DIR_OBJ),$(SRC)))

SRC_F			+= main.c
SRC_F			+= map.c
SRC_F			+= draw_1.c
SRC_F			+= draw_2.c
SRC_F			+= draw_3.c
SRC_F			+= sg_1.c
SRC_F			+= sg_2.c
SRC_F			+= parser.c
SRC_F			+= parse_line_of_map.c
SRC_F			+= calc.c
SRC_F			+= points_1.c
SRC_F			+= points_2.c
SRC_F			+= points_3.c
SRC_F			+= key_dispatcher.c
SRC_F			+= key_callbacks.c

SRC_F			+= errors.c
SRC_F			+= div.c

INC_F			+= project.h
INC_F			+= structs.h
INC_F			+= key_mapping_linux.h
INC_F			+= key_mapping_macos.h

# Messages & Colors
CLR_GREEN		= \033[0;32m
CLR_ORANGE		= \033[38;5;208m
CLR_BLUE		= \033[1;34m
CLR_RED			= \033[0;31m
CLR_PINK		= \033[0;35m
CLR_DEFAULT		= \033[0m

MSG_BUILD		= printf "$(CLR_GREEN)[build]"
MSG_BUILDING	= printf "$(CLR_ORANGE)[building]"
MSG_REMOVE		= printf "$(CLR_RED)[remove]"
MSG_DEF			= printf "$(CLR_DEFAULT)"
MSG_MODE		= printf "$(CLR_BLUE)[prod_mode]"
ifeq ($(MODE),dev)
MSG_MODE		= printf "$(CLR_PINK)[dev_mode]"
endif

LINE_ERASE		= printf "\r" && printf "\033[K"

# RULES
# Classic
all: $(NAME)

$(NAME): $(DIR_OBJ) $(OBJ)
	@$(CC) -o $@ $(OBJ) $(CFLAGS) $(CLIBS)
	@$(MSG_MODE) && $(MSG_BUILD) && echo " Project ok!" && $(MSG_DEF)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(INC) $(LIBFT) $(LIBMLX)
	@$(MSG_MODE) && $(MSG_BUILDING) && printf " " && printf $< && $(MSG_DEF)
	@$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)
	@$(LINE_ERASE)

clean:
	@$(RM) -f $(OBJ)
	@$(MSG_REMOVE) && echo " Project .o down." && $(MSG_DEF)

fclean: clean
	@$(RM) -f $(NAME)
	@$(MSG_REMOVE) && echo " Project binary down." && $(MSG_DEF)

gclean: fclean
	make -C $(DIR_LIBFT) fclean

re: fclean all

$(LIBFT):
	make -C $(DIR_LIBFT) MODE=prod
	make -C $(DIR_LIBFT) clean

$(LIBMLX):
	make -C $(DIR_LIBMLX)

$(DIR_OBJ):
	mkdir $(DIR_OBJ)

# Supp
dev:
	@make re MODE=dev

prod:
	@make re MODE=prod

ca: gclean

.PHONY: all clean fclean gclean re dev prod ca
