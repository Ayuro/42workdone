# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flemaist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/25 17:35:04 by flemaist          #+#    #+#              #
#    Updated: 2017/07/25 17:35:14 by flemaist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC				= gcc

FLAGS			= -Wall -Wextra -Werror

NAME 			= bsq

OBJS 			+= $(subst .c,.o,$(subst $(SRC_PATH), ./,$(SRCS)))

#Directories
SRC_PATH		= ./srcs/
OBJ_PATH		= ./objs/

#Sources, fill it.
SRCS		+=	$(SRC_PATH)main.c
SRCS		+=	$(SRC_PATH)parser.c
SRCS		+=	$(SRC_PATH)parser_check.c
SRCS		+=	$(SRC_PATH)parser_metadata.c
SRCS		+=	$(SRC_PATH)travel.c
SRCS		+=	$(SRC_PATH)basics.c
SRCS		+=	$(SRC_PATH)basics2.c
SRCS		+=	$(SRC_PATH)display.c
SRCS		+=	$(SRC_PATH)ft_error.c

#MSG flags
DARK_RED		=	\033[38;5;52m
DARK_GREEN		=	\033[38;5;28m
UND				=	\033[4m
MSG_BOLD		=	\033[1m
MSG_STD 		=	\033[0m
CLEAR			=	\033[2K
UP 				=	\033[A
MID				=	\033[20C

all: 			$(NAME)

$(NAME):		$(OBJS)
				@echo "$(CLEAR)$(MID)$(MSG_BOLD)$(DARK_RED)ft_ls Compilation: 	$(UND)$(DARK_GREEN)SUCCESSFUL!!!$(MSG_STD)"
				@$(CC) $(FLAGS) -c $(SRCS)
				@$(CC) -o $(NAME) $(OBJS)

%.o:	$(SRC_PATH)%.c
				@echo "$(CLEAR)Currently pre-processing, compiling and assembling $(UND)$(DARK_RED)$<$(MSG_STD) to $(DARK_GREEN)$@$(MSG_STD)$(UP)"
				@$(CC) -o $@ -c $<

.PHONY: 		all re clean fclean

clean:
				@/bin/rm -f $(OBJS)
				@echo "$(CLEAR)$(MID)$(MSG_BOLD)$(DARK_RED)OBJS ft_ls Status: 	$(UND)$(DARK_GREEN)CLEARED!!!$(MSG_STD)"
				@rm -f ft_ls.o

fclean:			clean
				@/bin/rm -f $(NAME)
				@echo "$(CLEAR)$(MID)$(MSG_BOLD)$(DARK_RED)NAME ft_ls status: 	$(UND)$(DARK_GREEN)CLEARED!!!$(MSG_STD)"
				@rm -f $(NAME)

re: 			fclean
				@make
