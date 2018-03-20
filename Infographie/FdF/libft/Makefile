#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 18:44:35 by flemaist          #+#    #+#              #
#    Updated: 2014/11/27 18:44:38 by flemaist         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

LDFLAGS		= -I includes

NAME		= libft.a

#Directories
SRC_PATH	= ./srcs/
OBJ_PATH	= ./objs/

#Display
SRCS		+= $(SRC_PATH)ft_putchar.c
SRCS		+= $(SRC_PATH)ft_putstr.c
SRCS		+= $(SRC_PATH)ft_putendl.c
SRCS		+= $(SRC_PATH)ft_putnbr.c
SRCS		+= $(SRC_PATH)ft_putchar_fd.c
SRCS		+= $(SRC_PATH)ft_putstr_fd.c
SRCS		+= $(SRC_PATH)ft_putendl_fd.c
SRCS		+= $(SRC_PATH)ft_putnbr_fd.c
SRCS		+= $(SRC_PATH)ft_putnbrendl.c
SRCS		+= $(SRC_PATH)ft_putnbr_base.c
SRCS		+= $(SRC_PATH)ft_putnbr_base_chrs.c
SRCS		+= $(SRC_PATH)ft_putnbr_l_base.c
SRCS		+= $(SRC_PATH)ft_putnbr_l_base_chrs.c
SRCS		+= $(SRC_PATH)ft_putnbr_lu_base.c
SRCS		+= $(SRC_PATH)ft_putnbr_lu_base_chrs.c
SRCS		+= $(SRC_PATH)ft_putnbr_u_base.c
SRCS		+= $(SRC_PATH)ft_putnbr_u_base_chrs.c

#Char analysis & Modif
SRCS		+= $(SRC_PATH)ft_isalnum.c
SRCS		+= $(SRC_PATH)ft_isalpha.c
SRCS		+= $(SRC_PATH)ft_isascii.c
SRCS		+= $(SRC_PATH)ft_isdigit.c
SRCS		+= $(SRC_PATH)ft_isprint.c
SRCS		+= $(SRC_PATH)ft_tolower.c
SRCS		+= $(SRC_PATH)ft_toupper.c

#Nbr analysis & Modif
SRCS		+= $(SRC_PATH)ft_nbrlen_base.c
SRCS		+= $(SRC_PATH)ft_nbrlen_base_chrs.c
SRCS		+= $(SRC_PATH)ft_nbrlen_l.c
SRCS		+= $(SRC_PATH)ft_nbrlen_l_base.c
SRCS		+= $(SRC_PATH)ft_nbrlen_l_base_chrs.c
SRCS		+= $(SRC_PATH)ft_nbrlen_lu.c
SRCS		+= $(SRC_PATH)ft_nbrlen_lu_base.c
SRCS		+= $(SRC_PATH)ft_nbrlen_lu_base_chrs.c
SRCS		+= $(SRC_PATH)ft_nbrlen_u.c
SRCS		+= $(SRC_PATH)ft_nbrlen_u_base.c
SRCS		+= $(SRC_PATH)ft_nbrlen_u_base_chrs.c

#Str analysis & Modif
SRCS		+= $(SRC_PATH)ft_nbrlen.c
SRCS		+= $(SRC_PATH)ft_strcat.c
SRCS		+= $(SRC_PATH)ft_strchr.c
SRCS		+= $(SRC_PATH)ft_strcmp.c
SRCS		+= $(SRC_PATH)ft_strcpy.c
SRCS		+= $(SRC_PATH)ft_strdup.c
SRCS		+= $(SRC_PATH)ft_strlcat.c
SRCS		+= $(SRC_PATH)ft_strlen.c
SRCS		+= $(SRC_PATH)ft_strncmp.c
SRCS		+= $(SRC_PATH)ft_strncpy.c
SRCS		+= $(SRC_PATH)ft_strncat.c
SRCS		+= $(SRC_PATH)ft_strnstr.c
SRCS		+= $(SRC_PATH)ft_strrchr.c
SRCS		+= $(SRC_PATH)ft_strstr.c
SRCS		+= $(SRC_PATH)ft_strnew.c
SRCS		+= $(SRC_PATH)ft_strdel.c
SRCS		+= $(SRC_PATH)ft_strclr.c
SRCS		+= $(SRC_PATH)ft_striter.c
SRCS		+= $(SRC_PATH)ft_striteri.c
SRCS		+= $(SRC_PATH)ft_strmap.c
SRCS		+= $(SRC_PATH)ft_strmapi.c
SRCS		+= $(SRC_PATH)ft_strequ.c
SRCS		+= $(SRC_PATH)ft_strnequ.c
SRCS		+= $(SRC_PATH)ft_strsub.c
SRCS		+= $(SRC_PATH)ft_strjoin.c
SRCS		+= $(SRC_PATH)ft_strtrim.c
SRCS		+= $(SRC_PATH)ft_strsplit.c
SRCS		+= $(SRC_PATH)ft_atoi.c
SRCS		+= $(SRC_PATH)ft_itoa.c
SRCS		+= $(SRC_PATH)ft_strrev.c

#Mem analysis & Modif
SRCS		+= $(SRC_PATH)ft_bzero.c
SRCS		+= $(SRC_PATH)ft_memset.c
SRCS		+= $(SRC_PATH)ft_memchr.c
SRCS		+= $(SRC_PATH)ft_memcmp.c
SRCS		+= $(SRC_PATH)ft_memcpy.c
SRCS		+= $(SRC_PATH)ft_memccpy.c
SRCS		+= $(SRC_PATH)ft_memmove.c
SRCS		+= $(SRC_PATH)ft_memset.c
SRCS		+= $(SRC_PATH)ft_memalloc.c
SRCS		+= $(SRC_PATH)ft_memdel.c

#List analysis & Modif
SRCS		+= $(SRC_PATH)ft_lstadd.c
SRCS		+= $(SRC_PATH)ft_lstdel.c
SRCS		+= $(SRC_PATH)ft_lstdelone.c
SRCS		+= $(SRC_PATH)ft_lstiter.c
SRCS		+= $(SRC_PATH)ft_lstprint_str.c
SRCS		+= $(SRC_PATH)ft_lstsize.c
SRCS		+= $(SRC_PATH)ft_lstelem.c
SRCS		+= $(SRC_PATH)ft_lstmap.c
SRCS		+= $(SRC_PATH)ft_lstnew.c

#Printf
SRCS		+= $(SRC_PATH)ft_printf.c
SRCS		+= $(SRC_PATH)ft_printf_b.c
SRCS		+= $(SRC_PATH)ft_printf_bu.c
SRCS		+= $(SRC_PATH)ft_printf_c.c
SRCS		+= $(SRC_PATH)ft_printf_i.c
SRCS		+= $(SRC_PATH)ft_printf_lb.c
SRCS		+= $(SRC_PATH)ft_printf_lbu.c
SRCS		+= $(SRC_PATH)ft_printf_li.c
SRCS		+= $(SRC_PATH)ft_printf_lo.c
SRCS		+= $(SRC_PATH)ft_printf_lu.c
SRCS		+= $(SRC_PATH)ft_printf_lx.c
SRCS		+= $(SRC_PATH)ft_printf_lxu.c
SRCS		+= $(SRC_PATH)ft_printf_o.c
SRCS		+= $(SRC_PATH)ft_printf_p.c
SRCS		+= $(SRC_PATH)ft_printf_pu.c
SRCS		+= $(SRC_PATH)ft_printf_s.c
SRCS		+= $(SRC_PATH)ft_printf_u.c
SRCS		+= $(SRC_PATH)ft_printf_x.c
SRCS		+= $(SRC_PATH)ft_printf_xu.c

#File analysis & Modif
SRCS		+= $(SRC_PATH)get_next_line.c

OBJS 		+= $(subst .c,.o,$(subst $(SRC_PATH),$(OBJ_PATH),$(SRCS)))

DARK_RED	=	\033[38;5;52m
DARK_GREEN	=	\033[38;5;28m
UND			=	\033[4m
MSG_BOLD	=	\033[1m
MSG_STD 	=	\033[0m
CLEAR		=	\033[2K
UP 			=	\033[A
MID			=	\033[20C

all:				$(NAME)

$(NAME):			$(OBJS)
					@ar rcs $@ $^
					@echo "$(CLEAR)$(MID)$(MSG_BOLD)$(DARK_RED)Libft Compilation: 	$(UND)$(DARK_GREEN)SUCCESSFUL!!!$(MSG_STD)"

$(OBJ_PATH)%.o: 	$(SRC_PATH)%.c
					@echo "$(CLEAR)Currently pre-processing, compiling and assembling $(UND)$(DARK_RED)$<$(MSG_STD) to $(DARK_GREEN)$@$(MSG_STD)$(UP)"
					@gcc -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
					@/bin/rm -f $(OBJS)
					@echo "$(CLEAR)$(MID)$(MSG_BOLD)$(DARK_RED)OBJS Status: 	$(UND)$(DARK_GREEN)CLEARED!!!$(MSG_STD)"

.PHONY: 			all re clean fclean

fclean:				clean
					@/bin/rm -f $(NAME)
					@echo "$(CLEAR)$(MID)$(MSG_BOLD)$(DARK_RED)NAME status: 	$(UND)$(DARK_GREEN)CLEARED!!!$(MSG_STD)"

re:					fclean
					@make
