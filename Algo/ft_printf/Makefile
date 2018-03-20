#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/10/26 20:39:15 by flemaist          #+#    #+#              #
#    Updated: 2014/10/26 20:39:18 by flemaist         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=	libftprintf.a
CC=		gcc
INC=	-I.
CFLAGS=	-Wall -Wextra -Werror $(INC)
RM=		/bin/rm -f
OBJ=	mainf.o parser.o tools.o function.o function2.o function3.o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar -rc $@ $^
	ranlib $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
