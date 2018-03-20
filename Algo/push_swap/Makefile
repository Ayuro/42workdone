#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/08 12:31:40 by flemaist          #+#    #+#              #
#    Updated: 2014/01/09 20:00:56 by flemaist         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

DIR_LIBFT	=	./libft
LDFLAGS		=	-I $(DIR_LIBFT)/includes
CLIBFLAGS	+=	-L libft -lft

HDR 		=	header/
NAME		=	push_swap
SRCS		+=	./srcs/main.c
SRCS		+=	./srcs/pushswap.c
SRCS		+=	./srcs/create_list.c
SRCS		+=	./srcs/modif_list.c

OBJ			=	$(subst .c,.o,$(SRCS))

all:		$(NAME)

$(NAME):	$(OBJ) $(DIR_LIBFT)/libft.a
			@echo "\033[33;50mMake in progress:\033[0m"
			@$(CC) -o $@ $(OBJ) $(CFLAGS) $(CLIBFLAGS) $(LDFLAGS)
			@echo "global:" "\t\033[33;32mDone\033[0m"

%.o:		%.c
			@$(CC) -o $@ -c $< $(CFLAGS) $(CLIBFLAGS) $(LDFLAGS) -I $(HDR)
			@echo .o: "\t\t\033[33;32mDone\033[0m"

$(DIR_LIBFT)/libft.a:
			@echo "\033[33;50mLibft compilation processing:\033[0m"
			@make -f Makefile -C $(DIR_LIBFT)
			@echo "libft:" "\t\t\033[33;32mDone\033[0m"

.PHONY: 	all re clean fclean

clean:
			@echo "\033[33;50mCleaning in progress:\033[0m"
			@rm -f $(OBJ)
			@make -f Makefile -C $(DIR_LIBFT) clean
			@echo "clean:" "\t\t\033[33;32mDone\033[0m"

fclean: 	clean
			@echo "\033[33;50mFull cleaning in progress:\033[0m"
			@rm -f $(NAME)
			@make -f Makefile -C $(DIR_LIBFT) fclean
			@echo "fclean:" "\t\033[33;32mDone\033[0m"

re:
			@echo "\033[33;50mMake re in progress:\033[0m"
			@make fclean
			@make all
