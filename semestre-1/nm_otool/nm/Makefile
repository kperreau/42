# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 14:10:51 by kperreau          #+#    #+#              #
#    Updated: 2015/09/22 22:47:11 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_nm

# Dir vars

SRCDIR = src

INCLUDESDIR = includes

LIBDIR = libft

# Files vars

MAIN = main.c

CFILES = ft_nm.c ft_sort.c ft_tools.c ft_display.c ft_lib.c ft_fat.c \
		ft_display_32.c ft_sort_32.c ft_error.c

SRC = $(patsubst %, $(SRCDIR)/%, $(CFILES))

OBJ = $(SRC:.c=.o)

HFILES = ft_nm_otool.h

HEADERS = $(patsubst %, $(INCLUDESDIR)/%, $(HFILES))

# COMPILATION

ERRORFLAGS = -Wall -Werror -Wextra -W -O2 -march=native

INCLUDEFLAGS = -I $(INCLUDESDIR)/ -I $(LIBDIR)/includes/ -I $(LIBDIR)/printf/includes/

LIBFLAGS = -L $(LIBDIR)/ -lft

FLAGS = $(ERRORFLAGS) $(INCLUDEFLAGS)

CC = gcc

# Git vars

TOGIT =	$(SRC) \
		$(HEADERS) \
		$(MAIN) \
		Makefile \
		auteur \
		$(LIBDIR) \

# Rules

all: $(NAME)

$(NAME): $(OBJ)
			@make -j -C $(LIBDIR)/
			@$(CC) $(FLAGS) $(OBJ) $(MAIN) $(LIBFLAGS) -o $(NAME)

re: fclean all

clean:
			@rm -f $(OBJ)
			@make -C $(LIBDIR)/ clean

fclean: clean
			@rm -f $(NAME)
			@make -j -C $(LIBDIR)/ fclean

relib:
		@make -j -C $(LIBDIR)/ re

%.o: %.c
			@$(CC) -o $@ -c $< $(FLAGS)

git:
		git add $(TOGIT)
		git commit -m 'auto update'
		git push
