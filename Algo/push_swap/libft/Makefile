#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 17:42:15 by flemaist          #+#    #+#              #
#    Updated: 2013/12/22 18:16:19 by flemaist         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

LDFLAGS	= -I includes

NAME	= libft.a

SRCS	+= ft_atoi.c
SRCS	+= ft_bzero.c
SRCS	+= ft_isalnum.c
SRCS	+= ft_isalpha.c
SRCS	+= ft_isascii.c
SRCS	+= ft_isdigit.c
SRCS	+= ft_isprint.c
SRCS	+= ft_memset.c
SRCS	+= ft_memchr.c
SRCS	+= ft_memcmp.c
SRCS	+= ft_memcpy.c
SRCS	+= ft_memccpy.c
SRCS	+= ft_memmove.c
SRCS	+= ft_memset.c
SRCS	+= ft_strcat.c
SRCS	+= ft_strchr.c
SRCS	+= ft_strcmp.c
SRCS	+= ft_strcpy.c
SRCS	+= ft_strdup.c
SRCS	+= ft_strlcat.c
SRCS	+= ft_strlen.c
SRCS	+= ft_strncmp.c
SRCS	+= ft_strncpy.c
SRCS	+= ft_strncat.c
SRCS	+= ft_strnstr.c
SRCS	+= ft_strrchr.c
SRCS	+= ft_strstr.c
SRCS	+= ft_tolower.c
SRCS	+= ft_toupper.c
SRCS	+= ft_memalloc.c
SRCS	+= ft_memdel.c
SRCS	+= ft_strnew.c
SRCS	+= ft_strdel.c
SRCS	+= ft_strclr.c
SRCS	+= ft_striter.c
SRCS	+= ft_striteri.c
SRCS	+= ft_strmap.c
SRCS	+= ft_strmapi.c
SRCS	+= ft_strequ.c
SRCS	+= ft_strnequ.c
SRCS	+= ft_strsub.c
SRCS	+= ft_strjoin.c
SRCS	+= ft_strtrim.c
SRCS	+= ft_strsplit.c
#SRCS	+= ft_itoa.c
SRCS	+= ft_putchar.c
SRCS	+= ft_putstr.c
SRCS	+= ft_putendl.c
SRCS	+= ft_putnbr.c
SRCS	+= ft_putchar_fd.c
SRCS	+= ft_putstr_fd.c
SRCS	+= ft_putendl_fd.c
SRCS	+= ft_putnbr_fd.c
SRCS	+= get_next_line.c

OBJ		= $(subst .c,.o,$(SRCS))

all:		$(NAME)

$(NAME):	$(OBJ)
			@ar rcs $@ $^

%.o: 		%.c
			@gcc -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
			@/bin/rm -f $(OBJ)

.PHONY: 	all re clean fclean

fclean:		clean
			@/bin/rm -f $(NAME)

re:			fclean
			make
