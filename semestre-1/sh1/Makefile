# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 14:10:51 by kperreau          #+#    #+#              #
#    Updated: 2015/02/12 18:22:33 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1

# Dir vars

SRCDIR = src

INCLUDESDIR = includes

LIBDIR = libft

# Files vars

MAIN = main.c

CFILES = ft_shell.c ft_splitword.c ft_findpath.c ft_errors.c ft_env.c \
		ft_basic_cmd.c ft_basic_cmd2.c ft_utils.c

SRC = $(patsubst %, $(SRCDIR)/%, $(CFILES))

OBJ = $(SRC:.c=.o)

HFILES = shell.h

HEADERS = $(patsubst %, $(INCLUDESDIR)/%, $(HFILES))

# COMPILATION

ERRORFLAGS = -Wall -Werror -Wextra -W -O3
# ERRORFLAGS =

INCLUDEFLAGS = -I $(INCLUDESDIR)/ -I $(LIBDIR)/includes/

LIBFLAGS = -L $(LIBDIR)/ -lft

FLAGS = $(ERRORFLAGS) $(INCLUDEFLAGS)

CC = gcc

# Git vars

TOGIT =	$(SRC) \
		$(HEADERS) \
		$(MAIN) \
		Makefile \
		auteur \
		$(LIBDIR)

# Rules

all: $(NAME)

$(NAME): $(OBJ)
			@make -C $(LIBDIR)/
			@$(CC) $(FLAGS) $(MAIN) $(OBJ) $(LIBFLAGS) -o $(NAME)

re: fclean all

clean:
			@rm -f $(OBJ)
			@make -C $(LIBDIR)/ clean

fclean: clean
			@rm -f $(NAME)
			@make -C $(LIBDIR)/ fclean

relib:
		@make -C $(LIBDIR)/ re

%.o: %.c
			@$(CC) -o $@ -c $< $(FLAGS)

git:
		git add $(TOGIT)
		git commit -m 'auto update'
		git push
