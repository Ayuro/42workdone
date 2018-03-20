#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/29 16:50:43 by flemaist          #+#    #+#              #
#*   Updated: 2016/05/20 16:07:58 by jhezard          ###   ########.fr       *#
#                                                                              #
#******************************************************************************#

CC			= gcc

FLAGS		= -Wall -Wextra -Werror

NAME 		= ft_ls

#Directories
SRC_PATH	= ./src/
OBJ_PATH	= ./objs/

#Sources
SRCS		+= $(SRC_PATH)ft_ls.c
SRCS		+= $(SRC_PATH)args_tools.c
SRCS		+= $(SRC_PATH)args_tools2.c
SRCS		+= $(SRC_PATH)flags.c
SRCS		+= $(SRC_PATH)parsing.c
SRCS		+= $(SRC_PATH)print.c
SRCS		+= $(SRC_PATH)create_list.c
SRCS		+= $(SRC_PATH)fdatanew.c
SRCS		+= $(SRC_PATH)fget_data.c
SRCS		+= $(SRC_PATH)list_tools.c
SRCS		+= $(SRC_PATH)print_tools.c
SRCS		+= $(SRC_PATH)print_tools2.c

OBJS 		+= $(subst .c,.o,$(subst $(SRC_PATH),$(OBJ_PATH),$(SRCS)))

LIBFT_DIR	= libft

DARK_RED	=	\033[38;5;52m
DARK_GREEN	=	\033[38;5;28m
UND			=	\033[4m
MSG_BOLD	=	\033[1m
MSG_STD 	=	\033[0m
CLEAR		=	\033[2K
UP 			=	\033[A
MID			=	\033[20C

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C libft
			@echo "$(MID)$(MSG_BOLD)$(DARK_RED)Prog Compilation: 	$(UND)$(DARK_GREEN)SUCCESSFUL!!!$(MSG_STD)"
			@$(CC) -o $(NAME) $(OBJS) libft/libft.a

$(OBJ_PATH)%.o: 	$(SRC_PATH)%.c
					@mkdir -p -m 777 ./objs
					@gcc -o $@ -c $< $(CFLAGS)

.PHONY: all re clean fclean

clean: 
		@make clean -C libft
		@/bin/rm -rf $(OBJ_PATH)
		@echo "$(CLEAR)$(MID)$(MSG_BOLD)$(DARK_RED)Prog Objs Deleted: 	$(UND)$(DARK_GREEN)YES!!!$(MSG_STD)"

fclean: clean
		@make fclean -C libft
		@/bin/rm -f $(NAME)
		@echo "$(CLEAR)$(MID)$(MSG_BOLD)$(DARK_RED)Prog Deleted: 	$(UND)$(DARK_GREEN)YES!!!$(MSG_STD)"

re: 	fclean all
